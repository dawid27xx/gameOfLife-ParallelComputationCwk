# Conway's Game of Life - Parallelization Coursework

This project is an assignment focused on parallelizing Conway's Game of Life using OpenMP directives. The Game of Life is a classic cellular automaton where a two-dimensional grid evolves over time based on simple rules governing the state of each cell.

## Overview

The simulation involves a grid where each cell is either occupied (alive) or empty (dead). At every time step, each cell is updated based on the number of occupied neighboring cells. Two rule sets are implemented:

- **Original Rules (Moore Neighborhood):**
  - A live cell dies (becomes empty) if it has fewer than 2 or more than 3 live neighbors.
  - An empty cell becomes live if it has exactly 3 live neighbors.
  
- **Modified Rules (von Neumann Neighborhood with Red-Black Ordering):**
  - Neighbors are counted only from the four adjacent cells (up, down, left, right).
  - A live cell dies if it has 0 or 3 live neighbors.
  - An empty cell becomes live if it has exactly 2 live neighbors.

## Assessment Tasks

The assignment consists of four main tasks:
1. **Counting Cells:**  
   Parallelize the `numCells` function to correctly count the number of live cells in the grid.
2. **Grid Initialization:**  
   Parallelize the `initialiseGrid` function to add M distinct living cells at random positions (ensuring no duplicates).
3. **Iteration with Original Rules:**  
   Parallelize the `iterateWithOriginalRules` function to update the grid according to the classic Game of Life rules.
4. **Iteration with Modified Rules:**  
   Implement and parallelize the `iterateWithModifiedRules` function using a red-black pattern with the modified rules.

## Requirements

- **Operating System:** Unix-based systems (the coursework is designed for school Unix machines such as feng-linux.leeds.ac.uk).
- **Compiler:** A C compiler with OpenMP support (e.g., `gcc-14`).
- **Build Tool:** GNU Make.

## How to Build and Run

### Building the Code

To compile the code, open a terminal in the project directory and run:

```bash
make CC=gcc-14
```
### Running the Executable
Once compiled, run the executable with the following syntax:

```bash
./cwk1 N M I R
```
Where:

- N is the grid size (resulting in an N×N grid).
- M is the initial number of living cells.
- I is the number of iterations to perform.
- R selects the rule set: 0 for the original rules and 1 for the modified rules.
