//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <iostream>
//using namespace std;
//#define NMAX 100
//
//typedef struct stack
//{
//	char element[NMAX]; 	//хранилище
//	size_t top;		 // индекс элемента в вершине стека. 
//} stack;
//
//void init(stack* st)
//{
//	st->top = 0;
//}
//
//void push(stack* st, char e)
//{
//	if (st->top < NMAX)
//	{
//		st->element[st->top] = e;
//		st->top++;
//	}
//	else
//		cout << "Error: stack overflow " << st->top << endl;
//}
//
//char pop(stack* st)
//{
//	char element;
//	if ((st->top) > 0)
//	{
//		st->top--;
//		element = st->element[st->top];
//		return element;
//	}
//	else
//	{
//		cout<<"Stack is empty!"<<endl;
//		return 0;
//	}
//}
//
//int stack_top(stack* st)
//{
//	if ((st->top) > 0)
//		return st->element[st->top - 1];
//	else
//		return 0;
//}
// 
//int isempty(stack* st)
//{
//	if ((st->top) == 0)
//		return 1;
//	else
//		return 0;
//}
//
//int main()
//{
//	stack* st;
//	char el[NMAX];
//	st = new stack[NMAX];
//	init(st);
//	cin>> el;
//	int n = strlen(el) + 1;
//	for (int i = 0; i < n; i++)
//	{
//		if (el[i] == '(' || el[i] == '[' || el[i] == '{')
//		{
//			push(st, el[i]);
//		}
//		else if
//			(
//				(el[i] == ')' && stack_top(st) != '(') ||
//				(el[i] == ']' && stack_top(st) != '[') ||
//				(el[i] == '}' && stack_top(st) != '{')
//				)
//		{
//			push(st, el[i]);
//		}
//		else if
//			(
//				(el[i] == ')' && stack_top(st) == '(') ||
//				(el[i] == ']' && stack_top(st) == '[') ||
//				(el[i] == '}' && stack_top(st) == '{'))
//		{
//			pop(st);
//		}
//	}
//
//	if (isempty(st) == 1)
//		cout << "Success" << endl;
//	else
//		cout << "No success" << endl;
//	delete[] st;
//}