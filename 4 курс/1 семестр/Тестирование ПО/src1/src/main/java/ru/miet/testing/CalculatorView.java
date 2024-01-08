package ru.miet.testing;

public interface CalculatorView {
    /**
     * Отображает результат вычисления
     */
     public void printResult(double result);

    /**
     * Показывает ошибку, например деление на 0, пустые аргументы и прочее
     */
    public void displayError(String message);

    /**
     * Возвращает значение, введенное в поле первого аргументы
     */
    public String getFirstArgumentAsString();

    /**
     * Возвращает значение, введенное в поле второго аргументы
     */
    public String getSecondArgumentAsString();
}
