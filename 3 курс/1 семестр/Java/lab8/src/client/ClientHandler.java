package client;

import java.io.*;
import java.net.InetAddress;
import java.net.Socket;

public class ClientHandler implements Runnable {
    private final String clientName;
    private boolean flag = true;
    private PrintStream out = null;

    public ClientHandler(String name) {
        clientName = name;

    }

    @Override
    public void run() {
        String clientCommand = "";


        System.out.println("Process started for : " + clientName);
        Socket socket = null;
        try {//получение строки клиентом
            InetAddress myIP = InetAddress.getLocalHost();
            socket = new Socket("localhost", 9090);
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            out = new PrintStream(socket.getOutputStream());

            while (!socket.isOutputShutdown()) {
                Thread.sleep(2000);

                if (in.read() > -1) {
                    System.out.println("Читаем с сервера: " + clientName);
                    String msg;
                    while (!(msg = in.readLine()).equals("~"))
                        System.out.println(msg);
                }

                if (flag) {
                    out.println("~IP~" + myIP + " " + clientName);
                    out.flush();
                    flag = false;
                }
                // ждём консоли клиента на предмет появления в ней данных

                if (clientCommand.contains("quit")) {
                    System.exit(0);
                }
                System.out.println("Клиент печатает...");
                //Thread.sleep(1000);
                clientCommand = br.readLine();


                out.println(clientCommand);
                out.flush();
                System.out.println("Клиент отправляет сообщение " + clientCommand);


            }

        } catch (Exception e) {
            System.out.println("ОООООООООООООшибка: " + e);
        }

    }
    public static void main(String[] args){
        ClientHandler clientHandler = new ClientHandler("" + 0);
        clientHandler.run();
    }
}
