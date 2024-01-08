clc
clear
%Exercise 1
disp('--- Exercise 1 ---')
clear
A = [
    2;
    -3;
    1;
    ];
B = [
    0;
    -11;
    3;
    ];
C = [
    4;
    5;
    -1;
    ];
AB = B - A;
AC = C - A;
h = dot(AB,AC)/(norm(AB)*norm(AC)) %cos = -1,следовательною, векторы коллинеарны
disp('(x - 4)/-2 = (y - 5)/-8 = (z + 1)/2') %уравнение пр€мой
line([0 4],[-11 5],[3 -1],'color','b')
grid on
hold on
line([-15 0 0;15 0 0],[0 -15 0;0 15 0],[0 0 -15;0 0 15],'color','k')
plot3(2,-3,1,'r*')
plot3(0,-11,3,'r*')
plot3(4,5,-1,'r*')
text(3,-3,1,'A(2,-3,1)')
text(1,-11,3,'B(0,-11,3)')
text(5,5,-1,'C(4,5,-1)')
xlabel('x'),ylabel('y'),zlabel('z')
title('(x - 4)/-2 = (y - 5)/-8 = (z + 1)/2')

%Exercise 2
disp('--- Exercise 2 ---')
clear
MN = [
    1;
    -1;
    -3;
    ];
N = [
    2;
    -8;
    -1;
    ];
M = N - MN;
D = -MN(1)*M(1)-MN(2)*M(2)-MN(3)*M(3);
disp('x - y - 3z -2 = 0')
figure(2)
A = 1;
B = -1;
C = -3;
D = -2;
x = -5:0.5:5;
y = -5:0.5:5;
[X,Y] = meshgrid(x,y);
Z = (-A*X-B*Y-D)/C;
hold on
plot3(X,Y,Z,'or','MarkerSize',8, 'LineWidth',2)
grid on
xlabel('x'), ylabel('y'), zlabel('z')
title('x - y - 3z -2 = 0')
surf(X,Y,Z)
view(-65,31)

%Exercise 3
disp('--- Exercise 3 ---')
clear
figure(3)
A1 = 2;
B1 = 3;
C1 = -4;
D1 = 4;
A2 = 5;
B2 = -2;
C2 = 1;
D2 = -3;
cos = abs(A1*A2 + B1*B2 + C1*C2)/(sqrt(A1^2 + B1^2 + C1^2)*sqrt(A2^2 + B2^2 + C2^2));
a = acosd(cos)
x = -5:0.5:5;
y = -5:0.5:5;
[X,Y] = meshgrid(x,y);
Z1 = (-A1*X-B1*Y-D1)/C1;
Z2 = (-A2*X-B2*Y-D2)/C2;
hold on
plot3(X,Y,Z1,'r','MarkerSize',8, 'LineWidth',2)
plot3(X,Y,Z2,'b','MarkerSize',8, 'LineWidth',2)
grid on
xlabel('x'), ylabel('y'), zlabel('z')
title('2x + 3y -4z +4 = 0 and 5x - 3y + z -3 = 0')
surf(X,Y,Z1)
surf(X,Y,Z2)
view(40,5)

%Exercise 4
disp('--- Exercise 4 ---')
clear
figure(4)
n1 =[
    1;
    -1;
    4
    ];
n2 = [
    2;
    1;
    -1
    ];
n = [
    3;
    -1;
    6
    ];
p = cross(n1,n2);
dot(p,n)% p перпендикул€рно n, следовательно L||a
A = 3;
B = -1;
C = 6;
D = 12;
x = -5:0.5:5;
y = -5:0.5:5;
[X,Y] = meshgrid(x,y);
Z = (-A*X-B*Y-D)/C;
hold on
plot3(X,Y,Z,'r','MarkerSize',8, 'LineWidth',2)
grid on
xlabel('x'), ylabel('y'), zlabel('z')
title('3x - y + 6z -12 = 0')
surf(X,Y,Z)
view(-60,30)
line([1 0],[-5 -2],[0 1],'color','b','LineWidth',2)