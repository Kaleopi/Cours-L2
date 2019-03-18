// includes standards
#include <iostream>

// includes perso
#include "arbre.hpp"

using namespace std;

//Constructeur
    //par défault
Arbre::Arbre(){
  racine = nullptr;
}
    //Avec un noeud (arbre déjà creer) et l'on identifie le noeuds comme racine
//A vérifier
Arbre::Arbre(Noeud *n){
  racine = n;
}
    //Avec initialisation de la taille
//A faire
Arbre::Arbre(size_t taille){

}
    //Par copie
//A vérifier
Arbre::Arbre(const Arbre& a){
  cout << "Constructeur par copie." << endl;
  racine = a.racine;
}
    //Par déplacement
//A vérifier
Arbre::Arbre(Arbre&& a){
    cout << "Constructeur par déplacement." << endl;
  racine = a.racine;
}
    //Par liste
//A vérifier
Arbre::Arbre(const initializer_list<Noeud> &liste){
  racine = new Noeud[liste.size()];
  int i=0;
  for(const Noeud& l:liste){
    racine[i++]=l;
  }
}

//A vérifier
Arbre::Arbre(const Arbre& a){
  if(this!=a){
    for(int i=0 ;;){
      
    }
  }
}
    //par Range
//A vérifier
Arbre(a.begin(),a.end()){
    for(int i=0 ; i!=a.end() ; i++){

    }
}
//Assignation
    //Par copie
Arbre& operator=(const Arbre& a){

}