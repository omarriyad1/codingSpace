#include <iostream>
#include <string>

using namespace std;
template<class T>
class Node
{
 T info;
 Node* next;
public:
 Node(T data, Node*nnext =0)
 {
   info = data ;
   next = nnext;
 }
 Node* getNext()
 {
     return next ;

 }
 void setNext(Node*ptt )
 {
     next = ptt;

 }

 T getInfo ()
 {
     return info ;
 }
 void setInfo (T dataa)
 {
     info = dataa ;
 }
};

template<class T>
class SLL
{
 Node<T> *head, *tail;
public:
 SLL(){head = tail= 0;};
 void addtoHead(T info )
 {
     if(head == NULL) //if our list is currently empty
        {
           // head = new Node<T>; //Create new node of type T
            head->setInfo(info);
            tail = head;
        }
        else{
                  Node<T> * newnode ;
                  //newnode = new Node<T> ;
                 newnode->setInfo(info);
                 newnode->setNext(head);
                 head = newnode;
                 if (tail ==NULL)
                      {
                           tail = head  ;
                      }
        }



 }
 void addtoTail(T info )
 {
     if(tail == NULL) //if our list is currently empty
        {
           // head = new Node<T>; //Create new node of type T
            head->setInfo(info);
            tail = head;
        }
        else{
                  Node<T> * newnode ;
                 newnode->setInfo(info);
                 tail->setNext(newnode);
                 newnode->setNext(NULL);
                 tail = newnode;
        }


 }
 T removeFromHead()
 {

     if (head=tail ) //one node or nothing
     {
         head = tail= NULL ;
     }
     else
     {
         Node<T> * ptr=head;
         head =head->getNext();
         delete ptr;
     }
 }
 T removeFromTail()
 {
     Node<T> * ptr=head;
     if (head=tail ) //one node or nothing
     {
         head = tail= NULL ;
     }
     else
        {
            while(ptr->getNext() != tail)
            {
                ptr =ptr->getNext() ;
            }
            delete tail ;
            tail=ptr;
            tail->setNext(NULL);
        }

 }
 T getValueAtHead()//a function that returns the value at head without deleting it
 {
     cout<<head->getInfo()<< "  ";
     head->getInfo();
 }
 T getValueAttail()//a function that returns the value at tail without deleting it
 {
     cout<<tail->getInfo()<< "  ";
     tail->getInfo();
 }
 bool isEmpty()
 {
     if(head = tail = NULL )
     {
         return true;
     }
     else{
        return false ;
     }
 }
 void cleaar()
 {
     Node<T> * ptr=head;
     while(head.getNext() != NULL)
     {
         ptr=head;
         head=head.getNext();
         delete ptr ;
     }
 }
 friend ostream& operator<<(ostream&, const SLL<T>&);
};



template<class T>
class StackSLL
{
protected :
    SLL<T>LST;
public:
   T push(T data )
    {
        LST.addtoHead(data);

    }
    T pop()
     {
         LST.getValueAtHead();
         LST.removeFromHead();


     }
     T top()
     {
         {
         LST.getValueAtHead();
         }
     }

     T isEmpty()
     {
         LST.isEmpty();
     }
     T clear()
     {
         LST.cleaar();
     }


};

template<class T>
class QueueSLL
{
protected :
    SLL<T>QST;
public:

    T enqueue(T data)
    {
        QST.addtoHead(data);
    }
    T gettailvalue()
    {
        QST.getValueAtHead();
    }
    T addtohead(T data)
    {
        QST.addtoTail(data);
    }
     T dequeue()
     {
         QST.removeFromTail();
     }
     T front()
     {
         QST.getValueAttail();
     }
     T isEmpty()
     {
         QST.isEmpty();
     }
     T clear()
     {
         QST.cleaar();
     }
};



string convertToBinary(int decimal)
{
    string binary;
    int mn ;
    int i =0 ;
     StackSLL<int> * CON;
         CON = new StackSLL<int>;
         while (decimal > 0)
         {
             mn = decimal % 2 ;
              decimal = decimal / 2;
             CON->push(mn);
         }
         while (! CON->isEmpty())
         {
            binary[i]=CON->pop();
            i++;
         }
         cout << "binary number =" <<binary;
}
string convertInfixToPostfix(string infix)
{
         StackSLL<int> * CTP;
         CTP= new StackSLL<int>;
         int counter = 0 ;
         int countt = 0 ;
         char remind;
         char balance;
          for (int m = 0 ; m < infix.length(); m++ )
          {
                  if (infix[m]=='/' || infix[m]=='*')
                  {
                      if(counter == 1)
                      {
                              remind = infix[m];
                         //     balance= infix[m];

                              continue ;
                          }


                      else if(countt==1)
                          {
                              balance= infix[m];
                              continue ;
                          }

                      else
                      {
                              CTP->push(infix[m]);
                              counter=0;
                          }

                  }
                  else if (infix[m]=='+' || infix[m]=='-')
                  {
                      if(counter == 1)
                      {
                              remind = infix[m];
                         //     balance= infix[m];
                              continue ;
                          }


                      else if(countt==1)
                          {
                              balance= infix[m];
                              continue ;
                          }


                      else
                      {
                              CTP->push(infix[m]);
                              counter=0;
                          }

                      }
                  else
                  {
                      CTP->push(infix[m]);
                      if (counter==0)
                      {
                          counter++;
                      }
                      else
                      {
                              CTP->push(remind);
                              counter--;
                              countt++;
                      }



                  }
                  if (countt==2)
                  {
                      CTP->push(balance);
                      countt=0;
                  }

          }


};

