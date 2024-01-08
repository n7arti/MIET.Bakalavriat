// See https://aka.ms/new-console-template for more information
int N0 = 1000;
int Np0 = 10000;
double a0 = 0.2;
double t, a;
int Np;

for (Np = Np0, t = 0; Np0 < 15000 && t < 5; Np += 100, t += 0.1)
    Console.WriteLine(Math.Round(t, 1) + ";" + Np);
for (a = a0, Np = Np0, t = 0; Np0 < 15000 && t < 5&& a<2.7; Np += 100, t += 0.1, a+=0.05)
{
    double Nt = (Np* N0* Math.Exp(Math.Exp(a)*t))/ (Np0 - N0 * (1 - Math.Exp(Math.Exp(a) * t)));
    Console.WriteLine(Math.Round(t, 1) + ";" + Nt);
}
