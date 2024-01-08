clc
clear
%Exercise 1
disp('--- Exercise 1 ---')
clear
M = [
    -2;
    1
    ];
M1 = [
    5;
    3
    ];
X = M(1) - M1(1);
Y = M(2) - M1(2);
plot(M(1),M(2),'*b')
grid on
hold on
line([-10 10],[0 0],'color','k')
line([0 0],[-10 10],'color','k')
line([X X],[-10 10],'color','r')
line([-10 10],[Y Y],'color','r')
text(M(1)+1,M(2),'M(-2;1)')
plot(X,Y,'*r')
text(X-1,Y-1,'O(-7;-2)')
xlabel('x'), ylabel('y')
title('task 1')

%Exercise 2
disp('--- Exercise 2 ---')
clear
M = [
    sqrt(2);
    sqrt(2)
    ];
a = 225;
X = M(1)*cosd(a) + M(2)*sind(a);
Y = M(2)*cosd(a) - M(1)*sind(a);
M1 =[
    X;
    Y
    ]
figure(2)
line([-10 10],[0 0],'color','k')
line([0 0],[-10 10],'color','k')
line([-10 10],[-10 10],'color','r')
line([-10 10],[10 -10],'color','r')
hold on
plot(M(1),M(2),'*b')
grid on
xlabel('x'), ylabel('y')
title('task 2')

%Exercise 3
disp('--- Exercise 3 ---')
clear
figure(3)
A = [
    1;
    1
    ];
B = [
    1;
    4
    ];
C = [ 
    6;
    1
    ];  
plot(A(1),A(2),'b*')
hold on
plot(B(1),B(2),'b*')
plot(C(1),C(2),'b*')
line([-6 8],[0 0],'color','k')
line([0 0],[-5 5],'color','k')
line(C,A,'color','b')
line(A,B,'color','b')
line(C,B,'color','b')
grid on
text(A(1)-1,A(2),'A')
text(B(1)-1,B(2),'B')
text(C(1)+1,C(2),'C')
D = [
    -4;
    -3;
    ];
A = A + D;
B = B + D;
C = C + D;
plot(A(1),A(2),'r*')
plot(B(1),B(2),'*r')
plot(C(1),C(2),'r*')
line([-3 -3],[-2 1],'color','r')
line([-3 2],[-2 -2],'color','r')
line([-3 2],[1 -2],'color','r')
text(A(1)-1,A(2),'A1')
text(B(1)-1,B(2),'B1')
text(C(1)+1,C(2),'C1')
title('task 3')

%Exercise 4
disp('--- Exercise 4 ---')
clear
figure(4)
A = [
    1;
    1
    ];
B = [
    1;
    4
    ];
C = [ 
    6;
    1
    ];  
plot(A(1),A(2),'b*')
hold on
plot(B(1),B(2),'b*')
plot(C(1),C(2),'b*')
line([-8 8],[0 0],'color','k')
line([0 0],[-8 8],'color','k')
line(C,A,'color','b')
line(A,B,'color','b')
line(C,B,'color','b')
grid on
text(A(1)-1,A(2),'A')
text(B(1)-1,B(2),'B')
text(C(1)+1,C(2),'C')
a = 90;
X = A(1)*cosd(a) + A(2)*sind(a);
Y = A(2)*cosd(a) - A(1)*sind(a);
A = [
    X;
    Y
    ];
X = B(1)*cosd(a) + B(2)*sind(a);
Y = B(2)*cosd(a) - B(1)*sind(a);
B = [
    X;
    Y
    ];
X = C(1)*cosd(a) + C(2)*sind(a);
Y = C(2)*cosd(a) - C(1)*sind(a);
C = [
    X;
    Y
    ];
plot(A(1),A(2),'r*')
plot(B(1),B(2),'*r')
plot(C(1),C(2),'r*')
line([1 4],[-1 -1],'color','r')
line([1 1],[-6 -1],'color','r')
line([1 4],[-6 -1],'color','r')
text(A(1)-1,A(2),'A1')
text(B(1)+1,B(2),'B1')
text(C(1)+1,C(2),'C1')
axis;
title('task 4')