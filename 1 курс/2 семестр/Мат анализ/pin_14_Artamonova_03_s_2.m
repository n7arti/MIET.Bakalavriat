clc
clear
%ex1
syms n
hold on
Sn = 0;
an = input('¬ведите общий член последовательности: ');
n0 = input('¬ведите число рассматриваемых членов: ');
for i = 1:1:n0;
    Sn = Sn + subs(an,'n',i);
    plot(i,Sn,'r*')
end
grid on
%%
disp('--')
%ex2
clear
syms n
figure(2)
hold on
grid on
q = input('¬ведите значение q: ');
f0 = q;
fn = q^2;
Sn = q + q^2;
if limit(q.^n,n,+Inf)==0
    while f0-fn>0.00001
        f0 = fn;
       for n = 3:1:10000
           fn = q.^n;
           Sn = Sn + fn;
           plot(n,Sn,'r*')
       end
    end
end
%%
%ex3
disp('--')
clear
figure(3)
syms n
hold on
Sn = 0;
a = input('¬ведите значение a: ');
an = 1/n^a;
s = limit(int(1/n^a,'n',1,Inf));
if s == Inf
    disp('–€д расходитс€')
else
    disp('–€д сходитс€')
end
syms n
for i = 1:1:100;
    Sn = Sn + subs(an,'n',i);
    plot(i,Sn,'r*')
end
grid on
%%
%ex4
disp('--')
clear