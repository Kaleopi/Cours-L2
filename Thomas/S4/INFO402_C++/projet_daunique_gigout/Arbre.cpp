// includes standards
#include <iostream>

// includes perso
#include "arbre.hpp"

using namespace std;

//Méthodes
Arbre::Arbre(){
  racine = nullptr;
}

//A vérifier
Arbre::Arbre(Noeud *n){
  racine = n;
}

//A faire
Arbre::Arbre(size_t taille){

}

//A vérifier
Arbre::Arbre(const Arbre& a){
  cout << "Constructeur par copie." << endl;
  racine = a.racine;
}

//A vérifier
Arbre::Arbre(Arbre&& a){
    cout << "Constructeur par déplacement." << endl;
  racine = a.racine;
}

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
