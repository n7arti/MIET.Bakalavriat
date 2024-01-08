clc
%Exercise 1.1
disp('--- Exercise 1.1 ---')
clear
n = 5;
A=fix(rand(n,n)*10)
f=fix(rand(n,1)*10)
if det(A) ~= 0
    X = inv(A)*f;
else
    disp('Матрица вырожденная, поэтому нельзя использовать метод X = A^(-1)f')
end
X
%%
clc
%Exercise 1.2
disp('--- Exercise 1.2 ---')
clear
n = 5;
A=fix(rand(n,n)*10)
f=fix(rand(n,1)*10)
for i=1:n
    A1=A;
    A1(:,i)=f;
    X(i,1)=det(A1)/det(A);
end
X
%%
clc
%Exercise 2
disp('--- Exercise 2 ---')
clear
n = 5;
A=fix(rand(n,n)*10)
f=fix(rand(n,1)*10)

for j = 1:n
    a =0;
    for i = j:n
        if a<A(i,j)
           a = A(i,j);
           m = i;
        end
    end
    S1 = A(j,:);
    A(j,:) = A(m,:);
    A(m,:) = S1;
    f1 = f(j,:);
    f(j,:) = f(m,:);
    f(m,:) = f1;
    for i=j+1:n
        if A(i,j) ==0
            M(j) = 0;
        else
        M(j) = A(i,j)/A(j,j);
        end
        A(i,:) = A(i,:) - M(j)*A(j,:);
        f(i,:) = f(i,:) - M(j)*f(j,:);
    end
end
A
f
%%
clc
%Exercise 3
disp('--- Exercise 3 ---')
clear
n = 5;
A=fix(rand(n,n)*10)
f=fix(rand(n,1)*10)
rref([A f])
X= A\f
%%
clc
%Exercise 4
disp('--- Exercise 4 ---')
clear
n = 20
k = 5;
A=rand(n,n)+k
X=rand(n,1)

f=A*X
if det(A) ~= 0
    X1 = inv(A)*f;
else
    disp('Матрица вырожденная, поэтому нельзя использовать метод X = A^(-1)f')
end
X1
for i=1:n
    A1=A;
    A1(:,i)=f;
    X2(i,1)=det(A1)/det(A);
end
X2
X3 = rref ([A f]);
X3 = X3(:,n+1)
X4=A\f
S = A;
F = f;
for j = 1:n
    a =0;
    for i = j:n
        if a<S(i,j)
           a = S(i,j);
           m = i;
        end
    end
    S1 = S(j,:);
    S(j,:) = S(m,:);
    S(m,:) = S1;
    f1 = F(j,:);
    F(j,:) = F(m,:);
    F(m,:) = f1;
    for i=j+1:n
        if S(i,j) ==0
            M(j) = 0;
        else
        M(j) = S(i,j)/S(j,j);
        end
        S(i,:) = S(i,:) - M(j)*S(j,:);
        F(i,:) = F(i,:) - M(j)*F(j,:);
    end
end
X5=S\F
cond(A)  