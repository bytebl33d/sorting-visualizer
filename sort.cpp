#include <SDL2/SDL.h>
#include <iostream>
#include <random>
#include <algorithm>

unsigned int size = 150;

void visualizeSort(std::vector<int>& v, SDL_Renderer* renderer, unsigned int red, unsigned int blue){
    // clear screen and draw sorting state
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    unsigned int index = 0;
    for (int i : v)
    {
        if (index == red)
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        else if (index == blue)
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        else 
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        
        SDL_RenderDrawLine(renderer, index, 99, index, i);
        index += 1;
    }

    // show to window and delay set amount of milliseconds
    SDL_RenderPresent(renderer);
    SDL_Delay(2);
}

// selection sort algorithm (find minimum in unsorted array)
void selectionSort(std::vector<int>& v, SDL_Renderer* renderer){
    for(unsigned int i = 0; i < v.size(); i++)
    {
        for(unsigned int j = i; j < v.size(); j++)
        {
            if(v[j] < v[i]) std::swap(v[j], v[i]);

            visualizeSort(v, renderer, i, j);
        }
    }
}

// bubble sort algorithm
void bubbleSort(std::vector<int>& v, SDL_Renderer* renderer)
{
    for (unsigned int i = 0; i < v.size() - 1; i++){
        for (unsigned int j = 0; j < v.size() - i - 1; j++){
            if (v[j] < v[j + 1]) std::swap(v[j], v[j + 1]);

            visualizeSort(v, renderer, j, j);
        }
    }      
}

int main()
{
    std::random_device rd;
    std::uniform_int_distribution<> d(1,99);
    std::vector<int> v;

    // populate vector with numbers
    for(int i= 0; i < size; i++)
    {
        v.push_back(d(rd));
    }

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_CreateWindowAndRenderer(size*10, 100*10, 0, &window, &renderer);
    SDL_RenderSetScale(renderer, 10, 10);

    //selectionSort(v, renderer);
    bubbleSort(v, renderer);
}