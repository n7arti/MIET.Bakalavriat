// See https://aka.ms/new-console-template for more information
int N = 15;
int[,] matrix = new int[N,N];
Random rand = new Random();
for(int i = 0; i < N; i++)
{
    for (int j = 0; j < i+1; j++)
    {
        if (i == j)
            matrix[i, j] = 0;
        else
        {
            matrix[i, j] = rand.Next(-1000, 1000);
            matrix[j, i] = (-1)* matrix[i, j];
        }
    }
}
for (int i = 0; i < N; i++)
{
    for (int j = 0; j < N; j++)
    {
        Console.Write(matrix[i, j] + "\t");
    }
    Console.WriteLine();
}
Console.WriteLine();
matrix = recalc(matrix);
for (int i = 0; i < N; i++)
{
    for (int j = 0; j < N; j++)
    {
        Console.Write(matrix[i, j] + "\t");
    }
    Console.WriteLine();
}
int[,] recalc(int[,] matrix)
{
    int[,] Y = new int[N, N];
    int[] S = new int[N];
    int sum =0 ;
    for (int i = 0; i < N; i++)
    {
        S[i] = 0;
        for (int j = 0; j < N; j++)
        {
            S[i] +=matrix[i, j];
        }
        sum += Math.Abs(S[i]);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i - 1; j++)
        {
            Y[i, j] = (S[i] * Math.Abs(S[j]) - S[j] * Math.Abs(S[i])) / sum;
            Y[j, i] = -Y[i, j];
        }
    }
    return Y;
} 
//сумма столбцов
//S = sum(X, 1);
//SS = sum(abs(S));



