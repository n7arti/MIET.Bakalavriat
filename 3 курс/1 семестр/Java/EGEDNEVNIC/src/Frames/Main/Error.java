package Frames.Main;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Error extends JFrame implements ActionListener {
    private JPanel panel;
    private GridBagConstraints gbc;
    private JLabel message;
    private JButton ok;
    public Error(String ex){
        setSize(30*10 , 5*10);
        panel = new JPanel();
        //Назначаем менеджера компоновки для размещения компонентов
        GridBagLayout layout = new GridBagLayout();
        GridBagConstraints gbc = new GridBagConstraints();
        panel.setLayout(layout);
        getRootPane().setBorder(BorderFactory.createMatteBorder(2, 2, 2, 2, Color.RED));
        ok = new JButton("ОК");
        gbc.gridx = 0;
        gbc.gridy = 1;
        gbc.weightx = 1;
        gbc.weighty = 0.5;
        gbc.gridheight = 1;
        gbc.gridwidth = 1;
        gbc.anchor = GridBagConstraints.SOUTH;
        ok.addActionListener(this);
        panel.add(ok, gbc);
        message = new JLabel(ex);
        message.setHorizontalAlignment(JLabel.CENTER);
        gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.gridy = 0;
        gbc.gridwidth = GridBagConstraints.REMAINDER;
        gbc.anchor = GridBagConstraints.NORTH;
        panel.add(message, gbc);
        getContentPane().add(panel);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        dispose();
    }
}
