clc
%Exercise 1
disp('--- Exercise 1 ---')
clear
f=@(t)sin(pi*t);
i=0:4;
ti=i./4;
fi=f(ti);

x1=[0, 1/6, 1/3, 1/2];
y1=zeros(size(x1));
y2=zeros(size(x1));
for j=1:4
    x = x1(j);
    y2(j)=f(x1(j));
    for i=1:3
        if x>=ti(i)&& x<=ti(i+1)
            y1(j) =fi(i)+(fi(i+1)-fi(i))*(x-ti(i))/(ti(i+1)-ti(i));
        end
    end
end
hold on; grid on;
for i = 1:3
    line([x1(i);x1(i+1)],[y1(i);y1(i+1)],'Color','blue');
    line([1/2+x1(i);1/2+x1(i+1)],[y1(5-i);y1(5-i-1)],'Color','blue');
end

fplot(f, [0 1], 'r');
plot(ti, fi, 'g*');
xlabel('X') 
ylabel('Y')
disp('Реальные значения:')
y2
disp('Значения интерполированной функции:')
y1
%%
clc
%Exercise 2.1
disp('--- Exercise 2.1 ---')
clear
f=@(t)sin(pi*t);
i=0:4;
ti=i./4;
fi=f(ti);

x1=[0, 1/6, 1/3, 1/2];
y1=zeros(size(x1));
y2=zeros(size(x1));
for i=1:4
    x = x1(i);
    y2(i)=f(x1(i));
    l1 = (x-ti(2))*(x-ti(3))*(x-ti(4))/((ti(1)-ti(2))*(ti(1)-ti(3))*(ti(1)-ti(4)));
    l2 = (x-ti(1))*(x-ti(3))*(x-ti(4))/((ti(2)-ti(1))*(ti(2)-ti(3))*(ti(2)-ti(4)));
    l3 = (x-ti(1))*(x-ti(2))*(x-ti(4))/((ti(3)-ti(1))*(ti(3)-ti(2))*(ti(3)-ti(4)));
    l4 = (x-ti(1))*(x-ti(2))*(x-ti(3))/((ti(4)-ti(1))*(ti(4)-ti(2))*(ti(4)-ti(3)));
    y1(i)= fi(1)*l1 +fi(2)*l2 + fi(3)*l3 + fi(4)*l4; 
end
hold on; grid on;
for i = 1:3
    line([x1(i);x1(i+1)],[y1(i);y1(i+1)],'Color','blue');
    line([1/2+x1(i);1/2+x1(i+1)],[y1(5-i);y1(5-i-1)],'Color','blue');
end
fplot(f, [0 1], 'r');
plot(ti, fi, 'g*');
xlabel('X') 
ylabel('Y')
disp('Реальные значения:')
y2
disp('Значения интерполированной функции с помощью метода Лагранжа:')
y1
%%
clc
%Exercise 2.2
disp('--- Exercise 2.2 ---')
clear
f=@(t)sin(pi*t);
i=0:4;
ti=i./4;
fi=f(ti);

x1=[0, 1/6, 1/3, 1/2];
y1=zeros(size(x1));
y2=zeros(size(x1));
for i=1:4
    x = x1(i);
    y2(i)=f(x1(i));
    A1 = fi(1);
    A2 = (fi(2)-A1)/(ti(2)-ti(1));
    A3 = (fi(3)-A1 - A2*(ti(3)-ti(1)))/((ti(3)-ti(1))*(ti(3)-ti(2)));
    A4 = (fi(4)-A1 - A2*(ti(4)-ti(1))-A3*(ti(4)-ti(1))*(ti(4)-ti(2)))/((ti(4)-ti(1))*(ti(4)-ti(2))*(ti(4)-ti(3)));
    y1(i) = A1 + A2*(x-ti(1)) + A3*(x-ti(1))*(x-ti(2)) + A4*(x-ti(1))*(x-ti(2))*(x-ti(3));
end
hold on; grid on;
for i = 1:3
    line([x1(i);x1(i+1)],[y1(i);y1(i+1)],'Color','blue');
    line([1/2+x1(i);1/2+x1(i+1)],[y1(5-i);y1(5-i-1)],'Color','blue');
end
fplot(f, [0 1], 'r');
plot(ti, fi, 'g*');
xlabel('X') 
ylabel('Y')
disp('Реальные значения:')
y2
disp('Значения интерполированной функции с помощью метода Лагранжа:')
y1
o=max(abs(sin(x1)-y1));
disp(sprintf('Максимальная эксперементальная погрешность: %d',o))
syms x
t = ti.*pi;
[x0,M]=fminbnd(@(x)-abs(cos(x)),0,pi);
Rx=-M/factorial(5)*prod(x-t);
O=max(subs(Rx,x1));
disp(sprintf('Максимальная теоретическая погрешность: %d',O))
%%
clc
%Exercise 3.1
disp('--- Exercise 3.1 ---')
clear
syms x
x1=[2];
f=@(t)sin(pi*t);
i=0:4;
ti=i./4;
fi=f(ti);
t=ti.*pi;
L=0;
for i=1:5
t1=t;
t1(i)=[];
L=L+fi(i)*prod(x-t1)/prod(t(i)-t1);
end
L=simple(L);
y=subs(L,x1);
disp('Многочлен Лагранжа: ')
L
disp('Значение многочлена Лагранжа в заданных точках: ')
y
sin(2*pi)
%%
clc
%Exercise 3.2
disp('--- Exercise 3.2 ---')
clear
syms x
x1=[2];
f=@(t)sin(pi*t);
i=0:4;
ti=i./4;
fi=f(ti);
t=ti.*pi;
for i=1:5
    B(i,1)=1;
    if i>1
        for j=1:i-1
            B(i,j+1)=prod(t(i)-t(1:j));
        end
    end
end
A=B/fi;
P=A(1);
for i=2:5;
    P=P+A(i)*prod(x-t(1:i-1));
end
P=simple(P);
y=subs(P,x1);
disp('Многочлен Ньютона: ')
P
disp('Значение многочлена Ньютона в заданных точках: ')
y
%%
clc
%Exercise 4
disp('--- Exercise 4 ---')
clear
for i=1:10
    t(i) = 5*cos(pi*(2*i-1)/(2*10))
end
x1 = 4.5;
syms x
g=1/(1+25*x^2);
f=subs(g,t);
L=0;
for i=1:10
t1=t;
t1(i)=[];
L=L+f(i)*prod(x-t1)/prod(t(i)-t1);
end
L=simple(L);
h=ezplot(L,[-5 5]);
set(h,'Color','green')
hold on;grid on
ezplot(g,[-5 5])
ylim([-0.1 1])
y=subs(L,x1)
xlabel('x');
ylabel('y');
%%
clc
%Exercise dop1
disp('--- Exercise dop1 ---')
clear
f=@(t)sin(pi*t);
i=0:4;
ti=i./4;
fi=f(ti);
interp_f=@(x)(interp1(ti,fi,x));
x1=[0, 1/6, 1/3, 1/2];
y=zeros(size(x1));
for i=1:4
y(i)=interp_f(x1(i))
end
hold on; grid on;
fplot(interp_f, [0 1], 'b');
%%
clc
%Exercise dop2
disp('--- Exercise dop2 ---')
clear
f=@(t) (1/(1+25*t^2));
ti=-5:5;
fi=subs(f,ti);
interp_f=@(x)(interp1(ti,fi,x));
x1=[4.5];
y=zeros(size(x1));
y(1)=interp_f(x1(1))
hold on; grid on;
fplot(interp_f, [-5 5], 'b');