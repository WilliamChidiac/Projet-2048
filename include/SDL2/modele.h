#include <vector>
#include <iostream>
#include <SDL_ttf.h>
#include <SDL.h>
#include <string>
#include <fstream>
#include <stdexcept>
/*
#define CHECK(test) \
    if (!test)      \
        cout<<"test failed in line "<< __LINE__<< " : "<< #test << endl 
*/
using namespace std;

class C2048{
    public:
    int x;// abscisse de la case
    int y;// ordonne de la case
    int h;// hauteur de la case 
    int w;// largeur de la case
    int r;// intensite de rouge
    int g;// intensite de vert 
    int b;// intensite de bleu
    SDL_Renderer* renderer;// le moteur de rendu dans lequel les changement se feront
    TTF_Font *font;// police utilise


    /**
     * @brief change la valeur de l'intensite des couleur d'une case du plateau
     * 
     * @param r1 intensite de rouge
     * @param g1 intensite de vert 
     * @param b1 intensite de bleu
     */
    void change_color(int r1, int g1, int b1);

    /**
     * @brief dessine et rempli une case du plateau 
     * 
     */
    void rect_color();

    /**
     * @brief ecrit dans la case le nombre qui devrai s'afficher
     * 
     * @param nombre le nombre a ecrire
     */
    void e_rect(int nombre);
};

typedef vector<int> tab;
typedef vector<vector<int>> plateau;
typedef vector<vector<C2048>> cases;
typedef pair<plateau, cases> plateauCases;

/**
 * @brief calcul la puissance de 2 a laquel un nombre est eleve
 * 
 * @param num une puissance de 2
 * @return int la puissance a laquel num est eleve
 */
int puissance2(int num);

/** choisi un nombre au hazard 
 * @param a un entier 
 * @return un entier compris entre 0 inclus et a non inclus
 */
int randint(int a);

/**
 * @brief un nombre entre 2 et 4 avec des probabilite respective de 9/10 et 1/10
 * 
 * @return 2 ou 4
 */
int randnum();

/** transforme un entier en des coordonnees
 * @param a un entier compris en 0 et 15 et inclus
 * 
 * @return un tableau de deux entier representant des coordonnees dans le plateau
 */
tab LigneColone(int a);

/** initialise le plateau de 2048 au debut de la partie
 * 
 * @return plateau 2048 contenant 2 numeros seulement qui peuvent etre egal a 4 ou 2
 */
plateau init_plateau();

/**
 * @brief 
 * 
 * @param font police utilise
 * @param renderer1 moteur de rendu dans lequel les changement se feront
 * @param longueurCote longueur des cote des carre des dans le plateau
 * @param abs abscisse de la premeier case
 * @param ord ordonne de la premiere case
 * 
 * @return cases un vector de vectore de case du plateau de 2048 ayant une position, une dimension, un moteur de rendu dans lequel elles agiront et une police
 */
cases init_cases(TTF_Font *font, SDL_Renderer *renderer1, int longueurCote, int abs, int ord);

/**
 * @brief change la couleur des diffenrent cases de jeu dependament du nombre se trouvant sur dans le plateau en fonction de leur position
 * 
 * @param PC pair d'un plateau de jeu et de cases representant le plateau sur l'interface graphique
 * 
 * @return cases l'ensemble differente cases representant le plateau en changeant leur couleur  
 */
cases changeCases(plateauCases PC);

/** affiche le plateau 2048 sous forme d'un tableau de 4 ligne et 4 colone
 * 
 * @param P un plateau 2048
 */
void affiche_plateau(plateau P);

/**
 * @brief affiche les cases de 2048 (sans texte, juste la couleur) sur le plateau dans l'interface graphique
 * 
 */
void affiche_cases(cases GC);

/** deplace toutes les cases non vide du plateau vers la gauche tout en respectant les regle du jeu
 * @param P un plateau 2048
 * 
 * @return le nouveau plateau apres avoir bouge les elements de P vers la gauche
 */
plateau gauche(plateau P);

/** deplace toutes les cases non vide du plateau vers la droite tout en respectant les regle du jeu
 * @param P un plateau 2048
 * 
 * @return le nouveau plateau apres avoir bouge les elements de P vers la droite
 */
plateau droite(plateau P);

/** deplace toutes les cases non vide du plateau vers le haut tout en respectant les regle du jeu
 * @param P un plateau 2048
 * 
 * @return le nouveau plateau apres avoir bouge les elements de P vers le haut
 */
plateau enhaut(plateau P);

/** deplace toutes les cases non vide du plateau vers le bas tout en respectant les regle du jeu
 * @param P un plateau 2048
 * 
 * @return le nouveau plateau apres avoir bouge les elements de P vers le bas
 */
plateau enbas(plateau P);

