//omar abdelmoneam riad ibrahim __20206045
//omar sayed ramadan__20206042
#include <iostream>
#include <string>
#include"Node.h"
#include"SLL.h"
#include"StackSLL.h"
#include"QueueSLL.h"
using namespace std;

string convertToBinary(int decimallNUM)
{
    string binary;
    int mn = decimallNUM, z;
    StackSLL<int> CON;
    if (decimallNUM == 0) {
        return "0";
    }
    while (mn > 0)
    {

        z = mn % 2;
        CON.push(z);
        mn = mn / 2;
    }

    while (!CON.isEmpty())
    {
        binary.append(to_string(CON.top()));
        CON.pop();
    }
    return binary;
}
string convertInfixToPostfix(string exppp)
{
    StackSLL <char>* stack;
    stack = new StackSLL<char>;
    string postfxxx;
    int counttt = 0;
    for (int i = 0; i < exppp.length(); i++) {
        if (exppp[i] == '+' || exppp[i] == '*' || exppp[i] == '/' || exppp[i] == '-') {
            if (stack->top() < exppp[i] || stack->isEmpty() || counttt < 2) {

                if (exppp[i] == '*') {
                    stack->push(46);
                }
                else
                    stack->push(exppp[i]);
            }
            else {
                if (stack->top() == 46) {
                    postfxxx += '*';
                    stack->pop();
                    stack->push(exppp[i]);
                }
                else {

                    postfxxx += stack->top();
                    stack->pop();
                    stack->push(exppp[i]);
                    counttt = 1;
                }
            }
        }
        else {
            postfxxx += exppp[i];
            if (exppp[i] != ' ')
                counttt++;
        }
    }
    while (!stack->isEmpty()) {
        postfxxx += stack->top();
        stack->pop();
    }
    return postfxxx;
}
int evaluatePostfix(string input) {
    StackSLL<int> s;
    int k, l, inn, sum;
    for (int i = 0; i < input.length(); ++i) {
        if (input[i] == '+') {
            k = s.top();
            s.pop();
            l = s.top();
            s.pop();
            s.push(l + k);
        }
        else if (input[i] == '-') {
            k = s.top();
            s.pop();
            l = s.top();
            s.pop();
            s.push(l - k);
        }
        else if (input[i] == '*') {
            k = s.top();
            s.pop();
            l = s.top();
            s.pop();
            s.push(l * k);
        }
        else if (input[i] == '/') {
            k = s.top();
            s.pop();
            l = s.top();
            s.pop();
            s.push(l / k);
        }
        else if (input[i] == ' ') {
            continue;
        }
        else {
            inn = input[i] - '0';
            s.push(inn);
        }
    }
    sum = s.top();
    return sum;
}
template<class T>
bool moveNthElem(QueueSLL<T>& qu, int nth) {
    QueueSLL<T> qu2;
    T element;
    int size = 0;
    SLL<T>list;
    while (!qu.isEmpty()) {
        list.addtoTail(qu.dequeue());
        size++;
    }
    while (!list.isEmpty()) {
        qu.enqueue(list.getValueAtHead());
        list.removeFromHead();
    }
    if (size >= nth) {
        for (int i = 0; i < nth - 1; ++i) {
            qu2.enqueue(qu.dequeue());
        }
        element = qu.dequeue();
        while (!qu.isEmpty()) {
            qu2.enqueue(qu.dequeue());
        }
        qu.clear();
        qu.enqueue(element);
        while (!qu2.isEmpty()) {
            qu.enqueue(qu2.dequeue());
        }
        return true;
    }
    return false;
}
bool chkBalanced(string exp) {
    StackSLL<char> CHK;
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[') {
            CHK.push(exp[i]);
            continue;
        }
        else if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') {
            if ((CHK.top() == '{' && exp[i] == '}') || (CHK.top() == '(' && exp[i] == ')') || (CHK.top() == '[' && exp[i] == ']')) {
                CHK.pop();
            }
            else
                return false;
        }
        else
            continue;
    }
    if (CHK.isEmpty())
        return true;
    else
        return false;
}
template<class T>
void reverseQueue(QueueSLL<T>& quu) {
    StackSLL<T> s;
    while (!quu.isEmpty())
        s.push(quu.dequeue());

    while (!s.isEmpty()) {
        quu.enqueue(s.top());
        s.pop();
    }
}
int main()
{
    int x;

    cout << "1- Check for balanced brackets." << endl;
    cout << "2- Convert to binary" << endl;
    cout << "3- Convert infix to postfix expression and evaluate." << endl;
    cout << "4- Move Nth element to front in a queue of strings." << endl;
    cout << "5- Reverse elements of a queue of doubles." << endl;

    cout << "enter option number :";
    cin >> x;
    if (x == 1) {
        string y;
        cout << "please enter the string : ";
        cin.ignore();
        getline(cin, y);
        if (chkBalanced(y))
            cout << "balanced";
        else
            cout << "imbalanced";
    }
    else if (x == 2) {
        int c;
        cout << "enter decimal number : ";
        cin >> c;
        cout << convertToBinary(c);
    }
    else if (x == 4) {
        cout << "Enter size :";
        int s;
        cin >> s;
        cout << "Enter strings";
        int name;
        QueueSLL<int> qu;
        while (s--) {
            cin >> name;
            qu.enqueue(name);
        }
        cout << qu;
        int n;
        cout << "Enter n : ";
        cin >> n;
        if (moveNthElem(qu, n))
            cout << qu;
        else
            cout << "Out of range.";

    }
    else if (x == 3) {
        cout << "Enter infix : ";
        string s;
        cin.ignore();
        getline(cin, s);
        string newExp = convertInfixToPostfix(s);
        cout << "\nPost exp : " << newExp;
        cout << "\nevaluate result : " << evaluatePostfix(newExp);
    }
    else if (x == 5) {
        QueueSLL<double> qu;
        int n;
        cout << "enter n of numbers : ";
        cin >> n;
        double x = 0;
        while (n--) {
            cin >> x;
            qu.enqueue(x);
        }
        cout << qu << endl;
        reverseQueue(qu);
        cout << qu;
    }

    return 0;
}
