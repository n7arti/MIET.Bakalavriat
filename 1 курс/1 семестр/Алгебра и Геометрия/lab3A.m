clc
clear
%Exercise 1
disp('--- Exercise 1 ---')
clear
A = [
    1/sqrt(2) 3;
    2 -3*sqrt(2);
    ];
B = [
    4;
    -sqrt(2);
    ];
A1 = A;
A2 = A;
A1(:,1) = B;
A2(:,2) = B;
x = det(A1)/det(A);
y = det(A2)/det(A);
C = [
    x;
    y;
    ];
A*C
B
x1 = [-10:0.1:10];
y1 = (4-x1/sqrt(2))./3;
plot(x1,y1,'g')
hold on
y2 =( - sqrt(2) - 2*x1)./(-3*sqrt(2));
plot(x1,y2)
plot(x,y,'r*')
grid on
xlabel('x'),ylabel('y')

%Exercise 2
disp('--- Exercise 2 ---')
clear
A = [
    1/sqrt(2) 3;
    2 3*sqrt(2);
    ];
B = [
    4;
    -sqrt(2);
    ];
C = A^-1 * B

%Exercise 3
disp('--- Exercise 3 ---')
clear
a = [
    12;
    -8;
    6;
    ];
b = [
    -10;
    -7;
    5;
    ];
c = [
    44;
    -5;
    -13;
    ];
d = [
    10;
    10;
    10;
    ];
F = zeros(3);
F(:,1) = a;
F(:,2) = b;
F(:,3) = c;
det(F)
K = F^-1 * d
F*K

%Exercise 4
disp('--- Exercise 4 ---')
clear
A = [
    1;
    2;
    0;
    ];
B = [
    3;
    2;
    1;
    ];
C = [
    -2;
    1;
    2;
    ];
AB1 = B - A
AC1 = C - A
AB = norm(AB1);
AC = norm(AC1);
sin = sin(dot(AB23,AC23));
h = dot(AB,AC)
S = AB * AC * sin/2
s1 = cross(AB1,AC1)/2;
s2 = norm(s1)

%Exercise 5
disp('--- Exercise 5 ---')
clear
A = [
    7;
    2;
    4;
    ];
B = [
    7;
    -1;
    -2;
    ];
C = [
    3;
    3;
    1;
    ];
D = [
    -4;
    2;
    1;
    ];
AB = B - A;
AC = C - A;
AD = D - A;
F = zeros(3);
F(:,1) = AB;
F(:,2) = AC;
F(:,3) = AD;
V = 1/6*abs(det(F))