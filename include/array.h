#ifndef _STDLIB_H
#include <stdlib.h>
#endif

typedef struct Range{
    int y;
    int x;
    int height;
    int width;
} Range;

int **createArray(int h, int w);

void destroyArray(int **arr);

void fillArray(int **arr, int h, int w, int val);

int sumArray(int **arr, int h, int w, Range range);

void copyArray(int **dst, int **src, int h, int w);