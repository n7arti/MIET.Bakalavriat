package pack;

import java.util.ArrayList;
import java.util.Scanner;

public class Student extends Human{
    protected double avrSessionScore;

    public double getAvrSessionScore() {
        return avrSessionScore;
    }

    public void setAvrSessionScore(double avrSessionScore) {
        this.avrSessionScore = avrSessionScore;
    }

    public Student(String name, String secondName, int age, String sex, double avrSessionScore) {
        super(name, secondName, age, sex);
        this.avrSessionScore = avrSessionScore;
    }
    public Student() {
        super();
        this.avrSessionScore = 0;
    }
    @Override
    public String toString() {
        return "Имя: " + name + '\n' + "Отчество: " + secondName + '\n'
                + "Возраст: " + age + '\n' + "Пол: " + sex + '\n' + "Средняя оценка за сессию: "+avrSessionScore+'\n';
    }

    public String toSave() {
        return name + '\n' + secondName + '\n' + age + '\n' + sex + '\n'+avrSessionScore+'\n';
    }

    public static void addStudent(ArrayList<Student> s){
        String name;
        String secondName;
        int age;
        String sex;
        double avrSessionScore;
        Scanner sn = new Scanner(System.in);
        System.out.println("Введите имя: ");
        name = sn.nextLine();
        System.out.println("Введите отчество: ");
        secondName = sn.nextLine();
        System.out.println("Введите пол: ");
        sex = sn.nextLine();
        System.out.println("Введите возраст: ");
        age = sn.nextInt();
        System.out.println("Введите средний балл за сессию: ");
        avrSessionScore = sn.nextDouble();
        Student st1 = new Student(name, secondName, age, sex, avrSessionScore);
        s.add(st1);
    }
}
