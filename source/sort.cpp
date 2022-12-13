#include <sort.h>

Sort::Sort(Window& window, std::vector<int>& vector) : 
    _window(window), _vector(vector)
{

}


// Bubble Sort: compares two adjacent elements and swaps them until they are in the intended order for every iteration.
// Time Complexity: O(n^2)
// Space Complexity: O(1)
int Sort::bubbleSort(int currentIteration)
{
    // jumping to current step
    int ci = currentIteration / _vector.size();
    int cj = currentIteration % (_vector.size() - 1);

    for (unsigned int i = ci; i < _vector.size() - 1; i++){
        
        // check if swapping occurs
        int swapped = 0;

        for (unsigned int j = cj; j < _vector.size() - i - 1; j++){
            if (_vector[j] > _vector[j + 1]){
                std::swap(_vector[j], _vector[j + 1]);
                swapped = 1;

                if (visualizing) 
                    _window.visualizeSort(_vector, j+1, j+1, 0);
            }

            if (visualizing) 
                return i*(_vector.size())+j+1;
        }

        // array is already sorted
        if (swapped == 0) break;
    }   
    return -1;
}


// Selection Sort: select the smallest element from an unsorted list in each iteration and place that element at the beginning of the unsorted list
// Time Complexity: O(n^2)
// Space Complexity: O(1)
int Sort::selectionSort(int currentIteration){
    // jumping to current step
    int ci = currentIteration / _vector.size();

    for(unsigned int i = ci; i < _vector.size(); i++)
    {
        for(unsigned int j = i; j < _vector.size(); j++)
        {
            if(_vector[j] < _vector[i]) {
                std::swap(_vector[j], _vector[i]);

                if (visualizing) {
                    _window.visualizeSort(_vector, i, j, 0);
                    return i*(_vector.size())+j+1;
                }
            }
        }
    }
    return -1;
}

// Insertion Sort: place an unsorted element at its suitable place in each iteration.
// Time Complexity: O(n^2)
// Space Complexity: O(1)
int Sort::insertionSort(int currentIteration){
    int ci = (currentIteration / _vector.size()) + 1;

    for(unsigned int i = ci; i < _vector.size(); i++)
    {
        int key = _vector[i];
        int j = i - 1;

        // Compare key with each element on the left of it until an element smaller than it is found.
        while (key < _vector[j] && j >= 0) {
            _vector[j + 1] = _vector[j];
            --j;

            if (visualizing) {
                _window.visualizeSort(_vector, j, i+1, key);
            }
        }
        _vector[j + 1] = key;  

        if (visualizing) return i*(_vector.size())+j+1;
    }
    return -1;
}