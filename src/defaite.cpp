#include "modele.h"


bool gagnant(plateau P){
    for (auto i: P){
        for (auto j: i){
            if (j == 2048){
                return true;
            }
        }
    }
    return false;
}


bool defaite (plateau P){
    if (P == gauche(P) and P == droite(P) and P == enbas(P) and P == enhaut(P)){
        return true;
    }
    return false;
}