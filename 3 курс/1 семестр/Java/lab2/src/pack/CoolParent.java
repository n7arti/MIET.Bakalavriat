package pack;

import java.util.ArrayList;
import java.util.Scanner;

public class CoolParent extends Parent{
    public CoolParent(String name, String secondName, int age, String sex, int pocketMoney) {
        super(name, secondName, age, sex, pocketMoney);
    }

    public CoolParent() {
        super();
    }
    @Override
    public String toString() {
        return "Имя: " + name + '\n' + "Отчество: " + secondName + '\n'
                + "Возраст: " + age + '\n' + "Пол: " + sex + '\n' + "Количество карманных денег: "+pocketMoney+'\n';
    }
    public static void addCoolParent(ArrayList<CoolParent> p){
        String name;
        String secondName;
        int age;
        String sex;
        int pocketMoney;
        Scanner sn = new Scanner(System.in);
        System.out.println("Введите имя: ");
        name = sn.nextLine();
        System.out.println("Введите отчество: ");
        secondName = sn.nextLine();
        System.out.println("Введите пол: ");
        sex = sn.nextLine();
        System.out.println("Введите возраст: ");
        age = sn.nextInt();
        System.out.println("Введите карманные деньги: ");
        pocketMoney = sn.nextInt();
        CoolParent pa1 = new CoolParent(name, secondName, age, sex, pocketMoney);
        p.add(pa1);
    }
}
