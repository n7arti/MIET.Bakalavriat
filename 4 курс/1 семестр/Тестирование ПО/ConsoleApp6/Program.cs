// See https://aka.ms/new-console-template for more information
using System.Diagnostics.Metrics;
using System.Numerics;
using System.Security.AccessControl;
using System.Threading;


internal class Program
{
    public delegate void Res(long[] res, int rank);
    class MyThread
    {
        private Res res1;
        public long[] res;
        private long[][] matrix;
        private int M;
        private int N;
        private int rank;
        public MyThread(long[][] matrix, int M, int N, int rank, Res res1)
        {
            this.matrix = matrix;
            this.M = M;
            this.N = N;
            this.rank = rank;
            this.res1 = res1; 
        }
        public void Run()
        {
            Mutex mutex = new Mutex();
            long[] result = new long[M * M];
            result = matrix[0];
            for (int i = 1; i < N; i++)
            {
                
                result = Mult(result, matrix[i], M);
                
            }
            mutex.WaitOne();
            res= new long[M * M];
            for (int i = 0; i < M; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    res[i * M + j] = result[i * M + j];
                }
            }
            res1(res,rank);
            mutex.ReleaseMutex();
        }
        public long[] Mult(long[] A, long[] B, int M)
        {
            long[] result = new long[M * M];
            for (int i = 0; i < M; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    result[i * M + j] = 0;
                    for (int k = 0; k < M; k++)
                    {
                        result[i * M + j] += A[i * M + k] * B[k * M + j];
                    }
                }
            }

            return result;
        }
    }
    private static int Main(string[] args)
    {

        long[][] res = new long[3][];
        int M = 20;
        int N = 200;
        int countthreads = 3;

        void GetMatrix(long[] result, int rank)
        {
            res[rank] = new long[M * M];
            res[rank] = result;
        }
        

        long[][] matrix = new long[N][];

        for (int i = 0; i < N; i++)
        {
            matrix[i] = new long[M * M];
            for (int j = 0; j < M; j++)
            {
                for (int k = 0; k < M; k++)
                {
                    matrix[i][j * M + k] = j + k;
                    //Console.Write(matrix[i][j * M + k] + "\t");
                }
                //Console.WriteLine();
            }
            //Console.WriteLine();
        }


        long[][] matrix1 = new long[N / countthreads][];
        long[][] matrix2 = new long[N / countthreads][];
        long[][] matrix3 = new long[N / countthreads][];

        for (int i = 0; i < N / countthreads; i++)
        {
            matrix1[i] = new long[M * M];
            matrix2[i] = new long[M * M];
            matrix3[i] = new long[M * M];

            for (int j = 0; j < M; j++)
            {
                for (int k = 0; k < M; k++)
                {
                    matrix1[i][j * M + k] = matrix[i][j * M + k];
                    matrix2[i][j * M + k] = matrix[i + N / countthreads][j * M + k];
                    matrix3[i][j * M + k] = matrix[i + 2 * N / countthreads][j * M + k];
                }
            }
        }
        MyThread mt = new MyThread(matrix1, M, N/countthreads, 0,new Res(GetMatrix));
        Thread t1 = new Thread(new ThreadStart(mt.Run));
        mt = new MyThread(matrix2, M, N/countthreads, 1, new Res(GetMatrix));
        Thread t2 = new Thread(new ThreadStart(mt.Run));
        mt = new MyThread(matrix3, M, N/countthreads, 2, new Res(GetMatrix));
        Thread t3 = new Thread(new ThreadStart(mt.Run));

        t1.Start();
        t2.Start();
        t3.Start();

        t1.Join();
        t2.Join();
        t3.Join();

        long[] result = new long[M * M];
        result = res[0];
        for (int i = 1; i < 3; i++)
        {
            result = mt.Mult(result, res[i], M);
        }

        //for (int i = 0; i < M; i++)
        //{
        //    for (int j = 0; j < M; j++)
        //    {
        //        Console.Write(result[i * M + j] + "\t");
        //    }
        //    Console.WriteLine();
        //}
        return 0;

    }

    
}