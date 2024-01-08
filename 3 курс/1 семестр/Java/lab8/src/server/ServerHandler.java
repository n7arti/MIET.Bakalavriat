package server;

import frame.MainFrame;
import server.LabServer;

import javax.swing.*;
import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.TimeUnit;

public class ServerHandler implements Runnable {
    public static Map<String, Socket> socketMass = new HashMap<>();
    private Socket connection;
    private BufferedReader br;
    private BufferedReader in;
    private PrintStream out;
    private String ipName;
    public String entry;
    public boolean mess = false;
    private static boolean debugMode = false;
    private Date date;

    public synchronized static void disconnect (String name) {
        System.out.println("Тут 1");
        for (int i = 0; i < socketMass.size(); i++) {
            System.out.println("Тут 2");
            if (socketMass.containsKey(name)) {
                System.out.println("Тут 3");
                socketMass.put("quit", socketMass.get(name));
                System.out.println(socketMass.get("quit"));
            }
        }
    }

    public ServerHandler(Socket socket) {
        try {
            connection = socket;
            br = new BufferedReader(new InputStreamReader(System.in));
            in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            out = new PrintStream(socket.getOutputStream());
            LabServer.clientCount++;

        } catch (IOException e) {
            System.out.println(e);
        }

    }

    public void quitEvent(long dateStart) {
        System.out.println("Начинаю удаление клиента " + ipName);

        date = new Date();
        long dateFinish = date.getTime();
        String mess = "";

        mess = "Получена команда на выход\n";
        mess += "Соединение прервано. Время вашего подключения - " +
                TimeUnit.MILLISECONDS.toHours(dateFinish - dateStart) + ":" +
                TimeUnit.MILLISECONDS.toMinutes(dateFinish - dateStart) + ":" +
                TimeUnit.MILLISECONDS.toSeconds(dateFinish - dateStart);
        mess += "\n~";
        out.println(mess);
        out.flush();
        MainFrame.delClients(ipName);
    }

    @Override
    public void run() {
        System.console();
        DateFormat connectTime = new SimpleDateFormat("HH:mm:ss");

        try {//посылка строки клиенту
            BufferedReader in = new BufferedReader(new InputStreamReader(connection.getInputStream()));
            PrintStream out = new PrintStream(connection.getOutputStream());
            date = new Date();
            long dateStart = date.getTime();

            out.println(" Соединение установлено" + "\n~");
            out.flush();
            System.out.println("Соединение установлено");
            while (!connection.isClosed()) {
                entry = in.readLine();

                System.out.println("Получено сообщение - " + entry);
                mess = true;
                if (entry.contains("quit")) {
                    quitEvent(dateStart);
                    break;
                } else if (entry.contains("~IP~")) {
                    ipName = entry.substring(4);
                    MainFrame.setClients(ipName);
                    socketMass.put(ipName, connection);
                } else if (entry.contains("your_Mega_Command")) {
                    ;
                } else {
                    out.println(" Ты прав, бро\n~");
                    out.flush();
                }

                if (socketMass.containsKey("quit")) {
                    System.out.println("Внутри");
                    if (connection == socketMass.get("quit")) {
                        quitEvent(dateStart);
                        socketMass.remove("quit");
                    }
                }
            }

            connection.close(); // разрыв соединения
        } catch (IOException e) {
            System.out.println("ошибка: " + e);
        }
    }
}
