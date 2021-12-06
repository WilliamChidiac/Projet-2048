#include "modele.h"


int score(plateau P, int n4){
    int nFusion;
    int scor = 0;
    for (auto i: P){
        for (auto j: i){
            nFusion = 1;
            while(j>2){
                scor += j*nFusion;
                j = j/2;
                nFusion *= 2;
            }
        }
    }
    return scor - n4*4;
}

void affiche_score(int sco, SDL_Renderer *rendererr, TTF_Font *font){
    string str = to_string(sco);
    SDL_Rect SCORE;
    SCORE.h = 40; SCORE.y = 80; SCORE.x = 550-(str.size())*5; SCORE.w = (str.size())*10;
    SDL_SetRenderDrawColor(rendererr, 245, 245, 220, 255);
    SDL_RenderFillRect(rendererr, &SCORE);
    SDL_SetRenderDrawColor(rendererr, 0, 0 ,0, 255);
    SDL_Surface *text = TTF_RenderText_Blended(font, str.c_str(), {0,0,0});
    SDL_Texture *texture = SDL_CreateTextureFromSurface(rendererr, text);
    SDL_RenderCopy(rendererr, texture, NULL, &SCORE);
    SDL_FreeSurface(text);
    SDL_DestroyTexture(texture);
}

void affiche_highscore(string filename, SDL_Renderer *renderer, TTF_Font *font, int sco){
    int highsco = isHighScore(sco, filename);
    string str = to_string(highsco);
    SDL_Rect HSCORE;
    HSCORE.h = 40; HSCORE.y = 80; HSCORE.x = 100-(str.size())*5; HSCORE.w = (str.size())*10;
    SDL_SetRenderDrawColor(renderer, 245, 245, 220, 255);
    SDL_RenderFillRect(renderer, &HSCORE);
    SDL_SetRenderDrawColor(renderer, 0, 0 ,0, 255);
    SDL_Surface *text = TTF_RenderText_Blended(font, str.c_str(), {0,0,0});
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, text);
    SDL_RenderCopy(renderer, texture, NULL, &HSCORE);
    SDL_FreeSurface(text);
    SDL_DestroyTexture(texture);
}