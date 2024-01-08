package ru.miet.testing;

import javax.swing.*;

public class CalcController implements CalculatorPresenter {
    CalcView calcView = new CalcView();
    CalcModel calcModel = new CalcModel();

    @Override
    public void onPlusClicked() throws Exception {
        solveTask(1);
    }

    @Override
    public void onMinusClicked() throws Exception {
        solveTask(2);
    }

    @Override
    public void onMultiplyClicked() throws Exception {
        solveTask(3);
    }

    @Override
    public void onDivideClicked() throws Exception {
        solveTask(4);
    }

    private void solveTask(int operator) throws Exception {
        try {
            double a = Double.parseDouble(calcView.getFirstArgumentAsString());
            double b = Double.parseDouble(calcView.getSecondArgumentAsString());
            double result;


            switch (operator) {
                case 1 -> {
                    result = calcModel.sum(a, b);
                    break;
                }
                case 2 -> {
                    result = calcModel.subtract(a, b);
                    break;
                }
                case 3 -> {
                    result = calcModel.multiply(a, b);
                    break;
                }
                case 4 -> {
                    result = calcModel.divide(a, b);
                    break;
                }
                default -> {
                    result = 0;
                    break;
                }
            }

            calcView.printResult(result);
        } catch (NumberFormatException e) {
            if (e.getMessage().equals("empty String")) {
                calcView.displayError("Аргументы не должны быть пустыми");
                throw new Exception("Аргументы не должны быть пустыми");
            }
            else
                calcView.displayError("Аргументы должны быть числом");
        } catch (ArithmeticException e) {
                calcView.displayError("На ноль делить нельзя");
        }
    }
}
