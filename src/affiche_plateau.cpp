#include "modele.h"


void affiche_plateau(plateau P){
    int max = 0;
    int Ncaractere = 0;
    int puissance = 0;
    int caractere;
    for(auto i: P){
        for(auto j: i){
            if (max<j){
                max = j;
            }
        }
    }
    for (int i = 1; i<=max; i = i*10){
        Ncaractere++;
        puissance = i;
    }
    for(int l = 0; l<P.size(); l++){
        cout<<" ";
        for (int i = 0; i != 1+(Ncaractere+3)*4; i++ ){
            cout<<"*";
        }
        cout<<endl;
        for (int c = 0; c<P[l].size(); c++){
            caractere = Ncaractere;
            cout<<" * ";
            for (int puissance1 = puissance; P[l][c]+1<puissance1; puissance1 = puissance1/10){
                caractere--;
            }
            for(int i = 0; i<(Ncaractere - caractere)/2; i++){
                cout<<" ";
            }
            if (P[l][c] != 0){

                cout<<P[l][c];
            }else{
                cout<<" ";
            }
            for(int i = 0; i<((Ncaractere-caractere)-((Ncaractere - caractere)/2)); i++){
                cout<<" ";
            }
        }
        cout<<" *"<<endl;
    }
    cout<<" ";
    for (int i = 0; i != 1+(Ncaractere+3)*4; i++ ){
            cout<<"*";
        }
    cout<<endl;
}

void affiche_cases(cases GC){
    for(int l = 0; l<4; l++){
        for (int c = 0; c<4; c++){
            GC[l][c].rect_color();
        }
    }
}