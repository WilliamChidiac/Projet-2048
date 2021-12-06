#include "modele.h"

int isHighScore(int scr, string filename){
    fstream lire;
    lire.open(filename, ios::in);
    string text;
    int highscore;
    getline(lire, text);
    highscore = stoi(text);
    lire.close();
    if (highscore < scr){
        lire.open(filename, ios::out);
        lire<< scr <<endl;
        return scr;
    }
    return highscore;
}