package model;

import java.sql.Time;

public class Task {
    MYTime time;
    String text;
    Importance importance;

    public MYTime getTime() {
        return time;
    }

    public Task(MYTime time, String text, Importance importance) {
        this.time = time;
        this.text = text;
        this.importance = importance;
    }

    public void setTime(MYTime time) {
        this.time = time;
    }

    public String getText() {
        return text;
    }

    public void setText(String text) {
        this.text = text;
    }

    public Importance getImportance() {
        return importance;
    }

    public void setImportance(Importance importance) {
        this.importance = importance;
    }

    public String toString(){
        return time + " "+ text+" "+ importance;
    }

    public String toSave() {
        return time.hour + System.getProperty("line.separator") + time.minute + System.getProperty("line.separator") + text + '\n' + importance + '\n';
    }

}
