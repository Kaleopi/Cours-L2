//Import et execution du fichier fonctions
pathname = get_absolute_file_path("Ex0_Script.sce")
exec(pathname+'\fonctions.sce', -1);
//initialisation n=3
n=3
//Création d'une MAtrice radom
A=round(rand(n,n)*10+1);
//affichage
disp(A,"¨Matrice A")
//appelle de la fonction MAGIQUE
Z=MAGIQUE(A);
//Création de la matrice inverse de A
Y=inv(A)
//Preuve MAGIQUE crée la matrice inverse de A donc Y doit être égale à Z
disp(Y-Z,"preuve:")
