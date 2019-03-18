//Piles
#include "Piles.h"
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

typedef struct element_pile{
    int val;
    struct element_pile * prec;

};ELEMENT_PILE;

typedef struct Pile{
  ELEMENT_PILE *premier;
}PILE;

PILE *ma_pile;
//créer
PILE *CreerPile(){
  PILE *pile=malloc(sizeof(PILE));
  pile->premier=NULL;
}
/*
ajouter une élements dans la Piles
  1: Créer le nouvel élément
  2:Verifie si l'élément à été Créer
  3: On assigne à la donnée l'élément
  4:On fait pointé l'élément sur le sommet de la PILE
  3:On fait pointé sommet de pile sur l'element_pile*/

  void empiler(PILE *p_pile,int val){
      ELEMENT_PILE *p_nouv_element=malloc(sizeof(ELEMENT_PILE));
      if(p_nouv_element!=NULL){
        p_nouv_element->val=val;
        p_nouv_element->prec=p_pile_premier;
        p_pile->premier=p_nouv_element;
        //sommet de pile pointe sur le nouvelle élément
      }
  }
/* Retiré un élément de PILE
  1:Vérifier si la pile n'est pas tester_pile_vide
  2:si elle ne l'est pas ,stocker dans un éléments temporaire l'avant dernier eleme de la PILE
  3:Stocker dans une variable locale la valeur étant stockés dans la PILE
  4:Supprimer le dernier éléments
  5:Faire pointer vers l'élzment temporaire
  6:Retourner la valeur dépiler*/
  ind depiler(PILE *p_pile){
    int retour=-1;
    if (p_pile->premier!=NULL){
      ELEMENT_PILE *temporaire=p_pile->premier->prec;
      retour=p_pile->premier->val;
      free(p_pile->premier);
      p_pile->premier=temporaire;
      //sommet pointe sur précèdant
    }
    return retour;
  }
  /*Efacer une PILE
  1:Tant que pile non tester_pile_vide
  2:Effacer le dernier élements de la pile
  */
  void vider_pile(PILE *p_pile){
    while(p_pile->premier!=NULL){
      depiler(p_pile);
    }
  }
  /*retourne la valeur sommet de la PILE
  si pile vide retourne -1*/
  int sommet_pile(PILE *p_pile){
    int retour =-1;
    if(p_pile->premier!=NULL){
      retour = p_pile->premier->val; /*On stocke dans la variable retour la velur du sommet de la pile (dernier élément empilé)*/
  }
return retour;
}

/*Chercher si une valeur est présente dans une pile
Retourne 1 si la valeur est trouvée, 0 sinon*/
int chercher_dans_pile(PILE *p_pile  int val){
  ELEMENT_PILE *p_element;
  if(p_pile->premier == NULL){
    return 0;
  }
  p_element = p_pile->premier;
  while(p_element!=NULL){
    if(p_element->val == val){
      return 1;
    }
    p_element = p_element->prec;
  }
  return 0;
}

/*
Tester si une pile est vide
*/
int tester_pile_vide(PILE *p_pile){
  if(p_pile->premier == NULL){
    return 1;
  }
  return 0;
}

/*
Afficher à l'écran le contenu d'une pile
*/
void afficher_pile(PILE *p_pile){
  if(p_pile->premier == NULL){
    printf("Pile vide !");
    return;
  }
  // Parcourir la pile du dernier élément (sommet) au premier
  ELEMENT_PILE *p_element;
  p_element = p_pile->premier;
  printf("\nContenu de la pile : ");
  while(p_element!=NULL){
    printf("%d",p_element->val);
    p_element = p_element->prec;
  }
  printtf("\n");
}

/*
Empiler des éléments saisis au clavier.
Les valeurs saisies doivent êtres positives ou nulles.
Dès qu'une valeur saisie est négative, la saisie est terminée.
*/
void saisie_elements_pile(PILE *p_pile){
  int val;
  while(1){
    printf("Veuillez saisir une valeur >=0 (fin = valeur négative) : ");
    scanf("%d",val);
    if(val<0)return;
    empiler(p_pile,val);
  }
}

main(){
  int val;
  //Créer pile
  ma_pile = creer_pile();

  //remplir la pile
  saisie_elements_pile(ma_pile);

  //afficher le contenu de la pile avant de jouer avec
  afficher_pile(ma_pile);

  //valeur sommet pile
  val = sommet_pile(ma_pile);
  printf("\nSommet de la pile : %d\n",val);

  //boucle d'affichage pile et dépilement d'un élément par itération
  while(ma_pile->premier !=NULL){
    afficher_pile(ma_pile);
    depiler(ma_pile);
  }

  printf("\n\nFin du programme.\n\n");
}
