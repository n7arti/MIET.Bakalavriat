%Exercise 1
A = [
    1 2 3 4;
    5 6 7 8;
    9 2 4 5;
 ];
C = [
    1 4 5 7 8;
    4 6 7 3 2;
    4 1 2 3 9;
    1 1 4 7 3;
 ];
D = [
    1 1 4;
    3 3 6;
    2 7 8;
 ];
B = [
    1 1 1 1;
    1 1 1 1;
    1 1 1 1;
 ];

%task a

whos A B C D

%task b

A + B
A * C
%(A - B) * D

%task c

A(1,:) = 5

%task d

C(:,3) = -2 * C(:,3)

%task e

D.* D.* D

%Exercize 2

help magic

%task a

a = magic(5)
sum(diag(fliplr(a)))
sum(diag(a))
sum(a(1,:))
sum(a(2,:))
sum(a(3,:))
sum(a(4,:))
sum(a(5,:))
sum(a(:,1))
sum(a(:,2))
sum(a(:,3))
sum(a(:,4))
sum(a(:,5))

%task b

min(a)
max(a)

%Exercize 3
%task a

syms x
f = cos(x)^2 - sin (x)^2
simplify(f)

%task b

syms y
g = cos(x + y)
expand(g)

%task c

m =(x - 1) * sin(x) + (x + 2) * sin(x) + x^2
collect(m)

%task d

n = 126
h = factor (n)
prod(h)

%Exercize 4
%task a

hold on
grid on
A = [1; 2]
B = [4; 6]
C = [8; 3]
quiver(A(1,1), A(2,1), B(1,1) - A(1,1), B(2,1) - A(2,1))
quiver(A(1,1), A(2,1), C(1,1) - A(1,1), C(2,1) - A(2,1)) 
AB = [
B(1,1) -A(1,1);
B(2,1) -A(2,1)
]
AC = [
C(1,1) -A(1,1);
C(2,1) -A(2,1)
]
D = AB + AC
quiver(A(1,1), A(2,1), D(1,1)-A(1,1), D(2,1)-A(2,1))

%task b

figure(2)
hold on
grid on
x = [0:0.01:2]
y1 = log (x)
y2 = sin (2*x)
plot(x,y1,'r--')
plot(x,y2,'m*')