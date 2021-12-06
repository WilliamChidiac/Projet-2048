#include "modele.h"


plateau init_plateau(){
    plateau P = plateau(4, tab(4, 0));
    int emp1 = rand()%16;
    int emp2;
    tab emplacement1 = {emp1/4, emp1%4};
    tab emplacement2;
    do{
        emp2 = rand()%16;
        emplacement2 = {emp2/4, emp2%4};
    }while(emplacement1 == emplacement2);
    P[emplacement1[0]][emplacement1[1]] = randnum();
    P[emplacement2[0]][emplacement2[1]] = randnum();
    return P;
}

cases init_cases(TTF_Font *font, SDL_Renderer *renderer1, int longueurCote, int abs, int ord){
    cases gc = cases(4, vector<C2048>(4));
    for (int l = 0; l<4; l++){
        for (int c = 0; c<4; c++){
            gc[l][c].renderer = renderer1;
            gc[l][c].font = font;
            gc[l][c].w = longueurCote;
            gc[l][c].h = longueurCote;
            gc[l][c].x = abs +c*longueurCote;
            gc[l][c].y = ord + l*longueurCote;
        }
    }
    return gc;
}
