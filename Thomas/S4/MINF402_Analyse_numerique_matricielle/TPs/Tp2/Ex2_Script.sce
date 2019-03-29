//Import et execution du fichier fonctions.sci
pathname = get_absolute_file_path("Ex2_Script.sce")
exec(pathname+'\fonctions.sce', -1);
//initialisation N,n
N=100;
n=100;

A=zeros(n,n);
//meme que ex0
for i=2:n-1
     A(i,i-1)=-1;
     A(i,i)=2;
     A(i,i+1)=-1;
end
A(1,1)=2;
A(1,2)=-1;
A(n,n)=2;
A(n,n-1)=-1;

J=zeros(n,1);
K=zeros(n,1);
L=zeros(n,1);

for i=2:n-1
     K(i)=A(i,i);
     L(i)=A(i,i+1);
     J(i)=A(i,i-1);
end

J(n)=A(n,n-1);
K(1)=A(1,1);
K(n)=A(n,n);
L(1)=A(1,2);

h=1/N+1;

x=zeros(n,1);
for i=1:n
    x(i)=i*h;
end

//f(x)=6x-2;

F=zeros(n,1);

for i=1:n
    F(i)=6*x(i)-2;
end

G=zeros(n,1);

for i=1:n
    G(i)=h*h*F(i);
end
disp(A,"A=");

U=RESOUTRI(J,K,L,G,n);
U=PRODUIT(J,K,L,U,n);

//U(1)=0;
//U(0)=0
//U(n+1)=0
U=[0;U;0]

x=linspace(0,1,N+2);
x=x(2:N+1);
x(1)=0;
x(n)=1;
x=x';

z=zeros(n,1);
//U(x)=x*x(1-x)
for i=1:n
    z(i)=x(i)*x(i)*(1-x(i));
end
disp(x)
disp(z)
plot(x,z);
