//Import et execution du fichier fonctions.sci
pathname = get_absolute_file_path("Ex7_Script.sce")
exec(pathname+'fonctions.sce', -1);
//même que ex2 ^^
n=6;

disp("Resolution matrice tridiagonal : MX=D (M étant composé des diagonales A, B et C");

A=zeros(n,1);
B=zeros(n,1);
C=zeros(n,1);
X=zeros(n,1);
D=zeros(n,1);
M=zeros(n,n);
Y=zeros(n,1);

A=round(rand(n,1)*10+1);
B=round(rand(n,1)*10+20);
C=round(rand(n,1)*10+1);
D=round(rand(n,1)*10+1);


for i=2:n-1
     M(i,i)=B(i);
     M(i,i+1)=C(i);
     M(i,i-1)=A(i); 
end

X=RESOUTRI(A,B,C,D,n);

Y=PRODUIT(A,B,C,X,n);

disp(D,"D=",C,"C=",B,"B=",A,"A=");
disp(M,"Matrice M=");
disp(X,"X=");
disp(Y,"Y (Resultat de MATRICIELLE=");
disp(M*X,"MX = ","Preuve :");
disp(M*X-Y,"reel preuve:")
// M*X-Y


