#include "modele.h"



cases changeCases(plateauCases PC){
    for (int l = 0; l<4; l++){
        for (int c = 0; c<4; c++){
            int i = puissance2(PC.first[l][c]);
            if (i == 1){
                PC.second[l][c].change_color(255, 255, 255);
            }else if (i == 0){
                PC.second[l][c].change_color(50, 50, 50);
            }else{
                PC.second[l][c].change_color(255-20*(i-1), 20*(i-1), 255-i*i);
            }
        }
    }
    return PC.second;
}

plateau gauche(plateau P){
    int sep;
    for (int l = 0; l < P.size(); l++){
        for (int c = 0; c<P[l].size(); c++){
            if (P[l][c] != 0){
                sep = c+1;
                while( P[l][sep] == 0 and sep<4){
                    sep++;
                }
                if (sep<4 and P[l][sep] == P[l][c]){
                    P[l][c] = P[l][c]*2;
                    P[l][sep] = 0;
                }
                sep = 0;
                while (P[l][sep] != 0 and sep<c){
                    sep++;
                }
                if (sep != c){
                    P[l][sep] = P[l][c];
                    P[l][c] = 0;
                }
            }
        }
    }
    return P;
}


plateau droite(plateau P){
    int score;
    for (int l = 0; l<P.size(); l++){
        for(int c = 0; c<2; c++ ){
            P[l][c] += P[l][3-c];
            P[l][3-c] = P[l][c] - P[l][3-c];
            P[l][c] -= P[l][3-c];
        }
    }
    P = gauche(P);
    for (int l = 0; l<P.size(); l++){
        for(int c = 0; c<2; c++ ){
            P[l][c] += P[l][3-c];
            P[l][3-c] = P[l][c] - P[l][3-c];
            P[l][c] -= P[l][3-c];
        }
    }
    return P;
}


plateau enhaut(plateau P){
    int sep;
    for (int c = 0; c < P.size(); c++){
        for (int l = 0; l<P[c].size(); l++){
            if (P[l][c] != 0){
                sep = l+1;
                while(sep<4 and P[sep][c] == 0 ){
                    sep++;
                }
                if (sep<4 and P[sep][c] == P[l][c]){
                    P[l][c] = P[l][c]*2;
                    P[sep][c] = 0;
                }
                sep = 0;
                while (P[sep][c] != 0 and sep<l){
                    sep++;
                }
                if (sep != l){
                    P[sep][c] = P[l][c];
                    P[l][c] = 0;
                }
            }
        }
    }
    return P;
}


plateau enbas(plateau P){
    tab remp;
    for (int l = 0; l<2; l++){
        remp = P[l];
        P[l] = P[3-l];
        P[3-l] = remp;
    }
    P = enhaut(P);
    for (int l = 0; l<2; l++){
        remp = P[l];
        P[l] = P[3-l];
        P[3-l] = remp;
    }
    return P;
}

plateauCases choix_deplacement(plateauCases PC, SDL_Event event){
    if ((event.key.keysym.sym == SDLK_DOWN) or (event.key.keysym.sym == SDLK_s)){
        PC.first = enbas(PC.first);
    }else if((event.key.keysym.sym == SDLK_UP) or (event.key.keysym.sym == SDLK_w)){
        PC.first = enhaut(PC.first);
    }else if((event.key.keysym.sym == SDLK_LEFT) or (event.key.keysym.sym == SDLK_a)){
        PC.first = gauche(PC.first);
    }else if((event.key.keysym.sym == SDLK_RIGHT) or (event.key.keysym.sym == SDLK_d)){
        PC.first = droite(PC.first);
    }else{
        PC.first = {{0}};
        return PC;
    }
    PC.second = changeCases(PC);
    return PC;
}