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

## Valgrind
Valgrind reports memory leaks in the openGL library and can be suppressed using a suppresion file. More information about Valgrind Suppression can be found on the wiki: https://wiki.wxwidgets.org/Valgrind_Suppression_File_Howto
```
sudo apt install gawk

# log all errors to file
valgrind --leak-check=full --show-reachable=yes --error-limit=no --gen-suppressions=all --log-file=supdata.log ./sort.out

# create suppression file
cat ./supdata.log | ./parse_valgrind_suppressions.sh > sort.supp

# Running valgrind with suppression file
valgrind --leak-check=full --show-reachable=yes --suppressions=sort.supp ./sort.out
```
