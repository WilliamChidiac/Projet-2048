#include "modele.h"

int menu(TTF_Font *font, SDL_Window *window, SDL_Renderer *renderer1){
    SDL_Surface *text1 = TTF_RenderText_Blended(font, "MODE 1: Normal", {0, 0, 0});
    SDL_Surface *text2 = TTF_RenderText_Blended(font, "MODE 2: double spawning", {0, 0, 0});
    SDL_Surface *text3 = TTF_RenderText_Shaded(font, "2048", {0, 0, 0}, {250, 250, 225});
    SDL_Texture *texture3 = SDL_CreateTextureFromSurface(renderer1, text3);
    SDL_Texture *texture2 = SDL_CreateTextureFromSurface(renderer1, text2);
    SDL_Texture *texture1 = SDL_CreateTextureFromSurface(renderer1, text1);
    SDL_Rect MODE1, MODE2, TEXTMODE1, TEXTMODE2, TEXT2048;
    MODE1.h = 120, MODE1.w = 120; MODE1.x = 150; MODE1.y = 350;
    MODE2.h = 120, MODE2.w = 120; MODE2.x = 430; MODE2.y = 350;
    TEXTMODE1.h = 34; TEXTMODE1.w = 150; TEXTMODE1.x = 135; TEXTMODE1.y = 315;
    TEXTMODE2.h = 34; TEXTMODE2.w = 170; TEXTMODE2.x = 415; TEXTMODE2.y = 315;
    TEXT2048.h = 100; TEXT2048.w = 300; TEXT2048.x = 200; TEXT2048.y = 150;
    cases GC = init_cases(font, renderer1, 25, 160, 360);
    cases GC2 = init_cases(font, renderer1, 25, 440, 360);
    //PARTIE MENU DEBUT
    bool MENU = true; 
    while(MENU)
    {
        SDL_SetRenderDrawColor(renderer1, 255, 255, 255, 255);
        SDL_RenderClear(renderer1);
        SDL_Texture* texture = SDL_CreateTexture(renderer1, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 700, 700);
        
        SDL_Event event;
        
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT){
                return 0;
            }else if(event.type == SDL_KEYDOWN){
                if(event.key.keysym.sym == SDLK_BACKSPACE){
                    return 0;
                }
            }else if (event.type == SDL_MOUSEBUTTONDOWN){
                int x;
                int y;
                SDL_GetMouseState(&x, &y);
                if((150<x and x<270) and (350<y and 470>y)){
                    return 1;
                }else if(430<x and x<550 and 350<y and y<470){
                    return 2;
                }
            }
        }
        SDL_SetRenderDrawColor(renderer1, 150, 150, 150, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawRect(renderer1, &MODE1);
        SDL_RenderDrawRect(renderer1, &MODE2);
        for(int l = 0; l<4; l++){
            for(int c= 0; c<4; c++){
                GC[l][c].change_color(245, 245, 220);
                GC[l][c].rect_color();
                GC2[l][c].change_color(200, 200, 150);
                GC2[l][c].rect_color();
            }
        }
        SDL_SetRenderTarget(renderer1, NULL);
        SDL_RenderCopy(renderer1, texture1, NULL, &TEXTMODE1);
        SDL_RenderCopy(renderer1, texture2, NULL, &TEXTMODE2);
        SDL_SetRenderDrawColor(renderer1, 245, 245, 220, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(renderer1, &TEXT2048);
        SDL_RenderCopy(renderer1, texture3, NULL, &TEXT2048);
        SDL_RenderPresent(renderer1);
    }
    

    SDL_DestroyTexture(texture1);
    SDL_DestroyTexture(texture2);
    SDL_FreeSurface(text1);
    SDL_FreeSurface(text2);
    return 0;
}
