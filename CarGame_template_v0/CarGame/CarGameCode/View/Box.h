//
// Created by eys on 21/8/21.
//

#ifndef BOX_H
#define BOX_H

#include "SDL.h"
#include "../Utils/Vector2D.h"

#define WHITE SDL_Color({255,255,255})
#define BLACK SDL_Color({0,0,0})
#define BLUE SDL_Color({0,0,255})
#define RED SDL_Color({255,0,0})
#define SUPERRED SDL_Color({200,0,0})
#define YELLOW SDL_Color({255,255,0})
#define COIN SDL_Color({123,125,43}) //Nuevos colores para los nuevos items
#define BULLET SDL_Color({223,45,133})
#define TURBO SDL_Color({23,75,33})
#define OIL SDL_Color({123,175,143})
#define TRUCK SDL_Color({32,26,210})
class Box {
    SDL_Rect rect;
    SDL_Color color;
public:

    Box(SDL_Rect _rect, SDL_Color _color): rect(_rect), color(_color){}
    void render(SDL_Renderer *renderer, Point2D<int> origin ={0,0}){
        SDL_Rect dst = {rect.x + origin.getX(), rect.y + origin.getY(), rect.w, rect.h};
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_RenderDrawRect(renderer, &dst );
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    }
};

#endif