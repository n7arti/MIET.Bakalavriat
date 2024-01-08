package pack;

import java.util.ArrayList;
import java.util.Scanner;

public class SmartStudent extends Student{

    public SmartStudent(String name, String secondName, int age, String sex, double avrSessionScore) {
        super(name, secondName, age, sex, avrSessionScore);
    }

    public SmartStudent() {
        super();
    }
    @Override
    public String toString() {
        return "Имя: " + name + '\n' + "Отчество: " + secondName + '\n'
                + "Возраст: " + age + '\n' + "Пол: " + sex + '\n' + "Средняя оценка за сессию: "+avrSessionScore+'\n';
    }
    public static void addSmartStudent(ArrayList<SmartStudent> s){
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
        SmartStudent st1 = new SmartStudent(name, secondName, age, sex, avrSessionScore);
        s.add(st1);
    }
}
