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
template<class T>class arbreIterator;

//classe Arbre
template<class T>
class Arbre{
  friend class arbreIterator<T>;
protected:
  Noeud *racine;
  typedef Noeud NoeudArbre[100];
  NoeudArbre noeuds;

public:
  Arbre();                                                                      //Par défaut
  Arbre(Noeud *n);                                                              //Par init par noeud
  Arbre(size_t taille);                                                         //Par init par taille
  Arbre(const Arbre& a);                                                        //Par copie
  Arbre(Arbre&& a);                                                             //Par déplacement
  Arbre(const initializer_list<Noeud> &liste);                                  //Par liste
  //Arbre(arbreIterator a);                                                           //Par Range
  //Opérateurs
  Arbre& operator=(const Arbre& a);//Assignation par copie
  typedef noeud * iterator;
  typedef const noeud * const_iterator;
  iterator begin(){return &noeuds[0];}
  iterator end() {return &noeuds[100];}

};



  // friend class arbreIterator<T>;
  // typedef arbreIterator< T >  arbreIterator;
  // typedef arbreIterator< const T >  const_iterator;

  arbreIterator arbreIterator<T>::begin(){
    return (arbreIterator(this.racine);
  }

  arbreIterator arbreIterator<T>::end(){
    return ( arbreIterator(nullptr);
  }
  arbreIterator arbreIterator<T>::here(int n){
    return (arbreIterator(this.racine+n);
  }
  const arbreIterator arbreIterator<T>::begin(){
    return (const arbreIterator(this.racine);
  }

  const arbreIterator arbreIterator<T>::end(){
    return (const arbreIterator(nullptr));
  }
  const arbreIterator arbreIterator<T>::here(int n){
    return (const arbreIterator(this.racine+n);
  }
  template <class T>
  class arbreIterator
  //:public std::iterator<std::random_access_iterator_tag,T>
  {
  private:
    Noeud *n;
    arbreIterator(Noeud *p)::n(p){};
  public:
    arbreIterator(){n=nullptr};
    arbreIterator(const arbreIterator &n):n(it.n){};
    ~arbreIterator(){};
    arbreIterator &operator(const arbreIterator &n){
      n=it.n;
      return *this;
    }
    arbreIterator &operator+(){
      return this.n;
    }
    const T&operator*(){
      return *this;
    }
    bool operator!=(const arbreIterator &it)const{
      return(it.n!=n);
    }
    friend class Arbre;
};




#endif /*ARBRE_H*/
