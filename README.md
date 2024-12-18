# 🌱 Conway's Game of Life - Raylib Implementation

![Grafik](https://github.com/user-attachments/assets/af64f79d-b0ac-4163-810a-1212a9257d55)

A simple yet interactive implementation of Conway's Game of Life using the Raylib library.

## 🧩 Overview

**Conway's Game of Life** is a cellular automaton that simulates the evolution of life on a two-dimensional grid. Each cell on the grid can be either "alive" or "dead," and its state evolves based on four simple rules:

- **Survival**: A living cell with 2 or 3 living neighbors remains alive.
- **Death by Isolation**: A living cell with fewer than 2 living neighbors dies.
- **Death by Overpopulation**: A living cell with more than 3 living neighbors dies.
- **Reproduction**: A dead cell with exactly 3 living neighbors becomes alive.

This simulation showcases how complex patterns can emerge from simple rules, creating a dynamic, evolving world.

## ✨ Features

- **Interactive Grid**: Easily toggle cells between alive and dead using the mouse.
- **Real-time Simulation**: Watch the game evolve in real-time with each generation.
- **Randomization**: Generate random living cells to start with a unique pattern.
- **Lightweight & Fast**: Optimized for smooth performance using the Raylib library.

## 🛠 Requirements

- Raylib 5 or later  
- CMake  

## 📦 Installation

1. Clone the repository:
    ```bash
    git clone https://github.com/acc0re/rlgol/.git
    cd rlgol
    ```

2. Make sure you have Raylib installed and properly configured on your system.

3. Compile using CMake:
    ```bash
    cmake .
    make
    ```

## 🎮 Usage

- **Toggle Cells**: Click on the grid to toggle cells between alive and dead.
- **Random Generation**: Generate random living cells by pressing the corresponding button.
- **Start/Pause Simulation**: Start or pause the simulation with the **SPACE** key.

## 📖 About Conway's Game of Life

Conway's Game of Life was created by mathematician John Conway in 1970. It is a "zero-player game," meaning the game evolves based on its initial configuration with no further input needed. The game demonstrates how complex and diverse patterns can emerge from a set of simple rules, making it a fascinating example of cellular automata.
