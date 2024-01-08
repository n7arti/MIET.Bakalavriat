package pack;
import java.util.Scanner;

public class start {
    static void model(){
        int num1 = 1;
        int num2 = 100;
        int num;
        int i = 1;
        String ans;
        while (true) {
            num = (num1 + num2) / 2;
            view(i + " Ваше число больше " + num + "?\nИспользуйте Да/Нет");
            ans = controller();
            while (true) {
                if (ans.equals("Да")) {
                    num1 = num + 1;
                    break;
                } else if (ans.equals("Нет")) {
                    num2 = num;
                    break;
                } else {
                    view("Используйте Да/Нет");
                    ans = controller();
                }
            }
                if (num1 == num2) {
                    view("Ваше число  " + num1 + "!");
                    break;
                }
                i++;
            }

        }
    static void view(String key){
        System.out.println(key);
    }
    static String controller(){
        Scanner ln = new Scanner(System.in);
        return ln.nextLine();
    }
    public static void main(String[] args){
        start.model();
    }
}
