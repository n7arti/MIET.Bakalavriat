clc
%Exercise 1
disp('--- Exercise 1 ---')
clear
f = @(x,y) x^2;
h = 0.1;
x = 0:h:1;
y(1) = 1;
for i=1:10
    y(i+1) = y(i) + f(x(i),y(i))*h;
end
hold on; grid on;
plot(x,y,'r')
f1 = @(x,y) x^3/3 +1;
fplot(f1,[0 1])
%%
clc
%Exercise 2
disp('--- Exercise 2 ---')
clear
oscil=@(t, Y) [Y(2);-2*Y(2)-10*Y(1)+sin(t)];
Y0 = [1;0];
[T Y]=ode45(oscil, [0 15], Y0);
[T1 Y1]=ode23(oscil, [0 15], Y0);
C1=87/85;
C2 = 26/85;
F1=@(t)(exp(-t)*(C1*cos(3*t)+C2*sin(3*t))+(1/85)*(9*sin(t)-2*cos(t)));
hold on; grid on
fplot(F1, [0 15])
plot(T, Y, 'r')
axis([0 15 -0.4 1])
plot(T1, Y1, 'g')
%%
clc
%Exercise 3
disp('--- Exercise 3 ---')
clear
t0 = 0.01;
oscil=@(t, Y)[Y(2); -1/(t+t0)^2];
[T Y]=ode23(oscil, [0 15], [log(t0); 100])
f = @(t) log(t);
hold on; grid on
fplot(f, [0 15])
plot(T, Y(:,1),'r')
