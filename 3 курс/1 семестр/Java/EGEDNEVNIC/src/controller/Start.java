package controller;

import Frames.Main.MainFrame;

import javax.swing.*;
import java.awt.*;
import java.util.HashMap;
import java.util.Map;

public class Start {
    public static void main(String[] args)
    {
        EventQueue.invokeLater(new Runnable() {
            public void run() {
                //Создаем массив объектов APPLICATIONS, который будет хранить ссылки на объекты программы
                Map<String, Object> Application = new HashMap();

                //Создаем главное окно программы
                JFrame PFrame = new MainFrame();
                PFrame.setTitle("Ежедневник");
                PFrame.setName(App.PFrame);
                App.Frames.put(App.PFrame, PFrame);
                PFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                PFrame.setSize(9*45, 15*45);
                PFrame.setLocationRelativeTo(null);
                PFrame.setVisible(true);
            }
        });
    }
}

