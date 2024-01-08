using System;

namespace Lab1
{
    class Program
    {
        static double g = 9.8;
        public static void speedPulse(double M, double m, double L, double l)
        {
            double U = L * M / m * Math.Sqrt(g / l);
            Console.WriteLine("Скорость пули из закона сохранения импульса " + U);
        }
        public static void speedEnergy(double M, double m, double L, double l)
        {
            double U = L * Math.Sqrt(M * g / (m * l));
            Console.WriteLine("Скорость пули из закона сохранения энергии " + U);
        }
        public static void AFSPulse(double M, double m, double l, double U)
        {
            double a = U * m / M * Math.Sqrt(1 / (g * l));
            Console.WriteLine(U + ";" + a);
        }
        public static void AFSEnergy(double M, double m, double l, double U)
        {
            double a = U * Math.Sqrt(m / (M * g * l));
            Console.WriteLine(U + ";" + a);
        }
        static void Main(string[] args)
        {
            double m = 0.007;
            double M = 0.2;
            double L = 0.2;
            double l = 1;
            speedPulse(M, m, L, l);
            speedEnergy(M, m, L, l);
            Console.WriteLine("Зависимость угла отклонения от скорости по закону сохранения энергии");
            for (double U = 100; U <= 1000; U += 10)
                AFSEnergy(M, m, L, U);
            Console.WriteLine("Зависимость угла отклонения от скорости по закону сохранения импульса");
            for (double U = 100; U <= 1000; U += 10)
                AFSPulse(M, m, L, U);
        }
    }
}
