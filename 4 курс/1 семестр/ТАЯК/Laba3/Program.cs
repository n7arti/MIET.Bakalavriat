using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Lab3
{
    class Program
    {
        class Command
        {
            public int state = 0;
            public string word = "l";
            public string text = "";
            public int new_state = 0;
            public string new_text = "";
        }

        static List<Command> Parse (string[] str)
        {
            List<Command> commands = new List<Command>();
            string P="", Z="";
            string letters = "QWERTYUIOPASDFGHJKLZXCVBNM";
            string notTerminal ="";
            int count=0;
            for (int i=0; i<str.Count(); i++)
            {
                for (int j=0; j<str[i].Length; j++)
                {
                    if ((str[i][j] != '>') && (str[i][j] != '|'))
                    {
                        if (!Z.Contains(str[i][j]))
                            Z += str[i][j];
                        if (!letters.Contains(str[i][j])&&!P.Contains(str[i][j]))
                            P += str[i][j];
                    }
                    else
                    {
                        if (str[i][j] == '>')
                            count++;
                    }
                }
            }
            if (count > str.Count())
            {
                Z += ">";
                P += ">";
            }
            for (int i=0; i<Z.Length; i++)
            {
                if (letters.Contains(Z[i]) && !notTerminal.Contains(Z[i]))
                {
                    notTerminal += Z[i];
                }
                    
            }

            for (int i=0; i<str.Count(); i++)
            {
                char c = str[i][0];
                str[i] = str[i].Substring(str[i].IndexOf('>') + 1);
                while (str[i] != "")
                {
                    Command com = new Command();
                    com.state = 0;
                    com.word = "l";
                    com.text = c+"";
                    com.new_state = 0;
                    if (str[i].Contains('|'))
                    {
                        string t = str[i].Substring(0, str[i].IndexOf('|'));
                        com.new_text = "";
                        for (int j = t.Length-1; j >= 0; j--)
                        {
                            if (t[j] == ')')
                                com.new_text += '(';
                            else if (t[j] == '(')
                                com.new_text += ')';
                            else com.new_text += t[j];
                        }
                        str[i] = str[i].Substring(str[i].IndexOf('|') + 1);
                        commands.Add(com);
                    }
                    else
                    {
                        com.new_text = str[i];
                        commands.Add(com);
                        str[i] = "";
                    }
                        
                }  

            }

            for (int i = 0; i < P.Count(); i++)
            {
                Command com = new Command();
                com.state = 0;
                com.word = P[i].ToString();
                com.text = P[i].ToString();
                com.new_state = 0;
                com.new_text = "l";
                commands.Add(com);
            }

            Command com2 = new Command();
            com2.text = "h0";
            com2.new_text = "l";
            commands.Add(com2);

            Z += "h0";
            Console.WriteLine("P: " + P);
            Console.WriteLine("Z: " + Z);
            Console.WriteLine("(1)Команды для всех правил грамматики: ");
            foreach (Command c in commands)
                if(!c.word.Equals(c.text)&&!c.text.Equals("h0"))
                Console.WriteLine("(s" + c.state + "," + c.word + "," + c.text + ")=(s" + c.new_state + "," + c.new_text + ")");

            Console.WriteLine("(2)Команды для всех терминальных символов: ");
            foreach (Command c in commands)
                if (c.word.Equals(c.text))
                    Console.WriteLine("(s" + c.state + "," + c.word + "," + c.text + ")=(s" + c.new_state + "," + c.new_text + ")");
            Console.WriteLine("(3)Командa для перехода в конечное состояние: ");
            Console.WriteLine("(s0,l,h0)=(s0,l)");
            return commands;
        }

        static bool Check_string(List<Command> commands, string str, string state, int step, int max)
        {
            string str1;
            string state1;

            if ((str == "l") && (state == "h0"))
                return true;

            bool admissbility = false;            
            if (str == "")
                return false;

            if (step == max)
            {
                admissbility = false;
                return false;
            }

            for (int j=0; j<commands.Count(); j++)
            {
                if ((state[state.Length - 1].ToString() == commands[j].word) && (str[0].ToString() == commands[j].word))
                {
                    str1 = str.Remove(0, 1);
                    if (str1 == "")
                        str1 = "l";
                    state1 = state.Remove(state.Length - 1, 1);
                    
                    admissbility = Check_string(commands, str1, state1, step + 1, max);
                    if (admissbility == true)
                    {
                        Console.WriteLine("(s0," + str1 + "," + state1 + ")");
                        return true;
                    }
                        
                }

            }

               
            for (int j=0; j<commands.Count; j++)
            {
                if ((state[state.Length - 1].ToString() == commands[j].text) && (commands[j].word == "l"))
                {
                    state1 = state.Remove(state.Length - 1, 1) + commands[j].new_text;
                    str1 = str;
                    
                    admissbility = Check_string(commands, str1, state1, step + 1, max);
                    if (admissbility == true)
                    {
                        Console.WriteLine("(s0," + str1 + "," + state1 + ")");
                        return true;
                    }
                        
                }

            }
            if (admissbility == false)
                return false;  

            if ((str != "l") || (state != "h0"))
                return false;

            return false;
        }

        static void Main(string[] args)
        {
            bool errors;
            Console.OutputEncoding = Encoding.GetEncoding("utf-8");
            string path = @"test1.txt";
            int count = File.ReadAllLines(path).Length;
            string[] str = new string[count];
            string input;
            List<Command> commands = new List<Command>();
            using (StreamReader sr = new StreamReader(path, System.Text.Encoding.Default))
            {
                Console.WriteLine("File:");
                for (int i = 0; i < count; i++)
                {
                    str[i] = sr.ReadLine();
                    str[i] = str[i].Replace(" ", "");
                    Console.WriteLine(str[i]);
                }
            }
            commands = Parse(str);

            while (true)
            {
                Console.Write("Введите строку: ");
                input = Console.ReadLine();
                string state = "h0E";
        
                errors = Check_string(commands, input, state, 0, 100);
                if (errors)
                    Console.WriteLine("Строку можно разобрать");
                else
                    Console.WriteLine("Строку нельзя разобрать");

            }
        }
    }
}
