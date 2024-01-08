package frame;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.Random;

public class TestPane extends JPanel implements ActionListener {
    private ButtonPane panelRed;
    private ButtonPane panelBlue;
    private ButtonPane panelGreen;
    private JButton restart;
    private JPanel pool;
    private Thread red;
    private Thread green;
    private Thread blue;

    public TestPane() {
        setLayout(new BorderLayout());
        pool = new JPanel(null);
        pool.setBackground(Color.white);

        panelRed = new ButtonPane(Color.red);
        panelRed.setLocation(0, 50);
        pool.add(panelRed);

        panelBlue = new ButtonPane(Color.blue);
        panelBlue.setLocation(0, 200);
        pool.add(panelBlue);

        panelGreen = new ButtonPane(Color.green);
        panelGreen.setLocation(0, 350);
        pool.add(panelGreen);

        restart = new JButton("RESTART");
        restart.setSize(100, 30);
        restart.setLocation(320, 460);
        restart.setActionCommand("restart");
        restart.addActionListener(this);
        pool.add(restart);

        add(pool);

        thread();
        red.start();
        blue.start();
        green.start();

    }

    public void finishGame(String color) {
        String textWin = null;
        switch (color) {
            case "Red": {
                textWin = "RED WIN!";
                pool.setBackground(Color.red);
                green.interrupt();
                blue.interrupt();
                break;
            }
            case "Blue": {
                textWin = "BLUE WIN!";
                pool.setBackground(Color.blue);
                red.interrupt();
                green.interrupt();
                break;
            }
            case "Green": {
                textWin = "GREEN WIN!";
                pool.setBackground(Color.green);
                red.interrupt();
                blue.interrupt();
                break;
            }
        }
        JFrame FGH = new FinishGameFrame(textWin);
        FGH.setUndecorated(true);
        FGH.setLocationRelativeTo(null);
        FGH.setVisible(true);
        FGH.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                super.windowClosing(e);
                restart();
            }
        });

    }

    public void thread() {
        red = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    Random random = new Random();
                    int speed = random.nextInt(40) + 10;
                    do {
                        Thread.sleep(1000);
                        panelRed.run(speed);

                    } while (15 * 50 - 115 > panelRed.getLocation().x);
                    System.out.println("RED WIN!");
                    finishGame("Red");
                } catch (InterruptedException e) {
                    System.out.println("Red starting communistic revolution");
                }
            }
        });

        blue = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    Random random = new Random();
                    int speed = random.nextInt(40) + 10;
                    do {
                        Thread.sleep(1000);
                        panelBlue.run(speed);
                    } while (15 * 50 - 115 > panelBlue.getLocation().x);
                    System.out.println("BLUE WIN!");
                    finishGame("Blue");
                } catch (InterruptedException e) {
                    System.out.println("Blue can be drink some hard...");
                }

            }
        });

        green = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    Random random = new Random();
                    int speed = random.nextInt(40) + 10;
                    do {
                        Thread.sleep(1000);
                        panelGreen.run(speed);

                    } while (15 * 50 - 115 > panelGreen.getLocation().x);
                    System.out.println("GREEN WIN!");
                    finishGame("Green");
                } catch (InterruptedException e) {
                    System.out.println("Green may be win once...");
                }

            }
        });
    }

    public void restart() {
        red.interrupt();
        blue.interrupt();
        green.interrupt();
        Rectangle bounds = panelRed.getBounds();
        bounds.x = 0;
        panelRed.setBounds(bounds);
        bounds = panelBlue.getBounds();
        bounds.x = 0;
        panelBlue.setBounds(bounds);
        bounds = panelGreen.getBounds();
        bounds.x = 0;
        panelGreen.setBounds(bounds);
        thread();
        red.start();
        blue.start();
        green.start();
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        restart();
    }
}
