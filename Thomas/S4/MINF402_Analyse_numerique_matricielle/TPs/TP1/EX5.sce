function [X]=RESOUINF(A,b,n)
    X(1,1)=b(1,1)/A(1,1);
    for i=2:n
         aux=0;
         for k=1:i-1
             aux=aux+A(i,k)*X(k);
         end
         X(i)=(b(i)-aux)/A(i,i);
    end 
endfunction
function [Y]=RESOUSUP(A,b,n)
    Y(n,n)=b(1,n)/A(n,n);
    for i=n-1:1
         aux=0;
         for k=1:i-1
             aux=aux+A(i,k)*X(k);
         end
         X(i)=(b(i)-aux)/A(i,i);
    end 
endfunction
X=zeros(1,5);
n=5;
A=round(10*rand(n,n));
b=round(10*rand(5,1));
X=RESOUINF(A,b,n);
Y=RESOUSUP(A,b,n);
disp(X);
