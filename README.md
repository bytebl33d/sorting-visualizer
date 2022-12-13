# Sorting Visualizer using SDL2
![visualizer1](https://user-images.githubusercontent.com/61542339/207411555-92d1f5aa-5faa-40ff-b4a9-01bc8b840bf5.png)

Visualization of different sorting algorithms in C++ with SDL2 Library. You can also run Sorting Visualizer using the C++ source code available in the repository.

## Installing SDL2
```
sudo apt-get install libsdl2-dev libsdl2-ttf-dev
```

## Compiling
```
g++ source/* -o sort.out -lSDL2 -lSDL2_ttf -Iheaders
```
## Running the program
Available controls:
- 0: generate a different randomized array.
- 1: start/pause Bubble Sort Algorithm.
- 2: start/pause Selection Sort Algorithm.
- 3: start/pause Insertion Sort Algorithm.
- m: open/close the menu
- q: exit out of Sorting Visualizer
