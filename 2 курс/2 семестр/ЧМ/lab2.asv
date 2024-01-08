clc
%Exercise 1
disp('--- Exercise 1 ---')
clear
x=[-10:10];
y = x.^3-3.*x.^2-9.*x-5;
grid on; hold on;
plot(x,y)
y1=[-1500;1000];
x1=[-1.7;-1.7];
x2=[-0.4;-0.4];
x3=[4.9;4.9];
x4=[5.1;5.1];
plot(x1,y1,'r')
plot(x2,y1,'r')
plot(x3,y1,'r')
plot(x4,y1,'r')
p = [1 -3 -9 -5];
roots(p)
%%
clc
%Exercise 2
disp('--- Exercise 2 ---')
clear
syms x
f=@(x) x^3-3*x^2-9*x-5;
a=4.9999;
b=5.0001;
eps=0.01;
i =1;
c = (b+a)/2;
if sign(f(b)) ~= sign(f(a))
    while abs(a-b) > eps
        c = (b+a)/2;
        i = i+1;
        if sign(f(c)) == sign(f(a))
            a = c;
        else
            b = c;
        end
    end
    disp(sprintf('Корень: %d',c))
    disp(sprintf('Количество итераций: %d',i))
else
   disp('Функция на концах отрезка не различается по знаку. Используйте другой отрезок.') 
end
%%
clc
%Exercise 3
disp('--- Exercise 3 ---')
clear
syms x;
f=@(x)(sin(x) -x/2);
f1=diff(f,x,1);
a = 1;
b = 2;
i = 1;
eps = 0.0001;
xn = (a+b)/2;
while abs(subs(f,x,xn))>eps
    xn = xn - subs(f,x,xn)/subs(f1,x,xn);
    i = i+1
end
disp(sprintf('Корень: %d',xn))
disp(sprintf('Количество итераций: %d',i))
%%
clc
%Exercise 4
disp('--- Exercise 4 ---')
clear
syms x
f=@(x)(sin(x) -x/2);
f1=diff(f,x,1);
a = 1;
b = 2;
i = 1;
eps = 0.0001;
xn = (a+b)/2;
xn1 = xn - subs(f,x,xn)/subs(f1,x,xn);
while abs(subs(f,x,xn1))>eps
    t = xn1;
    xn1 = xn1 - (subs(f,x,xn1)*(xn1 - xn))/(subs(f,x,xn1) - subs(f,x,xn));
    xn = t;
    i = i+1;
end
disp(sprintf('Корень: %d',xn))
disp(sprintf('Количество итераций: %d',i))
%%
clc
%Exercise 5
disp('--- Exercise 5 ---')
clear
syms x
a = 9;
eps = 0.0001;
x0 = 0.1;
x1 = (1/2*(a/x0 + x0));
while abs(x1-x0)>eps
    x0 = x1;
    x1 = (1/2*(a/x1 + x1));
end
x1
%%
clc
%Exercise 6
disp('--- Exercise 6 ---')
clear
x = [-10:10];
y = 2.*x + 1;
plot(x,y)
grid on; hold on;
plot([-10,10],[1,1],'r')
syms x
a = 9;
eps = 0.0001;
x0 = 0;
x1 = (x0^2 + x0 -a);
while abs(x1-x0)>eps
    x0 = x1;
    x1 = (x1^2 + x1 -a);
end
x1

%%
clc
%Exercise 7
disp('--- Exercise 7 ---')
clear
syms x
x = [-4*pi:4*pi];
y = sin(x) +1;
plot(x,y)
grid on
f = sin(x) +1;
fzero(@(x) sin(x) +1,[-5,0])
%%
clc
%Exercise 8
disp('--- Exercise 8 ---')
clear
x = [-10:10];
y = sin(x) -x/2;
plot(x,y)
grid on; hold on;
plot([-10,10],[0,0],'r')
syms x
diff(2*sin(x),x,1)