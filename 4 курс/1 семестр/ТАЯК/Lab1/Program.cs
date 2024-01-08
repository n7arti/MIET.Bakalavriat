using System;
using System.Linq;
using System.Collections.Generic;
using System.Reflection.Metadata;

namespace Lab1
{
    public static class Program
    {
        public static bool check(string input)
        {
            int countOpen = 0, countClose = 0;

            for (int i = 0; i < input.Length; i++)
            {
                if (i < input.Length - 1)
                {
                    if ("+-/*^(".IndexOf(input[i]) != -1)
                    {
                        if ((i == 0) && (input[i] != '('))
                        {
                            Console.WriteLine("В начале строки не должно быть оператора");
                            return false;
                        }
                        if ("+-/*^)".IndexOf(input[i + 1]) != -1)
                        {
                            Console.WriteLine("Не должно быть два оператора подряд или оператор после открывающей скобки");
                            return false;
                        }
                    }
                }
                else if ("+-/*^(".IndexOf(input[i]) != -1)
                {
                    Console.WriteLine("В конце строки не должно быть оператора или открывающей скобки");
                    return false;
                }

                if (input[i] == '(')
                    countOpen++;
                if (input[i] == ')')
                    countClose++;
                if ((i < input.Length - 2) && (input[i] == 'p') && (input[i + 1] == 'o') && (input[i + 2] == 'w') && (input[i + 3] == '('))
                {
                    if (input[i + 4] == '-')
                    {
                        Console.WriteLine("Можно возвести в степень только положительные числа");
                        return false;
                    }

                    else
                        i += 2;
                }
                else if ((",;.+-/*()# ".IndexOf(input[i]) == -1) && (Char.IsNumber(input[i]) == false))
                {
                    Console.WriteLine("Встречен недопустимый символ");
                    return false;
                }
                if (",.".IndexOf(input[i]) != -1)
                {
                    while ("+-/*^)".IndexOf(input[i]) == -1)
                    {
                        i++;
                        if (i == input.Length)
                            break;
                        if (",.".IndexOf(input[i]) != -1)
                        {
                            Console.WriteLine("Встеречено две или более точки в числе");
                            return false;
                        }
                    }
                    i--;
                }
            }
            if (countOpen != countClose)
            {
                Console.WriteLine("Несоответствие количества открывающих и закрывающих скобок");
                return false;
            }
            return true;
        }
        public static void Polsk(string input)
        {
            string output = "";
            char operand;
            input = input.Replace(',', ' ');
            input = input.Replace('.', ',');
            input = input.Replace("pow", "^");

            Stack<char> operands = new Stack<char>();
            Stack<char> buff = new Stack<char>();
            for (int i = 0; i < input.Length; i++)
            {
                switch (input[i])
                {
                    case '(':
                        operands.Push(input[i]);
                        break;
                    case ')':
                        do
                        {
                            operand = operands.Pop();
                            if (!operand.Equals('('))
                            {
                                output += operand.ToString() + " ";
                            }

                        } while (!operand.Equals('('));
                        break;
                    case '+':
                        if (operands.Contains('*') || operands.Contains('/') || operands.Contains('+') || operands.Contains('-'))
                        {
                            if (operands.Contains('('))
                                do
                                {

                                    operand = (char)operands.Pop();
                                    if (operand.Equals('*') || operand.Equals('/') || operand.Equals('+') || operand.Equals('-'))
                                        output += operand.ToString() + " ";
                                    else
                                        buff.Push(operand);
                                } while (!operand.Equals('('));
                            else
                                do
                                {

                                    operand = (char)operands.Pop();
                                    if (operand.Equals('*') || operand.Equals('/') || operand.Equals('+') || operand.Equals('-'))
                                        output += operand.ToString() + " ";
                                    else
                                        buff.Push(operand);
                                } while (operands.TryPeek(out var temp));
                            while (buff.TryPeek(out var temp))
                            {
                                operand = (char)buff.Pop();
                                operands.Push(operand);
                            }
                        }
                        operands.Push(input[i]);
                        break;
                    case '-':
                        if (operands.Contains('*') || operands.Contains('/') || operands.Contains('+') || operands.Contains('-'))
                        {
                            if (operands.Contains('('))
                                do
                                {

                                    operand = (char)operands.Pop();
                                    if (operand.Equals('*') || operand.Equals('/') || operand.Equals('+') || operand.Equals('-'))
                                        output += operand.ToString() + " ";
                                    else
                                        buff.Push(operand);
                                } while (!operand.Equals('('));
                            else
                                do
                                {

                                    operand = (char)operands.Pop();
                                    if (operand.Equals('*') || operand.Equals('/') || operand.Equals('+') || operand.Equals('-'))
                                        output += operand.ToString() + " ";
                                    else
                                        buff.Push(operand);
                                } while (operands.TryPeek(out var temp));
                            while (buff.TryPeek(out var temp))
                            {
                                operand = (char)buff.Pop();
                                operands.Push(operand);
                            }
                        }
                        operands.Push(input[i]);
                        break;
                    case '*':
                        if (operands.Contains('*') || operands.Contains('/'))
                        {
                            if (operands.Contains('('))
                                do
                                {

                                    operand = (char)operands.Pop();
                                    if (operand.Equals('*') || operand.Equals('/'))
                                        output += operand.ToString() + " ";
                                    else
                                        buff.Push(operand);
                                } while (!operand.Equals('('));
                            else
                                do
                                {

                                    operand = (char)operands.Pop();
                                    if (operand.Equals('*') || operand.Equals('/'))
                                        output += operand.ToString() + " ";
                                    else
                                        buff.Push(operand);
                                } while (operands.TryPeek(out var temp));
                            while (buff.TryPeek(out var temp))
                            {
                                operand = (char)buff.Pop();
                                operands.Push(operand);
                            }
                        }
                        operands.Push(input[i]);
                        break;
                    case '/':
                        if (operands.Contains('*') || operands.Contains('/'))
                        {
                            if (operands.Contains('('))
                                do
                                {

                                    operand = (char)operands.Pop();
                                    Console.WriteLine("plus " + operand.ToString());
                                    if (operand.Equals('*') || operand.Equals('/'))
                                        output += operand.ToString() + " ";
                                    else
                                        buff.Push(operand);
                                } while (!operand.Equals('('));
                            else
                                do
                                {

                                    operand = (char)operands.Pop();
                                    Console.WriteLine("plus " + operand.ToString());
                                    if (operand.Equals('*') || operand.Equals('/'))
                                        output += operand.ToString() + " ";
                                    else
                                        buff.Push(operand);
                                } while (operands.TryPeek(out var temp));
                            while (buff.TryPeek(out var temp))
                            {
                                operand = (char)buff.Pop();
                                operands.Push(operand);
                            }
                        }
                        operands.Push(input[i]);
                        break;
                    case '^':
                        operands.Push(input[i]);
                        break;
                    default:
                        output += input[i].ToString();
                        if ((i != input.Length - 1) && !((input[i + 1].Equals(' ')) || (input[i + 1].Equals(',')) || (Char.IsNumber(input[i + 1]))))
                            output += " ";
                        break;
                }
            }

            while(operands.TryPeek(out var t))
                output += " " + operands.Pop().ToString();
            Console.WriteLine(output);
            Calculate(output);
        }
        public static void Calculate(string input)
        {
            input = input.Replace("  ", " ");
            string[] mas = input.Split(' ');
            double a;
            double b;
            Stack<string> result = new Stack<string>();
            foreach(string ch in mas)
            {
                switch (ch)
                {
                    case "+":
                        b = Convert.ToDouble(result.Pop());
                        a = Convert.ToDouble(result.Pop());
                        result.Push((a + b).ToString());
                        break;
                    case "-":
                        b = Convert.ToDouble(result.Pop());
                        a = Convert.ToDouble(result.Pop());
                        result.Push((a - b).ToString());
                        break;
                    case "*":
                        b = Convert.ToDouble(result.Pop());
                        a = Convert.ToDouble(result.Pop());
                        result.Push((a * b).ToString());
                        break;
                    case "/":
                        b = Convert.ToDouble(result.Pop());
                        a = Convert.ToDouble(result.Pop());
                        result.Push((a / b).ToString());
                        break;
                    case "^":
                        b = Convert.ToDouble(result.Pop());
                        a = Convert.ToDouble(result.Pop());
                        result.Push(Math.Pow(a,b).ToString());
                        break;
                    default:
                        result.Push(ch);
                        break;

                }
            }
            Console.WriteLine(result.Pop());
        }
        public static void Main()
        {
            Console.Write("Введите выражение: ");
            string input = Console.ReadLine();
            if (check(input))
                Polsk(input);
        }
        // 6*8+3*4-2/5 = 63
        // 61*8+32*4-21/5,3
        // 6*8+(3*4)-2/5
        // (3+4)*(5+6,18)-.31
        // (3+4)*(5+6,18)-.31+pow(2;4)
        // pow(pow(2;3);4)
        // pow(2;-4)
    }
}
