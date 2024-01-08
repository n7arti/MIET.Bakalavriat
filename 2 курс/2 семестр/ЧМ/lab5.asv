clc
%Exercise 1
disp('--- Exercise 1 ---')
clear
f=@(x)(x^3);
n = 10;
h = 1/n;
j=1;
for i=0:h:1
    fi(j)=f(i);
    j = j+1;
end
sum=0;
for i=1:n+1
    if (i == 1)|| ( i== n)
        sum = sum + 1/2*fi(i);
    else
        sum = sum +fi(i);
    end
end
sum = sum*h
eps = sum - 1/4;
M2 = 6;
eps1 = h^2/12 * M2;
disp(sprintf('Практическая ошибка при h/%d: %.4f- 1/4 = %.4f', n,sum, eps))
disp(sprintf('Теоретическая ошибка: %.4f', eps1))
%%
clc
%Exercise 1.2
disp('--- Exercise 1.2 ---')
clear
f=@(x)(1/(1+x^2));
h = 0.001;
n = 1/h;
j=1;
for i=0:1/2*h:1
    fi(j)=f(i);
    j = j+1;
end
sum=0;
for i=3:2:2*n+1
    sum=sum+fi(i)+fi(i-2)+4*fi(i-1);
end

sum=sum*h/6 *4
eps = sum - 1/4;
disp(sprintf('Погрешность: %.4f- 1/4 = %.4f', sum, eps))
%%
clc
%Exercise 3.1
disp('--- Exercise 3.1 ---')
clear
f=@(x)(1/(1+x^2));
h = 0.01/2;
n = 1/h;
j=1;
for i=0:h:1
    fi(j)=f(i);
    j = j+1;
end
sum=0;
for i=1:2:n+1
    if (i == 1)|| ( i== n+1)
        sum = sum + 1/2*fi(i);
    else
        sum = sum +fi(i);
    end
end
Ih = sum*h*2*4
sum1 = 0;
for i=2:2:n+1
    sum1 = sum1 +fi(i);
end
Ih2 = (Ih/2 + h*sum1)*2


OIh= abs(Ih - pi)
OIh2 = abs(Ih2 - pi)
o = 1/3*abs(Ih - Ih2)
%%
clc
syms x
y = diff(1/(x^2 +1), x,2)
[x0,M2]=fminbnd(@(x)-abs((8*x^2)/(x^2 + 1)^3 - 2/(x^2 + 1)^2),0,1);
-M2
y = diff(1/(x^2 +1), x,4)
%[x0,M4]=fminbnd(@(x) -abs(24/(x^2 + 1)^3 - (288*x^2)/(x^2 + 1)^4 + (384*x^4)/(x^2 + 1)^5));
%-M4
y = @(x) abs(24/(x^2 + 1)^3 - (288*x^2)/(x^2 + 1)^4 + (384*x^4)/(x^2 + 1)^5);
hold on; grid on
fplot(y, [0 1])
plot([0 1], [24 24], 'r')