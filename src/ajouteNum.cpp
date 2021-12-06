#include "modele.h"


plateau ajouteNum(plateau P, int a){
    int placeVide = 0;
    for(auto l: P){
        for(auto c: l){
            if (c==0){
                placeVide++;
            }
        }
    }
    if (placeVide!=0){
        int placeChoisi = rand()%placeVide;
        placeVide = 0;
        for (int l = 0; l<4; l++){
            for (int c = 0; c<4; c++){
                if (P[l][c] == 0){
                    if (placeVide == placeChoisi){
                        P[l][c] = a;
                        return P;
                    }
                    placeVide++;
                }
            }
        }
    }
    return P;
}