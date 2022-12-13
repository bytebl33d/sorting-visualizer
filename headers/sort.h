#pragma once
#include <string>
#include <iostream>
#include <random>
#include <algorithm>
#include <tuple>

#include <window.h>

class Sort {
public:
    Sort(Window &window, std::vector<int>& vector);

    int bubbleSort(int iteration);
    int selectionSort(int iteration);
    int insertionSort(int iteration);

    bool visualizing = true;

private:
    std::vector<int>& _vector;
    Window& _window;
};