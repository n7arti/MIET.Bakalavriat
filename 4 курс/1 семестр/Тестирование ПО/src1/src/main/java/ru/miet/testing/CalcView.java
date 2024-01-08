package ru.miet.testing;

import javax.swing.*;

public class CalcView implements CalculatorView {
    static Interface calc = new Interface();

    @Override
    public void printResult(double result) {
        calc.setResult(String.valueOf(result));
    }

    @Override
    public void displayError(String message) {
        Interface.error = message;
        JOptionPane.showMessageDialog(calc, message);
    }

    @Override
    public String getFirstArgumentAsString() {
        return calc.getA();
    }

    @Override
    public String getSecondArgumentAsString() {
        return calc.getB();
    }
}
