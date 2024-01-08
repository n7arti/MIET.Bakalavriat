package Frames.Main;

import controller.File;
import model.Importance;
import model.MYTime;
import model.Task;

import javax.swing.*;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowEvent;

public class ColorChoser extends JFrame implements ActionListener, ChangeListener {
    private JPanel panel;
    private GridBagConstraints gbc;
    private JColorChooser tcc;
    private JLabel banner;
    private JButton apply;
    private JButton cancel;
    public ColorChoser() {
        panel = new JPanel();
        //Назначаем менеджера компоновки для размещения компонентов
        GridBagLayout layout = new GridBagLayout();
        gbc = new GridBagConstraints();
        panel.setLayout(layout);
        panel.setBackground(Color.white);
        banner = new JLabel("Выберите цвет фона: ",
                JLabel.CENTER);
        //banner.setForeground(Color.white);
        gbc.fill = GridBagConstraints.VERTICAL;
        gbc.gridx = 0;
        gbc.gridy = 0;
        gbc.weightx = 1;
        gbc.weighty = 0.02;
        gbc.gridheight = 1;
        gbc.gridwidth = GridBagConstraints.REMAINDER;
        gbc.anchor = GridBagConstraints.NORTH;
        panel.add(banner, gbc);
        tcc = new JColorChooser();
        gbc.gridy = 1;
        gbc.weighty = 0.96;
        panel.add(tcc, gbc);
        apply = new JButton("Применить");
        gbc.gridx = 1;
        gbc.gridy = 2;
        gbc.weightx = 0.5;
        gbc.weighty = 0.02;
        gbc.gridheight = 1;
        gbc.gridwidth = 1;
        gbc.anchor = GridBagConstraints.SOUTHEAST;
        apply.setName("apply");
        apply.setActionCommand("apply");
        apply.addActionListener(this);
        panel.add(apply, gbc);

        cancel = new JButton("Отмена");
        gbc.gridx = 0;
        gbc.anchor = GridBagConstraints.SOUTHWEST;
        cancel.setName("cancel");
        cancel.setActionCommand("cancel");
        cancel.addActionListener(this);
        panel.add(cancel, gbc);
        getContentPane().add(panel);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        switch (e.getActionCommand() ) {
            case "apply": {
                tcc.getSelectionModel().addChangeListener(this);
                File.saveProperties(tcc.getColor());
                dispatchEvent(new WindowEvent(this, WindowEvent.WINDOW_CLOSING));
                break;
            }
            case "cancel": {
                dispose();
                break;
            }
        }
    }

    @Override
    public void stateChanged(ChangeEvent e) {
    }
}
