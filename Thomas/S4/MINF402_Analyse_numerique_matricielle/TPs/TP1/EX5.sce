function [X]=RESOUINF(A,b,n)
    X=zeros(b);
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
    Y=zeros(b);

    Y(n,1)=b(n,1)/A(n,n);
    for i=n-1:-1:1
         aux=0;
         for k=i+1:n
             aux=aux+A(i,k)*Y(k);
         end
         Y(i)=(b(i)-aux)/A(i,i);
    end
endfunction
function [A,b]=REDUC(A,b,n)

    for k=1:n-1
        for i=k+1:n
            aux=A(i,k)/A(k,k)
            for j=k+1:n
                A(i,j)=A(i,j)-aux*A(k,j)
    end
         A(i,k)=0;
    b(i)=b(i)-aux*b(k);

end

end



endfunction

n=5;
A=round(10*rand(n,n));
b=round(10*rand(5,1));
X=RESOUINF(A,b,n);
Y=RESOUSUP(A,b,n);
<<<<<<< HEAD
=======
X=RESOUINF(A,b,n);
Y=RESOUSUP(A,b,n);
>>>>>>> ba36c65f6b3d428dce083cf8c53bbec902c0c96e
=======
>>>>>>> ba36c65f6b3d428dce083cf8c53bbec902c0c96e
disp(X);
C=E*X-b;
disp(C);
F=D*Y-b;
disp(F);
[U,b]=REDUC(A,Y,n);
disp(U);
K=RESOUSUP(U,b,n)
