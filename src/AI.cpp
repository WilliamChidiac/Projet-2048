#include "modele.h"

plateau AI(plateau P, int nb_simulation, int nb_coup_par_simulation){
    tab scores  = {0, 0, 0, 0};
    vector<plateau> pos = {gauche(P), droite(P), enhaut(P), enbas(P)};
    plateau anciennePos;
    plateau simulation;
    int move;
    int nNum;
    int scor;
    int n4;
    int sMax = 0;
    int sMaxIndex;
    for (int i = 0; i<4; i++){
        scor = 0;
        for (int partie = 0; partie<nb_simulation; partie++){
            n4 = 0;
            simulation = pos[i];
            for (int coup = 0; coup<nb_coup_par_simulation; coup++){
                anciennePos = simulation;
                move = randint(4);
                if (move == 0){
                    simulation = gauche(simulation);
                }else if (move == 1){
                    simulation = droite(simulation);
                }else if (move == 2){
                    simulation = enhaut(simulation);
                }else if (move == 3){
                    simulation = enbas(simulation);
                }
                if (simulation != anciennePos){
                    nNum = randnum();
                    if (nNum == 4){
                        n4++;
                    }
                    simulation = ajouteNum(simulation, nNum);
                }else if(defaite(simulation)){
                    break;
                }
            }
            scor += score(simulation, n4);
        }
        scores[i] = scor/nb_simulation;
        if (scores[i]>sMax){
            sMax = scores[i];
            sMaxIndex = i;
        }
    }
    return pos[sMaxIndex];
}

void jeuAI(SDL_Window *window, SDL_Renderer *renderer1, SDL_Texture *texture1, TTF_Font *font){

    //DEF VARIABLES POUR JEU
    bool AIMODE = false;
    SDL_Rect PLATEAU; //plateau de jeu sur l'interface graphique
    PLATEAU.h = 440; PLATEAU.w = 440; PLATEAU.x = 130; PLATEAU.y = 130; // initialisation des positions

    SDL_Rect HIGH, CURRENT;
    HIGH.h = 40; HIGH.y = 40; HIGH.x = 45; HIGH.w = 100;
    CURRENT.h = 40; CURRENT.y = 40; CURRENT.x = 480; CURRENT.w = 70;
    SDL_Surface *high = TTF_RenderText_Blended(font, "highscore :", {0, 0, 0});
    SDL_Surface *current = TTF_RenderText_Blended(font, "score :", {0, 0, 0});
    SDL_Texture *H = SDL_CreateTextureFromSurface(renderer1, high);
    SDL_Texture *C = SDL_CreateTextureFromSurface(renderer1, current);

    SDL_Rect caseAI;
    caseAI.h = 100; caseAI.w = 100; caseAI.x = 0; caseAI.y = 600;
    SDL_Rect ai;
    ai.h = 40; ai.w = 50; ai.x = 25; ai.y = 600;
    SDL_Rect OnOff;
    OnOff.h = 55; OnOff.w = 80; OnOff.x = 10; OnOff.y = 640;
    SDL_Surface *aiT = TTF_RenderText_Blended(font, "AI", {0, 0, 0});
    SDL_Texture *A = SDL_CreateTextureFromSurface(renderer1, aiT);
    
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
                        AIMODE = false;
                    }
                    GAMEISRUNNNING = not defaite(PC.first);
                }
            }else if (event.type == SDL_MOUSEBUTTONDOWN){
                int x;
                int y;
                SDL_GetMouseState(&x, &y);
                if((0<x and x<100) and (600<y and 700>y)){
                    AIMODE = not AIMODE;
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
        if (AIMODE){
            PC.first = AI(PC.first, 250, 25);
            PC.second = changeCases(PC);
            AIMODE = not defaite(PC.first);
            if (PC.first != aP){
                nNum = randnum();
                if (nNum == 4){
                    n4++;
                }
                PC.first = ajouteNum(PC.first, nNum);
                PC.second = changeCases(PC);
            }
        }
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

        SDL_SetRenderDrawColor(renderer1, 255, 127, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(renderer1, &caseAI);
        SDL_RenderCopy(renderer1, A, NULL, &ai);
        if ( not AIMODE){
            SDL_Surface *On = TTF_RenderText_Blended(font, "ON", {0, 0, 0});
            SDL_Texture *N = SDL_CreateTextureFromSurface(renderer1, On);

            SDL_RenderCopy(renderer1, N, NULL, &OnOff);
            SDL_DestroyTexture(N);
            SDL_FreeSurface(On);
        }else{
            SDL_Surface *Off = TTF_RenderText_Blended(font, "OFF", {0, 0, 0});
            SDL_Texture *F = SDL_CreateTextureFromSurface(renderer1, Off);
            SDL_RenderCopy(renderer1, F, NULL, &OnOff);
            SDL_DestroyTexture(F);
            SDL_FreeSurface(Off);

        }
        affiche_score(scor, renderer1, font);
        affiche_highscore("score/scoreAI.txt", renderer1, font, scor);
        SDL_RenderPresent(renderer1);
         
    }
    SDL_DestroyTexture(A);
    SDL_FreeSurface(aiT);

    SDL_DestroyTexture(H);
    SDL_DestroyTexture(C);
    SDL_FreeSurface(high);
    SDL_FreeSurface(current);
}