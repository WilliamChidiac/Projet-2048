#include "modele.h"

void jeuNormal(SDL_Window *window, SDL_Renderer *renderer1, SDL_Texture *texture1, TTF_Font *font){

    //DEF VARIABLES POUR JEU
    SDL_Rect PLATEAU; //plateau de jeu sur l'interface graphique
    PLATEAU.h = 440; PLATEAU.w = 440; PLATEAU.x = 130; PLATEAU.y = 130; // initialisation des positions
    SDL_Rect HIGH, CURRENT;
    HIGH.h = 40; HIGH.y = 40; HIGH.x = 45; HIGH.w = 100;
    CURRENT.h = 40; CURRENT.y = 40; CURRENT.x = 480; CURRENT.w = 70;
    SDL_Surface *high = TTF_RenderText_Blended(font, "highscore :", {0, 0, 0});
    SDL_Surface *current = TTF_RenderText_Blended(font, "score :", {0, 0, 0});
    SDL_Texture *H = SDL_CreateTextureFromSurface(renderer1, high);
    SDL_Texture *C = SDL_CreateTextureFromSurface(renderer1, current);

    cases GC = init_cases(font, renderer1, 100, 150, 150); //groupement des different rectangle composant les differente les cases du jeu sur l'interface
    plateau P = init_plateau(); //groupementn des differente nombre du plateau
    plateauCases PC = plateauCases(P, GC);
    PC.second = changeCases(PC);
    plateau aP;
    bool GAMEISRUNNNING = true;
    int nNum;
    int n4 = 0;
    while (GAMEISRUNNNING){

        SDL_SetRenderDrawColor(renderer1, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer1);
        SDL_SetRenderTarget(renderer1, texture1);

        aP = PC.first;
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT){
                GAMEISRUNNNING = false;
            }else if(event.type == SDL_KEYDOWN){
                if(event.key.keysym.sym == SDLK_BACKSPACE){
                    GAMEISRUNNNING = false;
                }else{
                    plateauCases PC1 = choix_deplacement(PC, event);
                    if (PC1.first == plateau(1, tab(1, 0))){
                        break;
                    }else{
                        PC = PC1;
                    }
                    GAMEISRUNNNING = not defaite(PC.first);
                }
            }else{
                break;
            }
            
            if (PC.first != aP){
                nNum = randnum();
                if (not GAMEISRUNNNING){
                continue;
                }else if (nNum == 4){
                    n4++;
                }
                PC.first = ajouteNum(PC.first, nNum);
                PC.second = changeCases(PC);
            }

        }
        /*
        if (PC.first != aP){
            PC.first = ajouteNum(PC.first, nNum);
            PC.second = changeCases(PC);
        }
        */
        if (not GAMEISRUNNNING){
            continue;
        }
        SDL_SetRenderDrawColor(renderer1, 50, 50, 50, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(renderer1, &PLATEAU);
        SDL_SetRenderDrawColor(renderer1, 0, 0, 0, SDL_ALPHA_OPAQUE);
        for(int i = 250; i<=550; i += 100){
            SDL_RenderDrawLine(renderer1, i, 150, i, 550);
            SDL_RenderDrawLine(renderer1, 150, i, 550, i);
        }
        affiche_cases(PC.second);
        SDL_SetRenderTarget(renderer1, NULL);
        SDL_RenderCopy(renderer1, texture1, NULL, NULL);
        for (int l = 0; l<4; l++){
            for (int c = 0; c<4; c++){
                PC.second[l][c].e_rect(PC.first[l][c]);
            }
        }
        int scor = score(PC.first, n4);

        SDL_SetRenderDrawColor(renderer1, 245, 245, 220, 255);
        SDL_RenderFillRect(renderer1, &HIGH);
        SDL_RenderFillRect(renderer1, &CURRENT);
        SDL_RenderCopy(renderer1, H, NULL, &HIGH);
        SDL_RenderCopy(renderer1, C, NULL, &CURRENT);

        affiche_score(scor, renderer1, font);
        affiche_highscore("score/mode1.txt", renderer1, font, scor);
        SDL_RenderPresent(renderer1);
         
    }
    SDL_DestroyTexture(H);
    SDL_DestroyTexture(C);
    SDL_FreeSurface(high);
    SDL_FreeSurface(current);
}

