#include "modele.h"

int main(int argc, char *argv[]){
    if (tests()){return 0;}
    //INTIAILISATION DES DIFFERENTES VARIABLES : DEBUT
    if (SDL_Init(SDL_INIT_EVERYTHING)!=0){
        printf("error initializing SDL: %s\n", SDL_GetError());
    }else if (TTF_Init() != 0){
        printf("error initializing SDL_TTF: %s\n", SDL_GetError());
    }

    SDL_Window* window = SDL_CreateWindow("2048", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 700, 700, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer1 = SDL_CreateRenderer(window, -1, 0);
    SDL_Texture* texture1 = SDL_CreateTexture(renderer1, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 700, 700);
    TTF_Font *font = TTF_OpenFont("font/arial.ttf", 32);
    if (font<=0)cout<<"fail"<<endl;

    // FIN INITIALISATION
    bool windowIsOpen = true;
    while(windowIsOpen){
        int mode = menu(font, window, renderer1);
        SDL_SetRenderDrawColor(renderer1, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer1);
        SDL_RenderClear(renderer1);
        if(mode == 1){
            jeuNormal(window, renderer1, texture1, font);
        }else if (mode == 2){
            jeu2(window, renderer1, texture1, font);
        }else if (mode == 0){
            windowIsOpen = false;
        }
    }
    
    // REINITIALISATION DE LA MEMOIRE, DEBUT
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyTexture(texture1);
    SDL_DestroyRenderer(renderer1);
    SDL_DestroyWindow(window);
    SDL_Quit();
    // REINITIALISATION DE LA MEMOIR, FIN
    return 0;
}
