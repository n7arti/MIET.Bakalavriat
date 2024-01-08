using System.Linq;

namespace Lab3
{
    public static class Program
    {
        static List<Branch> branches;
        static List<char> P;
        static List<char> Z;
        static List<Stop> stops = new List<Stop>();
        static List<string> Solve = new List<string>();
        static List<string> strings = new List<string>();
        class Branch
        {
            public char start_state;
            public List<string> end_states = new List<string>();

        }
        class Stop
        {
            public int char_st = 0;
            public int branch_st = 0;
            public int end_st;
        }
        public static string reverse(String str)
        {
            char[] chars = str.ToCharArray();
            Array.Reverse(chars);
            return new string(chars);
        }
        public static void parse(String str)
        {
            string notterminal = "QWERTYUIOPASDFGHJKLZXCVBNM";
            if (str != null)
            {
                Branch br = new Branch();
                if (!Z.Contains(str[0]))
                    Z.Add(str[0]);
                br.start_state = str[0];
                str = str.Substring(2);
                while (str.IndexOf('|') != -1)
                {
                    br.end_states.Add(reverse(str.Substring(0, str.IndexOf('|'))));
                    str = str.Substring(str.IndexOf('|') + 1);
                }
                br.end_states.Add(reverse(str));
                foreach (string s in br.end_states)
                {
                    foreach (char c in s)
                    {
                        if (!P.Contains(c) && !notterminal.Contains(c))
                            P.Add(c);
                    }
                }
                branches.Add(br);
            }
        }
        public static bool checkSTR(String str, string inputstr, string outputstr)
        {
            string str_new = str;
            foreach (char ch in str)
            {
                inputstr = ch + inputstr;
                outputstr += ch;
                str_new = str_new.Substring(1);
                foreach (Branch branch in branches)
                {
                    foreach (string s in branch.end_states)
                    {
                        Console.WriteLine("state" + branch.start_state + " " + s);
                        if (outputstr.Contains(s))
                        {
                            outputstr = outputstr.Substring(0, outputstr.IndexOf(s)) + branch.start_state + outputstr.Substring(outputstr.IndexOf(s) + s.Length);

                            Solve.Add("(s0," + inputstr + ",h0" + outputstr + ")");
                            if (checkSTR(str_new, inputstr, outputstr))
                                Solve.Remove("(s0," + inputstr + ",h0" + outputstr + ")");

                        }
                    }


                }
            }
            Console.WriteLine("AAAAAAAAAAAAAaaaaa");
            if (outputstr.Equals("E"))
                return true;

            return false;
            //for (int i = stops.Last().char_st; i < str.Length; i++)
            //{
            //    Stop stop = new Stop();
            //    if (!P.Contains(str[i]))
            //        break;
            //    inputstr = str[i] + inputstr;
            //    outputstr += str[i];
            //    bool r = false;
            //    Console.WriteLine("(s0," + inputstr + ",h0" + outputstr + ")");
            //    for (int j = stops.Last().branch_st; j < branches.Count; j++)
            //    {
            //        for (int k = stops.Last().end_st; k < branches[j].end_states.Count; k++)
            //        {
            //            if (outputstr.Contains(branches[j].end_states[k]))
            //            {
            //                outputstr = outputstr.Substring(0, outputstr.IndexOf(branches[j].end_states[k])) + branches[j].start_state + outputstr.Substring(outputstr.IndexOf(branches[j].end_states[k]) + branches[j].end_states[k].Length);
            //                Console.WriteLine("(s0," + inputstr + ",h0" + outputstr + ")");
            //                stop.char_st = i + 1;
            //                stop.branch_st = j + 1;
            //                stop.end_st = k + 1;
            //                stops.Add(stop);
            //                r = true;
            //                break;
            //            }
            //        }
            //        if (r)
            //            break;
            //    }

            //}
            //Console.WriteLine("STR " + str);
            //if (!outputstr.Equals("E") || stops.Last().char_st == branches.Count || stops.Last().branch_st == branches.Count)
            //    checkSTR(str, inputstr, outputstr);

            //foreach (char c in str)
            //{
            //    //Console.WriteLine(c + "");
            //    if (!P.Contains(c))
            //        break;
            //    inputstr = c + inputstr;
            //    outputstr += c;
            //    bool r = false;
            //    //Console.WriteLine("(s0," + inputstr + ",h0" + outputstr + ")");
            //    foreach (Branch branch in branches)
            //    {
            //        foreach (string s in branch.end_states)
            //        {
            //            if (outputstr.Contains(s))
            //            {
            //                outputstr = outputstr.Substring(0, outputstr.IndexOf(s)) + branch.start_state + outputstr.Substring(outputstr.IndexOf(s) + s.Length);
            //                Console.WriteLine("(s0," + inputstr + ",h0" + outputstr + ")");
            //                r = true;
            //                break;
            //            }
            //        }
            //        if (r)
            //            break;
            //    }


            //}


            //Console.WriteLine("Строка может быть обработана");
            //Console.WriteLine("Строка не может быть обработана");

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
                    parse(line);

                } while (line != null);
                sr.Close();
            }
            catch (Exception e)
            {
                Console.WriteLine("Exception: " + e.Message);
            }
        }
        public static void outputSets()
        {
            Console.Write("P = { ");
            foreach (char c in P)
            {
                Console.Write(c + " ");
                Z.Add(c);
            }
            Console.WriteLine('}');

            Console.Write("Z = { ");
            foreach (char c in Z)
            {
                Console.Write(c + " ");
            }
            Console.WriteLine("h0 }");
        }
        public static void build1()
        {
            Console.WriteLine("(1)Команды для всех правил грамматики: ");
            foreach (Branch br in branches)
            {
                Console.Write("(s0,l," + br.start_state + ")={ ");
                foreach (string end_state in br.end_states)
                {
                    Console.Write("(s0," + end_state + ") ");
                }
                Console.WriteLine('}');
            }
        }
        public static void build2()
        {
            Console.WriteLine("(2)Команды для всех терминальных символов: ");
            foreach (char c in P)
            {
                Console.WriteLine("(s0," + c + "," + c + ")=(s0,l)");
            }
        }
        public static void build3()
        {
            Console.WriteLine("(3)Командa для перехода в конечное состояние: ");
            Console.WriteLine("(s0,l,h0)=(s0,l)");
        }
        public static void build()
        {
            build1();
            build2();
            build3();
        }
        public static void findall()
        {
            string notterminal = "QWERTYUIOPASDFGHJKLZXCVBNM";
            
            foreach (string end_state in branches[0].end_states)
            {
                strings.Add(end_state);
            }

            for (int i = 0; i < strings.Count; i++)
            {
                int count = 0;
                //Console.WriteLine(i);
                foreach (Branch branch in branches)
                {
                    foreach (string end_state in branch.end_states)
                    {
                        if (strings[i].Contains(branch.start_state) && !strings.Contains(strings[i].Substring(0, strings[i].IndexOf(branch.start_state)) + end_state + strings[i].Substring(strings[i].IndexOf(branch.start_state) + 1)))
                        {
                            strings.Add(strings[i].Substring(0, strings[i].IndexOf(branch.start_state)) + end_state + strings[i].Substring(strings[i].IndexOf(branch.start_state) + 1));
                            count++;
                        }
                    }
                    if (count > 0)
                        break;
                }
                count--;
                if (i - count < 0)
                    i = -1;
                else
                    i -= count;
                if (strings.Count > 10000)
                    break;
            }
            for (int i = 0; i < strings.Count; i++)
            {
                //Console.WriteLine(i + " " + strings[i]);
                foreach (char ch in notterminal)
                    if (strings[i].Contains(ch))
                    {
                        strings.Remove(strings[i]);
                        if (i - 2 >= 0)
                            i-=2;
                    }
            }
            //foreach (string str in strings)
            //    Console.WriteLine(str);



        }
        public static void Main()
        {
            String path = "D:\\4 курс 1 семестр\\ТАЯК\\Lab3\\Lab3\\test1.txt";
            branches = new List<Branch>();
            stops.Add(new Stop());
            P = new List<char>();
            Z = new List<char>();
            String input;

            inputfile(path);
            outputSets();
            build();
            findall();

            while (true)
            {
                Console.Write("Введите строку: ");
                input = Console.ReadLine();
                Console.WriteLine("(s0,l,h0)");
                //checkSTR(reverse(input), "", "");

                foreach (string str in strings)
                    if (str.Equals(input))
                        Console.WriteLine("Строку можно обработать");
            }

        }
    }
}