package ru.miet.testing;

public interface Calculator {
     /**
     * Вычисляет сумму двух чисел
     */
     public double sum(double a, double b);


    /**
     * Вычисляет разность двух чисел a - b
     */
    public double subtract(double a, double b);

    /**
     * Вычисляет произведение двух чисел
     */
    public double multiply(double a, double b);

    /**
     * Вычисляет отношение числа а к числу b.
     * Должен выбросить {@link java.lang.ArithmeticException} если |b| < 10e-8
     */
    public double divide(double a, double b);
}
