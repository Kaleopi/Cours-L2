#ifndef ARBRE_H
#define ARBRE_H

//includes
#include "noeud.hpp"
#include <iostream>
#include <initializer_list>
//defines variables

using namespace std;

//classe Arbre
class Arbre{
protected:
  Noeud *racine;

public:
  Arbre();                                                                      //Par défaut
  Arbre(Noeud *n);                                                              //Par init par noeud
  Arbre(size_t taille);                                                         //Par init par taille
  Arbre(const Arbre& a);                                                        //Par copie
  Arbre(Arbre&& a);                                                             //Par déplacement
  Arbre(const initializer_list<Noeud> &liste);                                  //Par liste
  //Opérateurs
  Arbre& operator=(const Arbre& a);                                             //Assignation par copie

};
#endif /*ARBRE_H*/
