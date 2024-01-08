package pack;

import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

import static pack.CoolParent.addCoolParent;
import static pack.Parent.addParent;
import static pack.SmartStudent.addSmartStudent;
import static pack.Student.addStudent;

public class Main {
    private static int com;
    private static ArrayList<Student> students;
    private static ArrayList<Parent> parents;
    private static ArrayList<SmartStudent> smartStudents;
    private static ArrayList<CoolParent> coolParents;

    public static void model() {
        students = new ArrayList<Student>();
        parents = new ArrayList<Parent>();
        smartStudents = new ArrayList<SmartStudent>();
        coolParents = new ArrayList<CoolParent>();
    }

    public static void fileOpen() {
        String filename = "stud.txt";
        String temp;
        try (FileReader stud = new FileReader(filename)) {
            BufferedReader dataInput = new BufferedReader(new FileReader(filename));
            while ((temp = dataInput.readLine()) != "" & temp!=null) {
                Student s = new Student(dataInput.readLine(),dataInput.readLine(),Integer.parseInt(dataInput.readLine()),dataInput.readLine(),Double.parseDouble(dataInput.readLine()));
                students.add(s);
            }
        }
        catch(IOException ex){
                System.out.println(ex.getMessage());
            }
    }

    public static void fileClose() {
        try (FileWriter dataOut = new FileWriter("stud.txt", false)) {
            for (Student i: students) {
                dataOut.append(" \n");
                dataOut.append(i.toSave());
            }
        }
        catch (Exception ex) {
            System.err.println(ex.getMessage());
        }

    }

    public static void mainController() {
        model();
        fileOpen();
        while (com != 9) {
            menuView();
            com = controller();
            switch (com) {
                case (1): {
                    addStudent(students);
                    break;
                }
                case (2): {
                    addSmartStudent(smartStudents);
                    break;
                }
                case (3): {
                    addParent(parents);
                    break;
                }
                case (4): {
                    addCoolParent(coolParents);
                    break;
                }
                case (5): {
                    for (Student i : students)
                        System.out.println(i.toString());
                    break;
                }
                case (6): {
                    for (SmartStudent i : smartStudents)
                        System.out.println(i.toString());
                    break;
                }
                case (7): {
                    for (Parent i : parents)
                        System.out.println(i.toString());
                    break;
                }
                case (8): {
                    for (CoolParent i : coolParents)
                        System.out.println(i.toString());
                    break;
                }
            }
        }
        fileClose();
    }

    public static void menuView() {
        System.out.println("---------------МЕНЮ---------------");
        System.out.println("Добавить студента................1");
        System.out.println("Добавить ботаника................2");
        System.out.println("Добавить родителя................3");
        System.out.println("Добавить крутого родителя .......4");
        System.out.println("Просмотреть студента.............5");
        System.out.println("Просмотреть ботаника.............6");
        System.out.println("Просмотреть родителя.............7");
        System.out.println("Просмотреть крутого родителя ....8");
        System.out.println("Выход............................9");
        System.out.print("Выберите команду: ");
    }

    public static int controller() {
        Scanner sn = new Scanner(System.in);
        int n;
        while (true) {
            n = sn.nextInt();
            if (n < 10)
                break;
            viewError();
        }
        return n;
    }

    public static void viewError() {
        System.out.println("Введите число меньше 10!");
    }

    public static void main(String[] args) {
        mainController();
    }
}