int evaluatePostfix(string postfix)
{
    StackSLL<int> * EVP;
    EVP= new StackSLL<int>;
    int minsum [2] ;
    int i=0 ;
    int sum ;
    for(int n= 0; n < postfix.length() ; n++)
         {
             if (postfix[n]=='*')
             {
                 if (i==0)
                 {
                     for(int y= 0 ; y< 2; y++)
                     {
                         minsum[y]=EVP->pop();
                     }
                     sum = minsum[0] * minsum[1];
                     EVP->push(sum);
                 }
                 else
                 {
                 sum = minsum[0] * minsum[1];
                 EVP->push(sum);
                 i=0;
                 }
             }
             else if (postfix[n]=='/')
             {
                 if (i==0)
                 {
                     for(int y= 0 ; y< 2; y++)
                     {
                         minsum[y]=EVP->pop();
                     }
                     sum = minsum[1] / minsum[0];
                     EVP->push(sum);
                 }
                 else
                 {
                 sum = minsum[1] / minsum[0];
                 EVP->push(sum);
                 i=0;
                 }
             }
             else if (postfix[n]=='+')
             {
                 if (i==0)
                 {
                     for(int y= 0 ; y< 2; y++)
                     {
                         minsum[y]=EVP->pop();
                     }
                     sum =minsum[0] + minsum[1];
                     EVP->push(sum);
                 }
                 else
                 {
                 sum = minsum[0] + minsum[1];
                 EVP->push(sum);
                 i=0;
                 }

                /* sum = minsum[0] + minsum[1];
                 EVP->push(sum);
                 i=0;*/

             }
             else if (postfix[n]=='-')
             {
                 if (i==0)
                 {
                     for(int y= 0 ; y< 2; y++)
                     {
                         minsum[y]=EVP->pop();
                     }
                     sum =minsum[1] - minsum[0];
                     EVP->push(sum);
                 }
                 else
                 {
                 sum =  minsum[1] - minsum[0];
                 EVP->push(sum);
                 i=0;
                 }


             }
             else
             {
                 minsum[i] = postfix[n];
                 i++;

             }
         }
         EVP->top();
};

bool moveNthElem(QueueSLL<int>* queuee,int nposs)
{

    QueueSLL<int> * MNE;
    MNE= new QueueSLL<int>;
    int ti =0;
    int sam;
    for(int i =0 ; i< nposs ; i++ )
    {
        ti ++ ;
        if (nposs == i+1)
        {
             sam = queuee->front() ;
             queuee->dequeue();
        }
        else
        {
            MNE->enqueue(queuee->front());
            queuee->dequeue();

        }

    }
    for(int v =0 ; v < (nposs - 1) ; v++ )
    {
        queuee->addtohead(MNE->gettailvalue());
    }
    queuee->addtohead(sam);
    for(int i =0 ; i< nposs ; i++ )
    {
        queuee->front();
        queuee->dequeue();
    }
    if (ti==nposs)
    {
        return true;
    }
    else
    {
        return false ;
    }

};
//StackSLL<char>::
        // SLL<T>CHK;
       //   <char> *
  bool chkBalanced(string expression){
        StackSLL<char> * CHK;
         CHK = new StackSLL<char>;
         int abb=0;
         int bbb=0;
         int cbb=0;
         int dbb=0;
    for(int i = 0 ; i< expression.length();i++)
    {
         CHK->push(expression[i]);
         if (expression[i]=='{')
            {
               abb=abb +1;
            }
        else if (expression[i]=='<')
            {
              bbb=bbb +1;
            }
        else if (expression[i]=='[')
            {
               cbb = cbb +1;
            }
        else if (expression[i]=='(')
            {
              dbb = dbb +1;
            }
        else{
            return 0;
        }
    }
    for(int m = 0 ; m< expression.length();m++)
    {
         char vall = CHK->pop();
         if ( vall =='}')
            {
               abb=abb-1;
            }
        else if (vall=='>')
            {
              bbb=bbb-1;
            }
        else if (vall==']')
            {
               cbb=cbb-1;
            }
        else if (vall==')')
            {
              dbb=dbb-1;
            }
        else
        return 0;



    }
    if (abb==0)
    {
        if (abb==cbb )

        {
            if(bbb ==dbb)
            {
                cout<< "balanced"<<endl;
                return true;

            }
            else
            {
                cout<< "imbalanced"<<endl;
                return false;
            }


        }
        else
            cout<< "imbalanced"<<endl;
            return false;

    }
    else
        cout<< "imbalanced"<<endl;
        return false;


     }
template<class T>
void reverseQueue(QueueSLL<T>& Q){
    StackSLL<T> s;
    while (!Q.isEmpty())
    {
        s.push(Q.dequeue());
    }

    while (!s.isEmpty())
    {
         Q.enqueue(s.pop());
    }

};



int main()
{
    string exp;
        cout<<"please enter the string : ";
        cin>>exp;
        chkBalanced(exp);
    /*int x;
    cout<<"1- Check for balanced brackets."<<endl;
    cout<<"2- Convert to binary"<<endl;
    cout<<"3- Convert infix to postfix expression and evaluate."<<endl;
    cout<<"4- Move Nth element to front in a queue of strings."<<endl;
    cout<<"5- Reverse elements of a queue of doubles."<<endl;

    cout<<"enter option number :";
    cin>>x;
    if(x==1){
        string exp;
        cout<<"please enter the string : ";
        cin>>exp;
        chkBalanced(exp);

    }*/
   /* else if(x==2){

    }
    else if(x==3){

    }
    else if(x==4){

    }
    else if(x==5){

    }*/









    return 0;
}
