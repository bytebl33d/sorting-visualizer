#pragma once
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <string>

class Text {
public:
    Text(SDL_Renderer *renderer, const std::string &fontPath, int fontSize, const std::string &messageText, const SDL_Color &color);

    void display(int x, int y, SDL_Renderer* renderer) const;

    static SDL_Texture *loadFont(SDL_Renderer *renderer, const std::string &fontPath, int fontSize, const std::string &messageText, const SDL_Color &color);

private:
    SDL_Texture *_textTexture = nullptr;
    mutable SDL_Rect _textRect;
};
