#ifndef _NOEUD_H_
#define _NOEUD_H_

#define VIDE ((Noeud *)0)   // VIDE : pointeur vers 'rien' <=> NULL

//      ######################
//      ##                  ##
//      ##      NOEUD :     ##
//      ##                  ##
//      ######################


// NB : La classe Noeud est souvent utilis� comme un 'sous-arbre'


class Noeud{       

    int v;          // �tiquette du noeud
    Noeud *fg;      // fils gauche
    Noeud *fd;      // fils droite

public:

    // terminologie :
    //
    //  ->  a est un "ant�c�dent" d'un noeud n si a pointe sur n 
    //          (i.e: a->fg = *n ou a->fd = *n)
    //  ->  "racine" : noeud qui n'a pas d'ant�c�dant
    //  ->  "feuille" : noeud qui n'a pas de fils
    //  ->  "descendant" : noeud fils (gauche ou droit) 


//-----------------------------------------------------------------------------
// I) Constructeurs :
    
    // cr�� un noeud, o� : v = -1, fg == fd == VIDE 
    Noeud();
    Noeud(int nb);              // initialise v � nb

//-----------------------------------------------------------------------------
// II) Destructeur :

    Noeud *videSousArbre();     // retourne le pointeur VIDE


//-----------------------------------------------------------------------------
// III) tests :
        
    bool noeud_vide();          // true si le noeud est VIDE
    bool est_fils(Noeud *pere);
    bool est_pere(Noeud *fils);

    bool appartient(int nb);    // test si nb appartient au sous-arbre

    // remarque : le test noeud_vide() est utile pour �viter un 'gros plantage'
    // dans la situation suivante par exemple :
    //      Noeud *tmp = VIDE;
    //      ...
    //      tmp->etiquette();   (on ne peut pas lire v si le noeud est VIDE)

//-----------------------------------------------------------------------------
//  IV )  informations sur le sous-arbre :

    Noeud *fils_gauche();
    Noeud *fils_droit();

    int etiquette();            // retourne -1 si le noeud est VIDE
    
    // etiquette_fg() et etiquette_fd()
    int etiquette_fg();
    int etiquette_fd();
    
    int hauteur();              // hauteur de l'arbre sous-jacent au noeud 
	int cardinal();				// nombre de noeuds ...

    // pr�condition : le noeud n'est pas VIDE
    int max();
    int min();

//-----------------------------------------------------------------------------
// V ) Op�rations sur les sous-arbres :

    // etiquette(pere, nb) : modifie l'etiquette, si possible ...
    // ( pere == VIDE <=> noeud == racine )
    int etiquette(Noeud *pere, int nb);      

    void insertion(int nb);     

    Noeud *recherche(int nb);
    
    // recherche d'un �l�ment en suivant un parcours d�finit par le tableau *t.
    // Parcours d�finit par r�currence, pour passer du noeud n[i] au noeud 
    // n[i+1] : 
    //      si t[i] == -1 , n[i+1] = fils gauche de n[i]
    //      si t[i] ==  1 , n[i+1] = fils droit de n[i] 
    //      sinon n[i+1] = n[i]
    // Rq : 1) pour un arbre de hauteur h, la taille du tableau doit �tre < h
    // (pour un chemin simple de h noeuds il n'y a que h-1 'arcs' ... )
    //      2) pour le noeud d'�tiquette 13 par exemple , s'il n'a pas de fils
    // gauche alors, on affiche '|13' et s'il n'a pas de fils droit, on affiche
    // '13|'
    
    Noeud *recherche(int *t, int taille);


    // retourne l'adresse du noeud contenant le max du sous-arbre
    Noeud *recherche_max();     

    // recherche l'ant�c�dant du noeud d'�tiquette 'nb' :
    // Nb :  pr�condition v != nb
    Noeud *recherche_pere(int nb);  

    void supprime(int nb);

    // pr�condition : au moin un descendant
    void supprime_racine();    
    
//-----------------------------------------------------------------------------
// VI) Affichage :
    
    void affiche_sous_arbre();
    void affiche_sous_arbre_1();

    // affichage sous forme de liste ( parcours infixe : fils gauche, etiquette,
    //  fils droit )
    friend ostream& operator<<(ostream& o, Noeud n);
    
};

#endif
