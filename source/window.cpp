#include <window.h>
#include <SDL2/SDL_ttf.h>

SDL_Renderer *Window::renderer = nullptr;

Window::Window(const std::string &title, int width, int height) : 
    _title(title), _width(width), _height(height)
{
    closed = !init();
}

Window::~Window(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(_window);
    TTF_Quit();
    SDL_Quit();
}

bool Window::init(){
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cerr << "Failed to initialize SDL\n";
        return 0;
    }

    if (TTF_Init() == -1) {
        std::cerr << "Failed to initialize SDL_ttf\n";
    }

    _window = SDL_CreateWindow(
        _title.c_str(), 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        _width, 
        _height,
        0
    );

    if (_window == nullptr) {
        std::cerr << "Failed to create window\n";
        return 0;
    }

    renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_PRESENTVSYNC);

    if (renderer == nullptr) {
        std::cerr << "Failed to create renderer\n";
        return 0;
    }

    return true;
}

void Window::clear() {
    SDL_SetRenderDrawColor(renderer, 0,0,0,255);
    SDL_RenderClear(renderer);
    SDL_RenderSetScale(renderer, 1, 1);
}

void Window::visualizeSort(std::vector<int>& vector, unsigned int red, unsigned int blue, unsigned int size){
    SDL_SetRenderDrawColor(renderer, 0,0,0,255);
    SDL_RenderClear(renderer);
    SDL_RenderSetScale(renderer, 10, 10);

    unsigned int index = 0;
    SDL_RenderDrawLine(renderer, index, 99, index, 99);
    for (int i : vector)
    {
        if (index == red)
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        else if (index == blue)
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        else 
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        if(size != 0 && index == red) 
            SDL_RenderDrawLine(renderer, index, 99, index, size);
        SDL_RenderDrawLine(renderer, index, 99, index, i);
        index += 1;
    }
    SDL_RenderPresent(renderer);
}