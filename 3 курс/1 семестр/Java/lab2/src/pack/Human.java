package pack;

 public abstract class Human {
    protected String name;
    protected String secondName;
    protected int age;
    protected String sex;

    public Human(String name, String secondName, int age, String sex) {
        this.name = name;
        this.secondName = secondName;
        this.age = age;
        this.sex = sex;
    }

    public Human() {
        this.name = "Иван";
        this.secondName = "Иванович";
        this.age = 20;
        this.sex = "Мужчина";
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getSecondName() {
        return secondName;
    }

    public void setSecondName(String secondName) {
        this.secondName = secondName;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String getSex() {
        return sex;
    }

    public void setSex(String sex) {
        this.sex = sex;
    }

    @Override
    public String toString() {
        return "Имя: " + name + '\n' + "Отчество: " + secondName + '\n' + "Возраст: " + age + '\n' + "Пол: " + sex + '\n';
    }
}
