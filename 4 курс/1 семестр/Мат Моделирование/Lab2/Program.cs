// See https://aka.ms/new-console-template for more information

double xs = 0, ys = 3,
    xp = 9, yp = -6,
    xo, yo = 0,
    n1 = 1, n2 = 2,
    A, B,
    SO, OP,
    L1, Lmin = Double.MaxValue, xomin = 0,
    sinθ1 = -1, sinθ2 = -1;
for (xo = 0; xo < xp; xo += 0.1)
{
    A = xo - xs;
    SO = Math.Sqrt(Math.Pow(A, 2) + Math.Pow(ys, 2));
    B = xp - xs;
    OP = Math.Sqrt(Math.Pow(B - A, 2) + Math.Pow(yp, 2));
    L1 = n1 * SO + n2 * OP;
    Console.WriteLine(Math.Asin(A / SO)*180/Math.PI + ";" + L1);
    if (L1 < Lmin)
    {
        xomin = xo;
        Lmin = L1;
        sinθ1 = A / SO;
        sinθ2 = (B - A) / OP;
    }
}
Console.WriteLine(xs + ";" + ys);
Console.WriteLine(xomin + ";" + yo);
Console.WriteLine(xp + ";" + yp);
Console.WriteLine(n1 * sinθ1);
Console.WriteLine(n2 * sinθ2);
