package main;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;

import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.List;

public class JSONFile {

    static public void inFile(List<Group> groups){
        GsonBuilder builder = new GsonBuilder();
        Gson gson = builder.create();
        try (PrintWriter out = new PrintWriter(new FileWriter("schedule"))) {
            out.write(gson.toJson(groups));
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
