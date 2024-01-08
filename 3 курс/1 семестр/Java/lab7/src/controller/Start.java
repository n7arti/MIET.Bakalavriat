package controller;

import frame.TestPane;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Start {
    public static void main(String[] args)
    {
        EventQueue.invokeLater(new Runnable() {
            public void run() {
                JFrame PFrame = new JFrame();
                PFrame.setTitle("Гонки");
                PFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                PFrame.setLayout(new BorderLayout());
                TestPane testPane = new TestPane();

                PFrame.add(testPane);
                //PFrame.pack();
                PFrame.setSize(15*50, 11*50);
                PFrame.setLocationRelativeTo(null);
                PFrame.setVisible(true);
            }
        });
    }
}
