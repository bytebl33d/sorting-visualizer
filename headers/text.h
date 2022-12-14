#pragma once
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <string>

class Text {
public:
    Text(SDL_Renderer *renderer, const std::string &fontPath, int fontSize, const std::string &messageText, const SDL_Color &color);
    ~Text();

    void display(int x, int y, SDL_Renderer* renderer) const;

    SDL_Texture *loadFont(SDL_Renderer *renderer, const std::string &fontPath, int fontSize, const std::string &messageText, const SDL_Color &color);

private:
    TTF_Font *_font = nullptr;
    SDL_Texture *_textTexture = nullptr;
    mutable SDL_Rect _textRect;
};
