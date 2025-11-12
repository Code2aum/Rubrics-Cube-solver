# Rubik's Cube Solver

This project implements a Rubik's Cube solver using various search algorithms including DFS, BFS, IDDFS (Iterative Deepening Depth-First Search), and IDA* (Iterative Deepening A*). The cube state is represented using three different implementations for performance comparison: 3D array, 1D array, and bitboard representation.

## Features

- Multiple Rubik's Cube representations:
  - 3D Array representation
  - 1D Array representation
  - Bitboard representation
- Various solving algorithms:
  - Depth-First Search (DFS)
  - Breadth-First Search (BFS)
  - Iterative Deepening DFS (IDDFS)
  - Iterative Deepening A* (IDA*)
- Pattern database for heuristic-based solving
- Support for all standard Rubik's Cube moves (F, F', F2, B, B', B2, etc.)

## Prerequisites

- CMake (version 3.0 or higher)
- C++ compiler with C++11 support
- Make

## Building the Project

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/rubiks-cube-solver.git
   cd rubiks-cube-solver
   ```

2. Create a build directory and navigate to it:
   ```bash
   mkdir build
   cd build
   ```

3. Generate the build files using CMake:
   ```bash
   cmake ..
   ```

4. Build the project:
   ```bash
   make
   ```

5. Create the database directory:
   ```bash
   mkdir -p ../Databases
   ```

## Running the Program

After building, you can run the solver from the build directory:

```bash
./rubiks_cube_solver
```

The program will:
1. Create a new Rubik's cube
2. Apply random moves to shuffle it
3. Solve the cube using the IDA* algorithm
4. Display both the scrambled and solved states

## Example Output

```
Rubik's Cube:

       W Y R 
       W W R 
       R R R 

G G G  Y G Y  O B B  W R O 
G G O  W R W  R B B  W O O 
O O W  R G G  Y B B  W B B 

       G Y O 
       Y Y B 
       Y Y O 

Scramble: D R2 L' U' R2 L2 R R L' F F2 F R' 
Solution: R L' U L R2 D'
```

## Project Structure

- `Model/`: Contains different Rubik's Cube representations
  - `RubiksCube.h`: Base class for all representations
  - `RubiksCube3dArray.h`: 3D array implementation
  - `RubiksCube1dArray.h`: 1D array implementation
  - `RubiksCubeBitboard.h`: Bitboard implementation
- `Solver/`: Contains different solving algorithms
  - `DFSSolver.h`: Depth-First Search solver
  - `BFSSolver.h`: Breadth-First Search solver
  - `IDDFSSolver.h`: Iterative Deepening DFS solver
  - `IDAstarSolver.h`: IDA* solver
- `PatternDatabases/`: Pattern database implementation for heuristic-based solving

## Contributing

Feel free to open issues or submit pull requests if you have any improvements or bug fixes.

## License

This project is licensed under the MIT License - see the LICENSE file for details.