#include <iostream>
#include <random>
#include <algorithm>

#include <sort.h>
#include <text.h>

unsigned int size = 150;

std::vector<int> randomizeVector(){
    std::random_device rd;
    std::uniform_int_distribution<> d(1,99);
    std::vector<int> v;

    // populate vector with numbers
    for(int i= 0; i < size; i++)
    {
        v.push_back(d(rd));
    }
    return v;
}

int main(int argc, char **argv) {

    std::cout
        <<"Available Controls inside Sorting Visualizer:-\n"
        <<"    Use 0 to resort the array.\n"
        <<"    Use 1 to start Bubble Sort Algorithm.\n"
        <<"    Use 2 to start Selection Sort Algorithm.\n"
        <<"    Use 3 to start Insertion Sort Algorithm.\n"
        <<"    Use q to exit out of Sorting Visualizer\n\n";

    Window window("Sorting visualizer", size*10, 1000);
    SDL_Event e;
    std::vector<int> vector = randomizeVector();
    Sort sorter(window, vector);

    int iteration = 0;
    int selected = 0;

    while(!window.isClosed())
    {
        while(SDL_PollEvent(&e)!=0)
        {
            if(e.type==SDL_QUIT){
                std::cout<<"\nEXITING PROGRAM.\n";
                window.closed = true;
            }  
            if(e.type==SDL_KEYDOWN){
                switch (e.key.keysym.sym)
                {
                    case SDLK_q:
                        std::cout<<"\nEXITING PROGRAM.\n";
                        window.closed = true;
                        break;

                    case SDLK_0:
                        iteration = 0;
                        vector = randomizeVector();
                        break;

                    case SDLK_1:
                        selected = 1;
                        sorter.visualizing = !sorter.visualizing;
                        break;

                    case SDLK_2:
                        selected = 2;
                        sorter.visualizing = !sorter.visualizing;
                        break;

                    case SDLK_3:
                        selected = 3;
                        sorter.visualizing = !sorter.visualizing;
                        break;
                    
                    default:
                        break;
                }
                break;
            }
        }

        if (sorter.visualizing){
            switch (selected)
            {
                case 1:
                    iteration = sorter.bubbleSort(iteration);
                    break;
                case 2:
                    iteration = sorter.selectionSort(iteration);
                    break;
                case 3:
                    iteration = sorter.insertionSort(iteration);
                    break;
                
                default:
                    break;
            }
        }
    }
    return 0;
}
