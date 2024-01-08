using System;
using System.Linq;
using System.IO;
using System.Collections.Immutable;
using System.Collections;

namespace Lab2
{
    public static class Program
    {
        class Branch
        {
            public int begin;
            public string end;
            public char symbol;
        }
        class NewBranch
        {
            public int begin;
            public List<string> ends = new List<string>();
            public char symbol;
        }
        class Conformity
        {
            public string old_states;
            public string new_states;
        }
        static List<Branch> graph;
        static List<NewBranch> new_graph;
        static List<Conformity> conformities;
        static bool error;

        public static void check(String str)
        {
            String part1 = "";
            Branch branch = new Branch();
            if (str != null)
            {
                part1 = str.Split('=')[0];
                try
                {
                    branch.end = str.Split('=')[1];
                    //Convert.ToInt32(q2[i].Split('f', 'q')[1]);
                    branch.symbol = Convert.ToChar(part1.Split(',')[1]);
                    branch.begin = Convert.ToInt32(part1.Split(',')[0].Split('q')[1]);
                    graph.Add(branch);
                }
                catch
                {
                    Console.WriteLine("Строка должна быть введена в формате <q><N>,<C>=<q|f><N>");
                    error = true;
                }

            }
        }
        public static void checkSTR(String str)
        {
            char state = 'q';
            int state_n = 0;
            char nowchar = ' ';
            foreach (char c in str)
            {
                for (int i = 0; i < graph.Count; i++)
                {
                    if (state == 'q')
                    {
                        if (graph[i].begin == state_n && graph[i].symbol == c)
                        {
                            state_n = Convert.ToInt32(graph[i].end.Split('f', 'q')[1]);
                            state = graph[i].end.ToCharArray()[0];
                            nowchar = c;
                            break;
                        }
                    }
                    else break;
                }
            }
            if (nowchar == str.ToCharArray()[str.Length - 1] && state == 'f')
                Console.WriteLine("Строка может быть обработана");
            else Console.WriteLine("Строка не может быть обработана");

        }
        public static void inputfile(String path)
        {
            String line;
            Console.WriteLine("File:");
            try
            {
                StreamReader sr = new StreamReader(path);

                do
                {
                    line = sr.ReadLine();
                    Console.WriteLine(line);
                    check(line);

                } while (line != null);
                sr.Close();
            }
            catch (Exception e)
            {
                Console.WriteLine("Exception: " + e.Message);
            }
        }
        public static bool checkDeterminate()
        {
            for (int i = 0; i < graph.Count - 1; i++)
            {
                for (int j = i + 1; j < graph.Count; j++)
                {
                    if (graph[i].begin == graph[j].begin && graph[i].symbol == graph[j].symbol)
                    {
                        Console.WriteLine("Граф недетерменирован");
                        return true;
                    }
                }
            }
            Console.WriteLine("Граф детерменирован");
            return false;
        }
        public static void determinate()
        {
            bool contain = false;
            int count = 1;
            string end = "";
            Branch det_branch;
            NewBranch branch;
            Conformity conformity = new Conformity();

            //формирует ветки формата q1,s=[q2,q3,q4]
            for (int i = 0; i < graph.Count; i++)
            {
                branch = new NewBranch();
                //добавляет конечные состояния и проверяет существует ли данная ветка в новом графе
                for (int j = 0; j < new_graph.Count; j++)
                {
                    if ((new_graph[j].begin == graph[i].begin) && (new_graph[j].symbol == graph[i].symbol))
                    {
                        if (!new_graph[j].ends.Contains(graph[i].end))
                        {
                            new_graph[j].ends.Add(graph[i].end);
                        }
                        contain = true;
                        break;
                    }
                }

                if (!contain)
                {
                    branch.begin = graph[i].begin;
                    branch.ends.Add(graph[i].end);
                    branch.symbol = graph[i].symbol;
                    new_graph.Add(branch);

                }
                contain = false;
            }
            //очищает изначальный граф, чтобы в него записать детерминированный добавляет первое соответствие старых и новых вершин
            graph = new List<Branch>();
            
            conformity.old_states = "q0";
            conformity.new_states = "q0";
            conformities.Add(conformity);

            for (int i = 0; i < new_graph.Count; i++)
            {
                //сортирует конечные состояния и переводит их в строку
                new_graph[i].ends.Sort();
                string ends_state = "";
                foreach (string c in new_graph[i].ends)
                {
                    if (c == new_graph[i].ends[new_graph[i].ends.Count() - 1])
                        ends_state += c;
                    else
                        ends_state += c + ',';
                }

                //есть ли данное конечное состояние в соответвии в старых состояниях
                contain = false;
                foreach (Conformity c in conformities)
                {
                    if (c.old_states == ends_state)
                        contain = true;
                }

                //добовляет новое соотвествие
                if (!contain)
                {
                    conformity = new Conformity();
                    conformity.old_states = ends_state;
                    if (ends_state.Contains('f'))
                        conformity.new_states = ends_state;
                    else
                    {
                        conformity.new_states = 'q' + count.ToString();
                        count++;
                    }
                    conformities.Add(conformity);
                }

                //Находим конечное состояние в соответсвии, находим начальное,
                //меняем старое значение на новое, добавляем в детерминированный граф
                foreach (Conformity c in conformities)
                {
                    if (ends_state == c.old_states)
                    {
                        end = c.new_states;

                        foreach (Conformity c2 in conformities)
                        {
                            contain = false;
                            foreach (string old_state in c2.old_states.Split(','))
                            {
                                if (!old_state.Contains('f'))
                                    if (Convert.ToInt32(old_state.Split('q')[1]) == new_graph[i].begin)
                                    {
                                        contain = true;
                                        break;
                                    }
                            }
                            if (contain)
                            {

                                det_branch = new Branch();
                                det_branch.end = end;
                                det_branch.begin = Convert.ToInt32(c2.new_states.Split('q')[1]);
                                det_branch.symbol = new_graph[i].symbol;
                                graph.Add(det_branch);
                            }

                        }
                    }
                }
            }
            Console.WriteLine("Соответсвие:");
            foreach(Conformity c in conformities)
            {
                Console.WriteLine(c.old_states+ "->" + c.new_states);
            }
            Console.WriteLine("Детерминированный конечный автомат: ");
            foreach (Branch b in graph)
            {
                Console.WriteLine("q" + b.begin + "," + b.symbol + '=' + b.end);
            }
        }

        public static void Main()
        {
            String path = "D:\\4 курс 1 семестр\\ТАЯК\\Lab2\\Lab2\\var3_nd.txt";
            graph = new List<Branch>();
            new_graph = new List<NewBranch>();
            conformities = new List<Conformity>();
            error = false;
            String input;
            inputfile(path);
            if (!error)
            {
                if (checkDeterminate())
                    determinate();
                while (true)
                {
                    Console.Write("Введите строку: ");
                    input = Console.ReadLine();
                    checkSTR(input);
                }
            }

        }
    }
}