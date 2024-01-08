clc
%Exercise 1
disp('--- Exercise 1 ---')
clear
syms x
h=0.5; 
R=1; 
while abs(R)>10^(-6)
    f=log(x);
    xi= 1;
    df=(subs(f,x,xi)-subs(f,x,xi-h))/h; 
    i=xi-h:10^(-6):xi;
    diff_f = diff(f,x,2);
    R=subs(diff_f,x,i)*h/2;
    R=max(R);
    h=h/2;
end
disp(sprintf('Шаг h: %d', h*2)) 
disp(sprintf('Значение производной в x: %d', df)) 
disp(sprintf('Погрешность: %d', R))
%%
clc
%Exercise 2
disp('--- Exercise 2 ---')
clear
syms x
h=1/2;
R1=[];
R2=[];
OR1=[];
OR2=[];
j=1;
while h>1/1024
    f=log(x);
    xi=1;
    df1=(subs(f,x,xi)-subs(f,x,xi-h))/h; 
    i=xi-h:10^(-3):xi;
    diff_f1 = diff(f,x,2);
    R=subs(diff_f1,x,i)*h/2;
    R1(j)= max(R);
   
    df2=(subs(f,x,xi+h)-subs(f,x,xi-h))/(2*h);
    i=xi-h:10^(-3):xi+h;
    diff_f2 = diff(f,x,3);
    R=subs(diff_f2,x,i)*h^2/6;
    R2(j)= max(R);

    if j==1
        O1=abs(R1(j));
        O2=abs(R2(j));
    end
    disp(sprintf('Шаг h: %d', h)) 
    disp(sprintf('(1)Значение производной в x: %d', df1)) 
    disp(sprintf('(2)Значение производной в x: %d', df2)) 

    h=h/2;
    j=j+1;
end
j=j-1;
OR1(1)=O1;
for i=2:j
    OR1(i)=OR1(i-1)/2;
end
OR2(1)=O2;
for i=2:j
    OR2(i)=OR2(i-1)/4
end
 
i=1:j;
hold on
grid on
plot(i,abs(R1),'r')
plot(i,OR1,'g')
plot(i,R2,'b')
plot(i,OR2,'k')
 
R1=abs(R1);
disp(sprintf('Практическая погрешность для О(h): %d', R1))
disp(sprintf('Практическая погрешность для О(h^2): %d', R2))
 
OR1=OR1;
disp(sprintf('Теоретическая погрешность для О(h): %d', OR1))
OR2=OR2;
disp(sprintf('Теоретическая погрешность для О(h^2): %d',OR2))
for i=1:j-1
    disp(sprintf('Деление h/(h/2) для О(h): %d', OR1(i)/OR1(i+1)))
end
for i=1:j-1
    disp(sprintf('Деление h/(h/2) для О(h^2): %d', OR2(i)/OR2(i+1)))
end
%%
clc
%Exercise 3
disp('--- Exercise 3 ---')
clear
syms x
h=1/2;
R=[];
i=1;
O=[];
while h>1/(2^55)
    f=log(x);
    xi=1;
    df=(subs(f,x,xi+h)-subs(f,x,xi-h))/(2*h);
    j=xi-h:10^(-3):xi+h;
    diff_f = diff(f,x,3);
    R=subs(diff_f,x,j)*h^2/6;
    R(i)= max(R);
    if i==1
        O1=abs(R(i))
    end
    O(i)=abs(subs(diff(f),'x',xi)-df);
        disp(sprintf('Шаг h: %d', h)) 
    disp(sprintf('Значение производной в x: %d', df)) 
    h=h/2;
    i=i+1;
end
k=i-1;
 
OR(1)=O1;
for i=2:1:k
    OR(i)=OR(i-1)/2^2;
end
disp('Практическая погрешность: ')
O
disp('Теоретическая погрешность для: ')
OR

i=1:1:k;
hold on
grid on
plot(i,log(abs(O)),'r')
plot(i,log(abs(OR)),'blue')
xlabel('Kolichestvo shagov') 
ylabel('Pogreshnost')

%%


