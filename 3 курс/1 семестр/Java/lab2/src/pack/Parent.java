package pack;

import java.util.ArrayList;
import java.util.Scanner;

public class Parent extends Human{
    protected int pocketMoney;

    public int getPocketMoney() {
        return pocketMoney;
    }

    public void setPocketMoney(int pocketMoney) {
        this.pocketMoney = pocketMoney;
    }

    public Parent(String name, String secondName, int age, String sex, int pocketMoney) {
        super(name, secondName, age, sex);
        this.pocketMoney = pocketMoney;
    }
    public Parent() {
        super();
        this.pocketMoney = 0;
    }
    @Override
    public String toString() {
        return "Имя: " + name + '\n' + "Отчество: " + secondName + '\n'
                + "Возраст: " + age + '\n' + "Пол: " + sex + '\n' + "Количество карманных денег: "+pocketMoney+'\n';
    }
    public static void addParent(ArrayList<Parent> p){
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
        Parent pa1 = new Parent(name, secondName, age, sex, pocketMoney);
        p.add(pa1);
    }
}
