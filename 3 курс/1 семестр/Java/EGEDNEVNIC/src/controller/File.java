package controller;

import model.Importance;
import model.MYTime;
import model.Task;

import javax.swing.*;
import java.awt.*;
import java.io.*;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.GregorianCalendar;
import java.util.List;

public class File {
    private static final String FILE_NAME = "data.txt";
    private static final String PROPERTIES = "prop.txt";
    private static List<Task> listTask = new ArrayList<>();

    public static List<Task> importFromFile() {
        String temp;
        try {
            BufferedReader dataInput = new BufferedReader(new FileReader(FILE_NAME));
            GregorianCalendar cannes = new GregorianCalendar();
            DateFormat df = new SimpleDateFormat("d MMMM y");
            if (dataInput.readLine().equals(df.format(cannes.getTime()))) {
                while ((temp = dataInput.readLine()) != "" & temp != null) {
                    MYTime time = new MYTime(Integer.parseInt(dataInput.readLine()), Integer.parseInt(dataInput.readLine()));
                    String text = dataInput.readLine();
                    Importance importanceT;
                    String imp = dataInput.readLine();
                    switch (imp) {
                        case "A": {
                            importanceT = Importance.A;
                            break;
                        }
                        case "B": {
                            importanceT = Importance.B;
                            break;
                        }
                        case "C": {
                            importanceT = Importance.C;
                            break;
                        }
                        default:
                            importanceT = Importance.A;
                    }
                    Task t = new Task(time, text, importanceT);
                    listTask.add(t);
                }
            }
        } catch (IOException ex) {
            System.err.println(ex.getMessage());
        }
        return listTask;
    }

    public static void exportToFile(List<Task> lt) {
        GregorianCalendar cannes = new GregorianCalendar();
        DateFormat df = new SimpleDateFormat("d MMMM y");
        try (FileWriter dataOut = new FileWriter(FILE_NAME, false)) {
            dataOut.write(df.format(cannes.getTime()) + '\n');
            for (Task t : lt) {
                dataOut.write(System.getProperty("line.separator"));
                dataOut.write(t.toSave());
            }
            dataOut.flush();
        } catch (Exception ex) {
            System.err.println(ex.getMessage());
        }
    }

    public static Color uploadProperties() {
        Color c = null;
        String temp;
        try {
            BufferedReader dataInput = new BufferedReader(new FileReader(PROPERTIES));
            while ((temp = dataInput.readLine()) != "" & temp != null)
                c = new Color(Integer.parseInt(temp),Integer.parseInt(dataInput.readLine()),Integer.parseInt(dataInput.readLine()));
        } catch (Exception ex) {
            System.err.println(ex.getMessage());
        }
        return c;
    }

    public static void saveProperties(Color c) {
        try (FileWriter dataOut = new FileWriter(PROPERTIES, false)) {
            dataOut.write(c.getRed()+System.getProperty("line.separator"));
            dataOut.write(c.getGreen()+System.getProperty("line.separator"));
            dataOut.write(c.getBlue()+System.getProperty("line.separator"));
            dataOut.flush();
        } catch (Exception ex) {
            System.err.println(ex.getMessage());
        }
    }
}
