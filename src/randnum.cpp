#include "modele.h"


void C2048::change_color(int r1, int g1, int b1){
    r = r1;
    g = g1;
    b = b1;
}

void C2048::rect_color(){
    SDL_Rect c;
    c.w = w; c.h = h; c.x = x; c.y = y;
    SDL_SetRenderDrawColor(renderer, r, g, b, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, &c);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawRect(renderer, &c);
}
    
void C2048::e_rect(int nombre){
    if (nombre != 0){
        SDL_SetRenderTarget(renderer, NULL);
        string str = to_string(nombre);
        SDL_Rect ec{x+w/4,y+h/3,w/2,h/2};
        //ec.h = h/2+(str.size()*5); ec.w = 10*(str.size()); ec.x = x+(x-ec.w)/2; ec.y = y+h/2;
        SDL_Surface *text = TTF_RenderText_Blended(font, str.c_str(), {0,0,0});
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, text);
        SDL_RenderCopy(renderer, texture, NULL, &ec);
        SDL_FreeSurface(text);
        SDL_DestroyTexture(texture);
    }
}


int puissance2(int num){
    int i = 0;
    for(int num1 = 1; num1 <= num; num1*=2){
        i++;
    }
    return i;
}

int randint(int a){
    return (rand()%a);
}

int randnum(){
    if (randint(10) == 0){
        return 4;
    }else{
        return 2;
    }
}

tab LigneColone(int a){
    return {a/4, a%4};
}