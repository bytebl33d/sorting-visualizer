#include <text.h>
#include <iostream>
#include <window.h>

Text::Text(SDL_Renderer *renderer, const std::string &fontPath, int fontSize, const std::string &messageText, const SDL_Color &color){
    _textTexture = loadFont(renderer, fontPath, fontSize, messageText, color);
    SDL_QueryTexture(_textTexture, nullptr, nullptr, &_textRect.w, &_textRect.h);
}

Text::~Text(){
    TTF_CloseFont(_font);
    SDL_DestroyTexture(_textTexture);
    TTF_Quit();
}

void Text::display(int x, int y, SDL_Renderer* renderer) const {
    _textRect.x = x;
    _textRect.y = y;

    SDL_RenderCopy(renderer, _textTexture, nullptr, &_textRect);
}

SDL_Texture *Text::loadFont(SDL_Renderer *renderer, const std::string &fontPath, int fontSize, const std::string &messageText, const SDL_Color &color){
    TTF_Init();
    _font = TTF_OpenFont(fontPath.c_str(), fontSize);
    if (!_font) {
        std::cerr << "Failed to load font\n";
    }

    auto textSurface = TTF_RenderText_Solid(_font, messageText.c_str(), color);
    if (!textSurface) {
        std::cerr << "Failed to create text surface\n";
    }

    auto textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if (!textTexture) {
        std::cerr << "Failed to create text texture\n";
    }

    SDL_FreeSurface(textSurface);
    return textTexture;
}