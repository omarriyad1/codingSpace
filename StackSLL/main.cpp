#include <iostream>
#include <string>

using namespace std;

template<class T>
class Node
{
    T info;
    Node* next;
public:
    Node() {}
    Node(T data, Node* nnext = 0)
    {
        info = data;
        next = nnext;
    }
    Node* getNext()
    {
        return next;

    }
    void setNext(Node* ptt)
    {
        next = ptt;

    }

    T getInfo()
    {
        return info;
    }
    void setInfo(T dataa)
    {
        info = dataa;
    }
};


template<class T>
class SLL
{
    Node<T>* head, * tail;
public:
    SLL() { head = tail = 0; }
    void addtoHead(T info)
    {
        Node<T>* n = new Node<T>(info, head);
        if (head == 0) //if our list is currently empty
        {
            // head = new Node<T>; //Create new node of type T
            head = tail = n;
        }
        head = n;



    }
    void addtoTail(T info)
    {
        Node<T>* n = new Node<T>(info);

        if (head == 0) //if our list is currently empty
        {
            // head = new Node<T>; //Create new node of type T
            head = tail = n;
        }
        else {
            tail->setNext(n);
            tail = n;
        }


    }
    T removeFromHead()
    {
        Node<T>* n = head;
        head = head->getNext();
        T x = n->getInfo();
        delete n;
        return x;
    }
    T removeFromTail()
    {
        Node<T>* n = head;//if has one node only
        Node<T>* n2 = new Node<T>;
        if (n->getNext() == 0) {
            T data = n->getInfo();
            delete n;
            head = 0;
            tail = 0;
            return data;
        }
        while (n->getNext() != 0) {
            n2 = n;
            n = n->getNext();
        }
        tail = n2;
        n2->setNext(0);
        T x = n->getInfo();
        delete n;
        return x;
    }
    T getValueAtHead()//a function that returns the value at head without deleting it
    {
        T x = head->getInfo();
        return x;
    }

    bool isEmpty()
    {
        if (head == 0) {
            return true;
        }
        else
            return false;

    }
    void clear()
    {

        Node<T>* n1 = head;
        Node<T>* n2 = new Node<T>;
        if (head == 0)//if empty
            return;
        while (n1->getNext() != 0) {
            n2 = n1;
            n1 = n1->getNext();
            delete n2;
        }
        delete n1;
        head = tail = 0;
    }
    Node<T>* getHead() { return head; }
    Node<T>* getTail() { return tail; }

    friend ostream& operator<<(ostream& s, const SLL<T>& l) {
        Node<T>* n = l.getHead();
        while (n != 0) {
            s << n->getInfo() << " ";
            n = n->getNext();
        }
        return s;
    }
};



template<class T>
class StackSLL
{
protected:
    SLL<T>LST;
public:
    SLL<T>* getStack() { return &LST; }
    void push(T data)
    {
        LST.addtoHead(data);

    }
    void pop()
    {
        if (!LST.isEmpty())
            LST.removeFromHead();
    }
    T top()
    {
        if (!LST.isEmpty())
            return LST.getValueAtHead();

    }

    bool isEmpty()
    {
        return LST.isEmpty();
    }
    void clear()
    {
        LST.clear();
    }

    friend ostream& operator<<(ostream& s, StackSLL<T>& st) {
        Node<T>* n = st.getStack()->getHead();
        while (n != 0) {
            s << n->getInfo() << " ";
            n = n->getNext();
        }
        return s;
    }
};


template<class T>
class QueueSLL
{
protected:
    SLL<T>QST;
public:
    SLL<T>* getQueue() { return &QST; }
    void enqueue(T data)
    {
        QST.addtoTail(data);
    }

    T dequeue()
    {
        if (!QST.isEmpty())
            return QST.removeFromHead();
    }
    T front()
    {
        if (!QST.isEmpty())
            QST.getValueAtHead();
    }
    bool isEmpty()
    {
        return QST.isEmpty();
    }
    void clear()
    {
        QST.clear();
    }
    friend std::ostream& operator<<(std::ostream& os, QueueSLL<T>& qu) {
        Node<T>* n = qu.getQueue()->getHead();

        while (n != 0) {
            os << n->getInfo() << " ";
            n = n->getNext();
        }
        return os;
    }
};




string convertToBinary(int decimal)
{
    string binary;
    int mn = decimal, x;
    StackSLL<int> CON;
    if (decimal == 0) {
        return "0";
    }
    while (mn > 0)
    {

        x = mn % 2;
        CON.push(x);
        mn = mn / 2;
    }

    while (!CON.isEmpty())
    {
        binary.append(to_string(CON.top()));
        CON.pop();
    }
    return binary;
}

int evaluatePostfix(string input) {
    StackSLL<int> s;
    int num1, num2, sum, in;
    for (int i = 0; i < input.length(); ++i) {
        if (input[i] == '+') {
            num1 = s.top();
            s.pop();
            num2 = s.top();
            s.pop();
            s.push(num2 + num1);
        }
        else if (input[i] == '-') {
            num1 = s.top();
            s.pop();
            num2 = s.top();
            s.pop();
            s.push(num2 - num1);
        }
        else if (input[i] == '*') {
            num1 = s.top();
            s.pop();
            num2 = s.top();
            s.pop();
            s.push(num2 * num1);
        }
        else if (input[i] == '/') {
            num1 = s.top();
            s.pop();
            num2 = s.top();
            s.pop();
            s.push(num2 / num1);
        }
        else if (input[i] == ' ') {
            continue;
        }
        else {
            in = input[i] - '0';
            s.push(in);
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
bool chkBalanced(string expression) {
    StackSLL<char> CHK;
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == '{' || expression[i] == '(' || expression[i] == '[' ) {
            CHK.push(expression[i]);
            continue;
        }
        else if (expression[i] == '}' || expression[i] == ')' || expression[i] == ']' ) {
            if ((CHK.top() == '{' && expression[i] == '}') || (CHK.top() == '(' && expression[i] == ')') || (CHK.top() == '[' && expression[i] == ']') )
                {
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
void reverseQueue(QueueSLL<T>& Q) {
    StackSLL<T> s;
    while (!Q.isEmpty())
        s.push(Q.dequeue());

    while (!s.isEmpty()) {
        Q.enqueue(s.top());
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
        //cout << "Enter infix : ";
        //string s;
        //cin.ignore();
        //getline(cin, s);
        //cout << evaluatePostfix(s);
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
