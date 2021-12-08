#include <modele.h>

bool CHECK(bool test, string test1){
    if (!test){
        cout<<"test failed : "<< test1 <<endl;
        return false;
    }
    return true;
}



bool tests(){
    int n = 0;
    //puissance2 test
    if(!CHECK(puissance2(16) == 4, "puissance2(16) == 4")){n++;}
    if(!CHECK(puissance2(0) == -1, "puissance2(0) == 0")){n++;}

    //randint test
    if(!CHECK(randint(4)>=0 and randint(4)<4, "randint(4)>=0 and randint(4)<4")){n++;}

    //randnum
    int randnumtest = randnum();
    if (!CHECK(randnumtest == 2 or randnumtest == 4, "randnumtest == 2 or randnumtest == 4")){n++;}
    
    //ligneColone test
    
    if (!CHECK(LigneColone(15) == tab {3, 3} , "LigneColone(15) == {3, 3}")){n++;}
    if (!CHECK(LigneColone(0) == tab {0, 0} , "LigneColone(0) == {0, 0}")){n++;}
    if (!CHECK(LigneColone(7) == tab {1, 3} , "LigneColone(7) == {1, 3}")){n++;}
    
    //init_plateau test
    plateau init_plateau_test = init_plateau();
    int init_plateau_test_0 = 0; int init_plateau_test_2 = 0; int init_plateau_test_4 = 0;
    for(auto l:init_plateau_test){
        for(auto i:l){
            if (i == 0){
                init_plateau_test_0++;
            }else if(i == 2){
                init_plateau_test_2++;
            }else if(i == 4){
                init_plateau_test_4++;
            }
        }
    }
    if (!CHECK(init_plateau_test_0 == 14 and ((init_plateau_test_2 == 2 and init_plateau_test_4 == 0) or (init_plateau_test_2 == 1 and init_plateau_test_4 == 1) or (init_plateau_test_2 == 0 and init_plateau_test_4 == 2)), "init_plateau_test_0 == 14 and ((init_plateau_test_2 == 2 and init_plateau_test_4 == 0) or (init_plateau_test_2 == 1 and init_plateau_test_4 == 1) or (init_plateau_test_2 == 0 and init_plateau_test_4 == 2)")){n++;}

    // test des different deplacement
    plateau deplacement = {{0, 2, 2, 4}, 
                           {0, 4, 2, 4}, 
                           {8, 8, 8, 8}, 
                           {4, 0, 0, 4}};
    if (!CHECK(gauche(deplacement) == plateau {{4, 4, 0, 0}, {4, 2, 4, 0}, {16, 16, 0, 0}, {8, 0, 0, 0}}, "gauche(deplacement) == {{4, 4, 0, 0}, {4, 2, 4, 0}, {16, 16, 0, 0}, {8, 0, 0, 0}}")){n++;}
    if (!CHECK(droite(deplacement) == plateau {{0, 0, 4, 4}, {0, 4, 2, 4}, {0, 0, 16, 16}, {0, 0, 0, 8}}, "droite(deplacement) == {{0, 0, 4, 4}, {0, 4, 2, 4}, {0, 0, 16, 16}, {0, 0, 0, 8}}")){n++;}
    if (!CHECK(enhaut(deplacement) == plateau {{8, 2, 4, 8}, {4, 4, 8, 8}, {0, 8, 0, 4}, {0, 0, 0, 0}}, "enhaut(deplacement) == {{8, 2, 4, 8}, {4, 4, 8, 8}, {0, 8, 0, 4}, {0, 0, 0, 0}}")){n++;}
    if (!CHECK(enbas(deplacement) == plateau {{0, 0, 0, 0}, {0, 2, 0, 8}, {8, 4, 4, 8}, {4, 8, 8, 4}}, "enbas(deplacement) == {{0, 0, 0, 0}, {0, 2, 0, 8}, {8, 4, 4, 8}, {4, 8, 8, 4}}")){n++;}

    //test score
    if (!CHECK(score({{4, 128, 4, 16}, {0, 0, 0, 8}, {0, 0, 0, 0}, {2, 0, 0, 4}}, 5) == 824, "score({{4, 128, 4, 16}, {0, 0, 0, 8}, {0, 0, 0, 0}, {2, 0, 0, 4}}, 5) == 824")){n++;}

    //test gagnant
    if (!CHECK(not gagnant({{4, 128, 4, 16}, {0, 0, 0, 8}, {0, 0, 0, 0}, {2, 0, 0, 4}}), "not gagnant({{4, 128, 4, 16}, {0, 0, 0, 8}, {0, 0, 0, 0}, {2, 0, 0, 4}})")){n++;}
    if (!CHECK(gagnant({{4, 128, 4, 16}, {0, 0, 0, 8}, {0, 0, 0, 0}, {2, 0, 2048, 4}}), "gagnant({{4, 128, 4, 16}, {0, 0, 0, 8}, {0, 0, 0, 0}, {2, 0, 2048, 4}})")){n++;}

    //test defaite
    if (!CHECK(not defaite({{4, 128, 4, 16}, {0, 0, 0, 8}, {0, 0, 0, 0}, {2, 0, 0, 4}}), "(not defaite({{4, 128, 4, 16}, {0, 0, 0, 8}, {0, 0, 0, 0}, {2, 0, 0, 4}})")){n++;}
    if (!CHECK(defaite({{4, 128, 4, 16}, {2, 4, 2, 8}, {32, 2, 8, 4}, {2, 256, 16, 8}}), "defaite({{4, 128, 4, 16}, {2, 4, 2, 8}, {32, 2, 8, 4}, {2, 256, 16, 8}})")){n++;}

    //test ajouteNum
    if (!CHECK(ajouteNum({{4, 128, 4, 16}, {2, 4, 2, 8}, {16, 2, 4, 32}, {2, 8, 0, 4}}, 4) == plateau {{4, 128, 4, 16}, {2, 4, 2, 8}, {16, 2, 4, 32}, {2, 8, 4, 4}}, "ajouteNum({{4, 128, 4, 16}, {2, 4, 2, 8}, {16, 2, 4, 32}, {2, 8, 0, 4}}, 4) == {{4, 128, 4, 16}, {2, 4, 2, 8}, {16, 2, 4, 32}, {2, 8, 4, 4}}")){n++;}
    

    if (n!=0){return true;}else{ return false;}
}