/**
 * @brief effectue le deplacement attendu par le joueur lorsqu'il presse une touche du clavier
 * 
 * @param PC pair contenant un plateau et des cases de meme proportion tel que pour un meme l et c, PC[l][c].second represente PC.first[l][c] sur l'interface graphique
 * @param event un evenement defini par l'utilisateur (joueur)
 * 
 * @return plateauCases la nouvelle pair de plateau et de cases apres que le joueur ait effectue un deplacement;
 */
plateauCases choix_deplacement(plateauCases PC, SDL_Event event);

/** calcul le score que le joueur devrait avoir a partir d'un plateau en supposant que seul des 2 ont ete ajoute apres chaque mouvements 
 * @param P un plateau
 * 
 * @return le score du joueur si seulement des 2 avaient ete ajoute au plateau depuis le debut de la partie
 */
int score(plateau P, int n4);

/**
 * @brief affiche le score sur l'interface graphique 
 * 
 * @param sco le score 
 * @param rendererr le moteur de rendu utilise
 * @param font la police utilise
 */
void affiche_score(int sco, SDL_Renderer *rendererr, TTF_Font *font);

/** s'assure de si le joueur a gagne la partie ou pas;
 * @param P un plateau
 * 
 * @return true si la numeros 2048 a ete atteint
 * @return false sinon
 */
bool gagnant(plateau P);

/** s'assure que la partie n'est pas perdu
 * @param P un plateau
 * 
 * @return true si la partie est terminer et que c'est impossible d'ameliorer son score
 * @return false sinon
 */
bool defaite (plateau P);

/** ajoute aleatoirement un numeros entre 2 et 4 sur place vide du plateau aussi choisi aleatoirement
 * @param P un plateau
 * @param a un entier soit 2 soit 4 a ajouter
 * 
 * @return le nouveau plateau apres l'ajout de numeros 
 */
plateau ajouteNum(plateau P, int a);

/**
 * @brief 
 * 
 * @param font la police utilise 
 * @param window la fenetre sur laquel on veut affiche le menu
 * @param renderer1 le moteur de rendu dans lequel on dessinera le menu 
 * 
 * @return int: 1 si le joueur le mode de jeu 1 (normal) et 2 si il choisi le 2eme mode de jeu
 */
int menu(TTF_Font *font, SDL_Window *window, SDL_Renderer *renderer1);

/**
 * @brief si le score record est depasse durant une partie, il sera modifie et le nouveau record sera ecrit dans le fichier mode1.txt
 * 
 * @param scr le score atteint durant la partie
 * @param filename le nom du fichier dans lequel est sauvgarde le highscore
 * 
 * @return int representant le highscore (score record)
 */
int isHighScore(int scr, string filename);

/**
 * @brief change le score record si besoin et l'affiche sur la fenetre du jeu
 * 
 * @param filename le nom du fichier dans lequel est sauvegarde le score record
 * @param renderer le moteur de rendu dans lequel les changements (dessins) sont fait
 * @param font la police utilise
 * @param sco le score courant
 */
void affiche_highscore(string filename, SDL_Renderer *renderer, TTF_Font *font, int sco);


/**
 * @brief met en place une partie de 2048 normal
 * 
 * @param window la fenetre dans lequel s'affichera le jeu 
 * @param renderer1 le moteur de rendu dans lequel le jeu sera dessine et modifie
 * @param texture1 la texture utilise
 * @param font la police utilise
 * 
 */
void jeuNormal(SDL_Window *window, SDL_Renderer *renderer1, SDL_Texture *texture1, TTF_Font *font);

/**
 * @brief met en place une partie de 2048 dans laquel apres chaque coup, 2 numeros apparaisse
 * 
 * @param window la fenetre dans lequel s'affichera le jeu 
 * @param renderer1 le moteur de rendu dans lequel le jeu sera dessine et modifie
 * @param texture1 la texture utilise
 * @param font la police utilise
 * 
 */
void jeu2(SDL_Window *window, SDL_Renderer *renderer1, SDL_Texture *texture1, TTF_Font *font);

/**
 * @brief BOT qui joue a 2048
 * 
 * @param P plateau de jeu de 2048
 * @param nb_simulation nombre de partie joue pour chaque position differente
 * @param nb_coup_par_simulation nombre de coup par partie
 * @return plateau de jeu apres que le BOT ait choisi un sens de deplacement
 */
plateau AI(plateau P, int nb_simulation, int nb_coup_par_simulation);

/**
 * @brief met en place une partie de 2048 avec une IA implante et prete a etre utilise en cas de besoin
 * 
 * @param window la fenetre dans lequel s'affichera le jeu 
 * @param renderer1 le moteur de rendu dans lequel le jeu sera dessine et modifie
 * @param texture1 la texture utilise
 * @param font la police utilise
 * 
 */
void jeuAI(SDL_Window *window, SDL_Renderer *renderer1, SDL_Texture *texture1, TTF_Font *font);


void CHECK(string test);