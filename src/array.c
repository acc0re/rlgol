#include "array.h"

// Create a 2D array with given height and width
int **createArray(int h, int w) {
    int *values = calloc(h * w, sizeof(int)); // Allocate memory for the array values
    int **rows = malloc(h * sizeof(int *));   // Allocate memory for the row pointers
    for (int i = 0; i < h; ++i) {
        rows[i] = values + i * w; // Set each row pointer to the correct position in the values array
    }
    return rows;
}

// Destroy a 2D array
void destroyArray(int **arr) {
    free(*arr); // Free the memory allocated for the array values
    free(arr);  // Free the memory allocated for the row pointers
}

// Fill a 2D array with a given value
void fillArray(int **arr, int h, int w, int val) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            arr[i][j] = val; // Set each element in the array to the given value
        }
    }
}

// Sum the values in a specified range of a 2D array
int sumArray(int **arr, int h, int w, Range range) {
    int sum = 0;
    for (int i = range.y; i < range.y + range.height; i++) {
        if (i < 0 || i >= h) {
            continue; // Skip rows that are out of bounds
        }
        for (int j = range.x; j < range.x + range.width; j++) {
            if (j < 0 || j >= w) {
                continue; // Skip columns that are out of bounds
            }
            sum += arr[i][j]; // Add the value of the current element to the sum
        }
    }
    return sum;
}

// Copy the contents of one 2D array to another
void copyArray(int **dst, int **src, int h, int w) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            dst[i][j] = src[i][j]; // Copy each element from the source array to the destination array
        }
    }
}