/*
void tests(){
    //puissance2 test
    CHECK(puissance2(16) == 4);
    CHECK(puissance2(0) == 0);

    //randint test
    CHECK(randint(4)>=0 and randint(4)<4);

    //randnum
    int randnumtest = randnum();
    CHECK(randnumtest == 2 or randnumtest == 4);
    
    //ligneColone test
    
    CHECK((LigneColone(15) == tab {3, 3}));
    CHECK((LigneColone(0) == tab {0, 0}));
    CHECK((LigneColone(7) == tab {1, 3}));
    
    //init_plateau test
    plateau init_plateau_test = init_plateau();
    int init_plateau_test_0, init_plateau_test_2, init_plateau_test_4;
    for(auto l:init_plateau_test){
        for(auto i:l){
            if (i == 0){
                init_plateau_test_0++;
            }else if(i == 2){
                init_plateau_test_2++;
            }else if(i == 4){
                init_plateau_test_4++;
            }
        }
    }
    CHECK((init_plateau_test_0 == 14 and ((init_plateau_test_2 == 2 and init_plateau_test_4 == 0) or (init_plateau_test_2 == 1 and init_plateau_test_4 == 1) or (init_plateau_test_2 == 0 and init_plateau_test_4 == 2))));

    // test des different deplacement
    plateau deplacement = {{0, 2, 2, 4}, 
                           {0, 4, 2, 4}, 
                           {8, 8, 8, 8}, 
                           {4, 0, 0, 4}};
    CHECK((gauche(deplacement) == plateau {{4, 4, 0, 0}, {4, 2, 4, 0}, {16, 16, 0, 0}, {8, 0, 0, 0}}));
    CHECK((droite(deplacement) == plateau {{0, 0, 4, 4}, {0, 4, 2, 4}, {0, 0, 16, 16}, {0, 0, 0, 8}}));
    CHECK((enhaut(deplacement) == plateau {{8, 2, 4, 8}, {4, 4, 8, 8}, {0, 8, 0, 4}, {0, 0, 0, 0}}));
    CHECK((enbas(deplacement) == plateau {{0, 0, 0, 0}, {0, 2, 0, 8}, {8, 4, 4, 8}, {4, 8, 8, 4}}));

    //test score
    CHECK(score(plateau {{4, 128, 4, 16}, {0, 0, 0, 8}, {0, 0, 0, 0}, {2, 0, 0, 4}}, 5) == 824);

    //test gagnant
    CHECK((not gagnant(plateau {{4, 128, 4, 16}, {0, 0, 0, 8}, {0, 0, 0, 0}, {2, 0, 0, 4}}));
    CHECK((gagnant(plateau {{4, 128, 4, 16}, {0, 0, 0, 8}, {0, 0, 0, 0}, {2, 0, 2048, 4}})));

    //test defaite
    CHECK((not defaite(plateau {{4, 128, 4, 16}, {0, 0, 0, 8}, {0, 0, 0, 0}, {2, 0, 0, 4}})));
    CHECK((defaite(plteau {{4, 128, 4, 16}, {2, 4, 2, 8}, {32, 2, 8, 4}, {2, 256, 16, 8}})));

    //test ajouteNum
    CHECK((ajouteNum(plateau {{4, 128, 4, 16}, {2, 4, 2, 8}, {16, 2, 4, 32}, {2, 8, 0, 4}}, 4) == plateau {{4, 128, 4, 16}, {2, 4, 2, 8}, {16, 2, 4, 32}, {2, 8, 4, 4}}));
}
*/