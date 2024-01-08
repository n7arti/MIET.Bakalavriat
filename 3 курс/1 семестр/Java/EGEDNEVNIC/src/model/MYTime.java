package model;
import java.util.GregorianCalendar;

public class MYTime {
    int hour;
    int minute;

    public MYTime(int hour, int minute) {
        this.hour = hour;
        this.minute = minute;
    }

    public int getHour() {
        return hour;
    }

    public void setHour(int hour) {
        this.hour = hour;
    }

    public int getMinute() {
        return minute;
    }

    public void setMinute(int minute) {
        this.minute = minute;
    }

    public String toString(){
        String m = "";
        if (minute <10)
             m ="0"+minute;
        else m = minute+"";
        return hour+ ":"+m;
    }
}
