# Sorting Visualizer using SDL2

## Installing SDL2
```
sudo apt-get install libsdl2-dev
```

## Compiling
```
g++ source/* -o sort.out -lSDL2 -lSDL2_ttf -Iheaders
```

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