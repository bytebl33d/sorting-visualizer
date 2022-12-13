#pragma once

#include <SDL2/SDL.h>
#include <string>
#include <vector>
#include <iostream>

class Window {
public:
    Window(const std::string &title, int width, int height);
    ~Window();

    inline bool isClosed() const { return closed;}
    bool closed = false;

    void clear();

    void visualizeSort(std::vector<int>& vector, unsigned int red, unsigned int blue, unsigned int size);

    static SDL_Renderer *renderer;

private:
    bool init();

private:
    std::string _title;
    int _width = 800;
    int _height = 600;

    SDL_Window *_window = nullptr;
};