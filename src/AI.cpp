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
