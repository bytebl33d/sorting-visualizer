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

    for(int i= 0; i < size; i++)
    {
        v.push_back(d(rd));
    }
    return v;
}

int main(int argc, char **argv) {
    std::vector<int> vector = randomizeVector();

    int window_width = size*10;
    int window_height = 1000;
    int text_x = 200;
    int text_y = 300;

    Window window("Sorting visualizer", window_width, window_height);
    Sort sorter(window, vector);
    Text text(Window::renderer, "fonts/kongtext.ttf", 50, "Sorting Visualizer 1.0", {255,255,255});
    Text options1(Window::renderer, "fonts/kongtext.ttf", 25, "0: re-shuffle array", {255,255,255});
    Text options2(Window::renderer, "fonts/kongtext.ttf", 25, "1-3: run/pause selected algorithm", {255,255,255});
    Text options3(Window::renderer, "fonts/kongtext.ttf", 25, "m: open/close menu", {255,255,255});
    Text options4(Window::renderer, "fonts/kongtext.ttf", 25, "q: quit program", {255,255,255});

    int iteration = 0;
    int selected = 0;
    bool idle = true;
    SDL_Event e;
    while(!window.isClosed())
    {
       
        if (idle){
            window.clear();
            text.display(text_x,text_y, Window::renderer);
            options1.display(text_x,text_y+200, Window::renderer);
            options2.display(text_x,text_y+250, Window::renderer);
            options3.display(text_x,text_y+300, Window::renderer);
            options4.display(text_x,text_y+350, Window::renderer);
            SDL_RenderPresent(Window::renderer);
        }

        while(SDL_PollEvent(&e)!=0)
        {
            if(e.type==SDL_QUIT){
                std::cout<<"\nGoodbye...\n";
                window.closed = true;
            }  
            if(e.type==SDL_KEYDOWN){
                switch (e.key.keysym.sym)
                {
                    case SDLK_q:
                        std::cout<<"\nGoodbye...\n";
                        window.closed = true;
                        break;

                    case SDLK_m:
                        if (sorter.visualizing) idle = !idle;
                        break;

                    case SDLK_0:
                        iteration = 0;
                        vector = randomizeVector();
                        break;

                    case SDLK_1:
                        selected = 1;
                        idle = false;
                        sorter.visualizing = !sorter.visualizing;
                        break;

                    case SDLK_2:
                        selected = 2;
                        idle = false;
                        sorter.visualizing = !sorter.visualizing;
                        break;

                    case SDLK_3:
                        selected = 3;
                        idle = false;
                        sorter.visualizing = !sorter.visualizing;
                        break;
                    
                    default:
                        break;
                }
                break;
            }
        }

        if (sorter.visualizing && !idle){
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

        SDL_Delay(1);
    }
    return 0;
}
