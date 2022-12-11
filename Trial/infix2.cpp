// Kaustubh Rai(21BCE0050)
// Q6-Implement a program to evaluate infix expressions.
// A6:
#include <iostream>
#include "stacklink.h"
#include "stacklink.cpp"
#include <bits/stdc++.h>
using namespace std;

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}
int applyOp(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
}
int evaluate(string tokens)
{
    int i;
    StackType<int> values;
    StackType<char> ops;

    for (i = 0; i < tokens.length(); i++)
    {

        if (tokens[i] == ' ')
            continue;

        else if (tokens[i] == '(')
        {
            ops.Push(tokens[i]);
        }

        else if (isdigit(tokens[i]))
        {
            int val = 0;

            while (i < tokens.length() &&
                   isdigit(tokens[i]))
            {
                val = (val * 10) + (tokens[i] - '0');
                i++;
            }

            values.Push(val);
        }
        else if (tokens[i] == ')')
        {
            while (!ops.IsEmpty() && ops.Top() != '(')
            {
                int val2 = values.Top();
                values.Pop();

                int val1 = values.Top();
                values.Pop();

                char op = ops.Top();
                ops.Pop();

                values.Push(applyOp(val1, val2, op));
            }

            if (!ops.IsEmpty())
                ops.Pop();
        }

        else
        {
            while ((!ops.IsEmpty()) && precedence(ops.Top()) >= precedence(tokens[i]))
            {
                int val2 = values.Top();
                values.Pop();

                int val1 = values.Top();
                values.Pop();
                char op = ops.Top();
                ops.Pop();

                values.Push(applyOp(val1, val2, op));
            }

            ops.Push(tokens[i]);
        }
    }

    while (!ops.IsEmpty())
    {
        int val2 = values.Top();
        values.Pop();

        int val1 = values.Top();
        values.Pop();

        char op = ops.Top();
        ops.Pop();

        values.Push(applyOp(val1, val2, op));
    }
    return values.Top();
}
int main()
{

    string infix;

    cin >> infix;
    cout << evaluate(infix);
    return 0;
}