void jeu2(SDL_Window *window, SDL_Renderer *renderer1, SDL_Texture *texture1, TTF_Font *font){

    //DEF VARIABLES POUR JEU
    SDL_Rect PLATEAU; //plateau de jeu sur l'interface graphique
    PLATEAU.h = 440; PLATEAU.w = 440; PLATEAU.x = 130; PLATEAU.y = 130; // initialisation des positions

    SDL_Rect HIGH, CURRENT;
    HIGH.h = 40; HIGH.y = 40; HIGH.x = 45; HIGH.w = 100;
    CURRENT.h = 40; CURRENT.y = 40; CURRENT.x = 480; CURRENT.w = 70;
    SDL_Surface *high = TTF_RenderText_Blended(font, "highscore :", {0, 0, 0});
    SDL_Surface *current = TTF_RenderText_Blended(font, "score :", {0, 0, 0});
    SDL_Texture *H = SDL_CreateTextureFromSurface(renderer1, high);
    SDL_Texture *C = SDL_CreateTextureFromSurface(renderer1, current);

    cases GC = init_cases(font, renderer1, 100, 150, 150); //groupement des different rectangle composant les differente les cases du jeu sur l'interface
    plateau P = init_plateau(); //groupementn des differente nombre du plateau
    plateauCases PC = plateauCases(P, GC);
    PC.second = changeCases(PC);
    plateau aP;
    bool GAMEISRUNNNING = true;
    int nNum, nNum2;
    int n4 = 0;
    while (GAMEISRUNNNING){

        SDL_SetRenderDrawColor(renderer1, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer1);
        SDL_SetRenderTarget(renderer1, texture1);

        aP = PC.first;
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT){
                GAMEISRUNNNING = false;
            }else if(event.type == SDL_KEYDOWN){
                if(event.key.keysym.sym == SDLK_BACKSPACE){
                    GAMEISRUNNNING = false;
                }else{
                    plateauCases PC1 = choix_deplacement(PC, event);
                    if (PC1.first == plateau(1, tab(1, 0))){
                        break;
                    }else{
                        PC = PC1;
                        GAMEISRUNNNING = not defaite(PC.first);
                    }
                    
                }
            }else{
                break;
            }
            
            nNum = randnum();
            nNum2 = randnum();
            if (not GAMEISRUNNNING){
            continue;
            }else if (nNum == 4){
                n4++;
            
            }

        }
        if (not GAMEISRUNNNING){
            continue;
        }
        if (PC.first != aP){
            aP == PC.first;
            PC.first = ajouteNum(PC.first, nNum);
            if (PC.first != aP){
                if (nNum == 4){
                    n4++;
                }
                aP = PC.first;
                PC.first = ajouteNum(PC.first, nNum2);
                if (PC.first != aP and nNum2 == 4){
                    n4++;
                }
            }
            PC.second = changeCases(PC);
        }
        SDL_SetRenderDrawColor(renderer1, 50, 50, 50, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(renderer1, &PLATEAU);
        SDL_SetRenderDrawColor(renderer1, 0, 0, 0, SDL_ALPHA_OPAQUE);
        for(int i = 250; i<=550; i += 100){
            SDL_RenderDrawLine(renderer1, i, 150, i, 550);
            SDL_RenderDrawLine(renderer1, 150, i, 550, i);
        }
        affiche_cases(PC.second);
        SDL_SetRenderTarget(renderer1, NULL);
        SDL_RenderCopy(renderer1, texture1, NULL, NULL);
        for (int l = 0; l<4; l++){
            for (int c = 0; c<4; c++){
                PC.second[l][c].e_rect(PC.first[l][c]);
            }
        }
        int scor = score(PC.first, n4);

        SDL_SetRenderDrawColor(renderer1, 245, 245, 220, 255);
        SDL_RenderFillRect(renderer1, &HIGH);
        SDL_RenderFillRect(renderer1, &CURRENT);
        SDL_RenderCopy(renderer1, H, NULL, &HIGH);
        SDL_RenderCopy(renderer1, C, NULL, &CURRENT);

        affiche_score(scor, renderer1, font);
        affiche_highscore("score/mode2.txt", renderer1, font, scor);
        SDL_RenderPresent(renderer1);
         
    }
    SDL_DestroyTexture(H);
    SDL_DestroyTexture(C);
    SDL_FreeSurface(high);
    SDL_FreeSurface(current);
}
