*This project has been created as part of the 42 curriculum by rababaya, dgrigor2

# cub3D

## Description
cub3D is a minimal 3D raycasting project inspired by classic Wolfenstein-style engines. The program parses a `.cub` map file describing textures, floor/ceiling colors and a map layout, validates the input, loads textures via MiniLibX and renders a first-person 3D view using simple raycasting.

The goal is to implement a working raycasting renderer, correct map parsing and validation, and a small interactive viewer with keyboard controls.

## Instructions
Requirements
- Unix-like system (Linux recommended)
- A working C toolchain (gcc/clang)
- X11 development libraries (for MiniLibX on Linux)
- The provided `minilibx-linux` and bundled `libft` in the repository

Build
```bash
cd /home/rababaya/42/cub3D
make all
```

Run
```bash
./cub3D map.cub
```
Replace `map.cub` with your map file. The program opens an interactive window; use the keyboard to move/rotate.

Clean
```bash
make fclean
```

Diagnostics
- To check for memory issues, run under Valgrind:
```bash
valgrind --leak-check=full ./cub3D map.cub
```

## Resources
- Lode Vandevenne's raycasting tutorial: https://lodev.org/cgtutor/raycasting.html
- MiniLibX (minilibx-linux) documentation and examples (bundled in this repo)
- X11 and Xlib documentation for event handling
- 42 project references: `get_next_line`, `libft` utilities used for parsing

AI usage disclosure
- AI assisted refactor and maintenance tasks only. Specifically, AI was used to:
  - Add malloc/calloc/ft_strdup null checks and safer early-exit cleanup.
  - Implement a `free`/cleanup routine to release reachable resources.
  - Refactor large functions by extracting smaller helpers and moving code into new source files to meet style/line-length goals.
  - Add safe image destruction on failures and improve error-handling paths.
