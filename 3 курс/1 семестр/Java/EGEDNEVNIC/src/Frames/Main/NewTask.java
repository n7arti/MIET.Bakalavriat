package Frames.Main;

import controller.File;
import model.Importance;
import model.MYTime;
import model.Task;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Vector;

public class NewTask extends JFrame implements ActionListener {
    private JPanel panel;
    private JButton addNewTask;
    private JButton cancel;
    private JTextField hour;
    private JTextField minute;
    private JLabel separator;
    private JLabel spase;
    private JComboBox<String> importance;
    private JTextField text;
    private JLabel rect;
    private List<Task> ListT;

    NewTask() {
        ListT = new ArrayList<>();
        for (Task ta : ListT)
            System.out.println(" new " + ta.toString());
        String[] elements = new String[]{"Важно", "Средне", "Наименее важно"};
        panel = new JPanel();
        //Назначаем менеджера компоновки для размещения компонентов
        GridBagLayout layout = new GridBagLayout();
        GridBagConstraints gbc = new GridBagConstraints();
        panel.setLayout(layout);
        panel.setBackground(Color.white);
        //Создаем ячейку для кнопки с помощью вспомогательного класса GBC
        //Расширяющего класс GridBagConstrains
        //Создаем кнопку показать график
        spase = new JLabel("Время");
        gbc.fill = GridBagConstraints.VERTICAL;
        gbc.gridx = 0;
        gbc.gridy = 0;
        gbc.weightx = 1;
        gbc.weighty = 0.02;
        gbc.gridheight = 1;
        gbc.gridwidth = GridBagConstraints.REMAINDER;
        gbc.anchor = GridBagConstraints.NORTH;
        panel.add(spase, gbc);
        spase = new JLabel(" ");
        gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.gridy = 1;
        gbc.weightx = 0.4;
        gbc.gridwidth = 2;
        panel.add(spase, gbc);
        hour = new JTextField();
        hour.setHorizontalAlignment(JTextField.RIGHT);
        gbc.gridx = 2;
        gbc.weightx = 0.1;
        gbc.anchor = GridBagConstraints.NORTHEAST;
        panel.add(hour, gbc);
        separator = new JLabel(":");
        gbc.gridx = 4;
        gbc.weightx = 0.01;
        gbc.anchor = GridBagConstraints.NORTH;
        panel.add(separator, gbc);
        minute = new JTextField();
        gbc.gridx = 6;
        gbc.weightx = 0.08;
        gbc.anchor = GridBagConstraints.NORTHWEST;
        panel.add(minute, gbc);
        spase = new JLabel(" ");
        gbc.gridx = 8;
        gbc.weightx = 0.42;
        panel.add(spase, gbc);
        spase = new JLabel("Важность: ");
        spase.setVerticalAlignment(JLabel.CENTER);
        gbc.gridx = 0;
        gbc.gridy = 2;
        gbc.weightx = 0.5;
        gbc.anchor = GridBagConstraints.NORTH;
        panel.add(spase, gbc);
        importance = new JComboBox<String>(elements);
        importance.setSelectedItem(elements[0]);
        importance.setName("importance");
        importance.setActionCommand("importance");
        importance.addActionListener(this);
        gbc.fill = GridBagConstraints.BOTH;
        gbc.gridx = 2;
        gbc.gridwidth = 7;
        panel.add(importance, gbc);
        rect = new JLabel(" ");
        rect.setOpaque(true);
        rect.setBackground(Color.red);
        gbc.gridx = 9;
        gbc.gridwidth = 1;
        panel.add(rect, gbc);
        text = new JTextField();
        gbc.gridx = 0;
        gbc.gridy = 4;
        gbc.weighty = 0.8;
        gbc.gridheight = 2;
        gbc.gridwidth = GridBagConstraints.REMAINDER;
        panel.add(text, gbc);
        addNewTask = new JButton("Добавить");
        gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.gridx = 5;
        gbc.gridy = 6;
        gbc.weightx = 0.5;
        gbc.weighty = 0.1;
        gbc.gridheight = 1;
        gbc.gridwidth = 5;
        gbc.anchor = GridBagConstraints.SOUTH;
        addNewTask.setName("addNewTask");
        addNewTask.setActionCommand("addNewTask");
        addNewTask.addActionListener(this);
        panel.add(addNewTask, gbc);

        cancel = new JButton("Отмена");
        //gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.gridx = 0;
        cancel.setName("cancel");
        cancel.setActionCommand("cancel");
        //имя addNewTask передается в событие и используется для определения действия
        cancel.addActionListener(this);
        panel.add(cancel, gbc);
        getContentPane().add(panel);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        switch (e.getActionCommand().toString()) {
            case "addNewTask": {
                try {
                    int hourTask = Integer.parseInt(hour.getText());
                    int minuteTask = Integer.parseInt(minute.getText());
                    if (hourTask < 0 || hourTask > 23 || minuteTask < 0 || minuteTask > 59)
                        throw new Exception("Введите верный формат времени!");
                    MYTime t = new MYTime(hourTask, minuteTask);
                    String textTask = text.getText();
                    if (textTask.equals(""))
                        throw new Exception("Введите задачу!");
                    Importance importanceT;
                    String importanceTask = (String) importance.getSelectedItem();
                    switch (importanceTask) {
                        case "Важно": {
                            importanceT = Importance.A;
                            break;
                        }
                        case "Средне": {
                            importanceT = Importance.B;
                            break;
                        }
                        case "Наименее важно": {
                            importanceT = Importance.C;
                            break;
                        }
                        default:
                            importanceT = Importance.A;
                    }
                    Task newTask = new Task(t, textTask, importanceT);
                    ListT.add(newTask);
                    File.exportToFile(ListT);
                    dispatchEvent(new WindowEvent(this, WindowEvent.WINDOW_CLOSING));

                } catch (NumberFormatException ex){
                    JFrame error = new Error("Введите время!");
                    error.setUndecorated(true);
                    error.setLocation(getLocation().x+(getWidth() - error.getWidth()) / 2, getLocation().y+(getHeight() - error.getHeight()) / 2);
                    error.setVisible(true);
                }
                catch (Exception ex) {
                    JFrame error = new Error(ex.getMessage());
                    error.setUndecorated(true);
                    error.setLocation(getLocation().x+(getWidth() - error.getWidth()) / 2, getLocation().y+(getHeight() - error.getHeight()) / 2);
                    error.setVisible(true);
                }
                break;
            }
            case "cancel": {
                dispose();
                break;
            }
            case "importance": {
                String importanceTask = (String) importance.getSelectedItem();
                switch (importanceTask) {
                    case "Важно": {
                        rect.setBackground(Color.red);
                        break;
                    }
                    case "Средне": {
                        rect.setBackground(Color.yellow);
                        break;
                    }
                    case "Наименее важно": {
                        rect.setBackground(Color.green);
                        break;
                    }

                }
                break;
            }
        }
    }
}
