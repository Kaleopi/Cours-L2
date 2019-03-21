#ifndef ARBRE_H
#define ARBRE_H
using namespace std;

//includes
#include "noeud.hpp"
#include <iostream>
#include <ostream>
#include <initializer_list>
#include <iterator>
#include <stack>
//defines variables


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
  Arbre(iterator_type a);                                          //Par Range
  //Opérateurs
  Arbre& operator=(const Arbre& a);                                              //Assignation par copie
  //friend class MyIterator<T>;
  //friend class ConstArbreIterator<T>;
  //typedef MyIterator< Type >  iterator;
  //typedef MyIterator< const Type >  const_iterator;
  Iterator* CreationIterateur(){
  return new MyIterator(*this);
  }
  iterator begin(){
    Iterator* it=CreationIterateur();
    return (it.debut());
  };
  iterator end(){
    Iterator* it=CreationIterateur();
    return (it.fin())};
};





// iterateur
template <typename >
class MyIterator {
private:
  Stack<noeud> stack=new stack<>();
  noeud a;
  MyIterator(noeud racine){
    a=racine;
  }
public:
  noeud next(){
    while(a!=nullptr){
      stack.push(a);
      Arbre(&a);
    }
  }
  boolean Suivant(){
  return(!stack.isEmpty()||a!=null);
}
  static Iterator iterator(noeud racine){
    return new Iterator(racine);
  }
  void debut() { it = a.racine; }
  void fin() { it = a.racine[a.racine.hauteur(); }
  MyIterator(Arbre &a):noeud(a),it(a.racine){}
    // iterator class definition goes here
    typedef MyIterator<int*> iterator_type;
    typedef MyIterator<const int*> const_iterator_type;
    ~MyIterator() = default;
};


#endif /*ARBRE_H*/
