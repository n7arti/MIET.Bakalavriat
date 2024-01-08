package ru.miet.testing;

import java.awt.event.*;
import javax.swing.*;

public class Interface extends JFrame implements ActionListener {
    static JFrame frame;
    static JLabel ANumLabel;
    static JLabel BNumLabel;
    static JLabel ResultLabel;
    public static JTextField ANumInputField;
    public static JTextField BNumInputField, ResultInputField;
    public static JButton plusButton, subtractButton, multiplyButton, divideButton;
    public static String error;
    CalcController calcController = new CalcController();

    public void setResult(String str) {
        ResultInputField.setText(str);
    }

    public String getA() {
        return ANumInputField.getText();
    }

    public String getB() {
        return BNumInputField.getText();
    }
    public Interface(){
        JPanel panel = new JPanel();
        frame = new JFrame("Calculator");

        ANumLabel = new JLabel("Аргумент 1");
        BNumLabel = new JLabel("Аргумент 2");
        ResultLabel = new JLabel("Результат");

        ANumInputField = new JTextField(13);
        BNumInputField = new JTextField(13);
        ResultInputField = new JTextField(13);

        ResultInputField.setEditable(false);

        plusButton = new JButton("+");
        subtractButton = new JButton("-");
        multiplyButton = new JButton("*");
        divideButton = new JButton("/");

        plusButton.addActionListener(this);
        subtractButton.addActionListener(this);
        multiplyButton.addActionListener(this);
        divideButton.addActionListener(this);

        panel.add(ANumLabel);
        panel.add(ANumInputField);

        panel.add(BNumLabel);
        panel.add(BNumInputField);

        panel.add(ResultLabel);
        panel.add(ResultInputField);

        panel.add(plusButton);
        panel.add(subtractButton);
        panel.add(multiplyButton);
        panel.add(divideButton);

        frame.add(panel);
        frame.setLocationRelativeTo(null);
        frame.setSize(250, 150);
        frame.show();
    }

    public static void main(String[] args) {
        Interface calculator = new Interface();
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        String s = e.getActionCommand();
        try {
            switch (s) {
                case "+" -> calcController.onPlusClicked();
                case "-" -> calcController.onMinusClicked();
                case "*" -> calcController.onMultiplyClicked();
                case "/" -> calcController.onDivideClicked();
            }

        }
        catch (Exception ex) {
        }

    }
}

