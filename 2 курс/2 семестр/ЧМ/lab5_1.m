clc
clear all
A = 0;
B = 1;
f =@(x) 1/(1+x*x);
N = 10;
x = linspace(A,B,N);
S = 0;
for i = 2 : N
    S = S + (f(x(i)) +  f(x(i - 1))) * 0.5 * (x(i) - x(i-1));
end
Errh = 4*S - pi
N = 20;
x = linspace(A,B,N);
S1 = 0;
for i = 2 : N
    S1 = S1 + (f(x(i)) +  f(x(i - 1))) * 0.5 * (x(i) - x(i-1));
end
err05h = 4*S1 - pi
errrug = 4*(S + (S1-S)*4/3) - pi