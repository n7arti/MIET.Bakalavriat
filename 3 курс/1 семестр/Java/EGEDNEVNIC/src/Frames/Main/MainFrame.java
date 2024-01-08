package Frames.Main;

import controller.File;
import model.Task;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.*;
import java.util.List;

public class MainFrame extends JFrame implements ActionListener {
    private JPanel panel;
    private GridBagConstraints gbc;
    private JButton addNewTask;
    private JButton backgroundColor;
    private JLabel date;
    private JList taskList;
    private List<Task> ListTask;

    public MainFrame() {
        ListTask = new ArrayList<>();
        ListTask = File.importFromFile();
        //Создаем панель содержимого для размещения элементов
        panel = new JPanel();
        //Назначаем менеджера компоновки для размещения компонентов
        GridBagLayout layout = new GridBagLayout();
        gbc = new GridBagConstraints();
        panel.setLayout(layout);
        Color c = File.uploadProperties();
        panel.setBackground(c);
        GregorianCalendar cannes = new GregorianCalendar();
        DateFormat df = new SimpleDateFormat("d MMMM y");
        date = new JLabel(df.format(cannes.getTime()));
        gbc.fill = GridBagConstraints.VERTICAL;
        gbc.gridx = 0;
        gbc.gridy = 0;
        gbc.weightx = 1;
        gbc.weighty = 0.02;
        gbc.gridheight = 1;
        gbc.gridwidth = GridBagConstraints.REMAINDER;
        gbc.anchor = GridBagConstraints.NORTH;
        panel.add(date, gbc);
        //Создаем ячейку для кнопки с помощью вспомогательного класса GBC
        //Расширяющего класс GridBagConstrains
        addNewTask = new JButton("Новая задача");
        gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.gridy = 1;
        gbc.weighty = 0.02;
        addNewTask.setName("addNewTask");
        addNewTask.setActionCommand("addNewTask");
        addNewTask.addActionListener(this);
        panel.add(addNewTask, gbc);
        //ListTask.add(new Task(new MYTime(12, 0), "Поцеовашкаться", Importance.A));
        //ListTask.add(new Task(new MYTime(13, 0), "Пообнимашкаться", Importance.C));
        //ListTask.add(new Task(new MYTime(13, 10), "СДЕЛАТЬ НАКОНЕЦ ДЖАВУ", Importance.B));
        sortTasksByTime();
        DefaultListModel model = new DefaultListModel();
        model.addAll(new Vector<Task>(ListTask));
        taskList = new JList(model);
        taskList.setBackground(c);
        taskList.setCellRenderer(new DefaultListCellRenderer() {
            @Override
            public Component getListCellRendererComponent(JList<?> list, Object value, int index, boolean isSelected, boolean cellHasFocus) {
                Component renderer = super.getListCellRendererComponent(list, value, index, isSelected, cellHasFocus);
                if (renderer instanceof JLabel && value instanceof Task) {
                    String color = "";
                    switch (((Task) value).getImportance()) {
                        case A: {
                            color = "red";
                            break;
                        }
                        case B: {
                            color = "yellow";
                            break;
                        }
                        case C: {
                            color = "green";
                            break;
                        }

                    }
                    ((JLabel) renderer).setText("<html><font color=" + color + ">██ </font>" + "\t" + ((Task) value).getTime().toString() + " " + ((Task) value).getText());

                }
                return renderer;
            }
        });
        gbc.fill = GridBagConstraints.BOTH;
        gbc.gridy = 2;
        gbc.weighty = 0.94;
        panel.add(taskList, gbc);
        backgroundColor = new JButton("Цвет фона");
        gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.gridy = 3;
        gbc.weighty = 0.02;
        gbc.anchor = GridBagConstraints.SOUTH;
        backgroundColor.setName("backgroundColor");
        backgroundColor.setActionCommand("backgroundColor");
        backgroundColor.addActionListener(this);
        panel.add(backgroundColor, gbc);
        getContentPane().add(panel);
    }

    public void sortTasksByTime(){
        for (int i = 0; i< ListTask.size(); i++) {
            for (int j = i+1; j< ListTask.size(); j++) {
                Task item1 = ListTask.get(i);
                Task item2 = ListTask.get(j);
                if(item1.getTime().getHour()>item2.getTime().getHour()) {
                    ListTask.set(i,item2);
                    ListTask.set(j,item1);
                }
                else if(item1.getTime().getHour()==item2.getTime().getHour())
                    if(item1.getTime().getMinute()>item2.getTime().getMinute()){
                        ListTask.set(i,item2);
                        ListTask.set(j,item1);
                    }
            }
        }
     }
    @Override
    public void actionPerformed(ActionEvent e) {
        switch (e.getActionCommand().toString()) {
            case "addNewTask": {
                JFrame newTask = new NewTask();
                newTask.setSize(9 * 33, 5 * 33);
                newTask.setUndecorated(true);
                newTask.setLocation(getLocation().x+(getWidth() - newTask.getWidth()) / 2, getLocation().y+(getHeight() - newTask.getHeight()) / 2);
                newTask.setVisible(true);
                addComponentListener(new ComponentAdapter() {
                    @Override
                    public void componentMoved(ComponentEvent e) {
                        super.componentMoved(e);
                        newTask.setLocation(getLocation().x+(getWidth() - newTask.getWidth()) / 2, getLocation().y+(getHeight() - newTask.getHeight()) / 2);
                    }
                });
                newTask.addWindowListener(new WindowAdapter() {
                    @Override
                    public void windowClosing(WindowEvent e) {
                        ListTask = new ArrayList<>();
                        ListTask = File.importFromFile();
                        File.exportToFile(ListTask);
                        sortTasksByTime();
                        DefaultListModel model = new DefaultListModel();
                        model.addAll(new Vector<Task>(ListTask));
                        taskList.setModel(model);
                    }
                });
                break;
            }
            case "backgroundColor": {
                JFrame bColor = new ColorChoser();
                bColor.setUndecorated(true);
                bColor.pack();
                bColor.setLocation(getLocation().x+(getWidth() - bColor.getWidth()) / 2, getLocation().y+(getHeight() - bColor.getHeight()) / 2);
                bColor.setVisible(true);
                addComponentListener(new ComponentAdapter() {
                    @Override
                    public void componentMoved(ComponentEvent e) {
                        super.componentMoved(e);
                        bColor.setLocation(getLocation().x+(getWidth() - bColor.getWidth()) / 2, getLocation().y+(getHeight() - bColor.getHeight()) / 2);
                        bColor.setVisible(true);
                    }
                });
                bColor.addWindowListener(new WindowAdapter() {
                    @Override
                    public void windowClosing(WindowEvent e) {
                        Color c = File.uploadProperties();
                        panel.setBackground(c);
                        taskList.setBackground(c);
                    }

                    /*@Override
                    public void windowDeactivated(WindowEvent e) {
                        super.windowActivated(e);
                        bColor.setVisible(true);
                    }*/
                });
                break;
            }

        }
    }
}
