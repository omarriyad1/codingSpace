#include <iostream>

using namespace std;

template<class DataType>
struct Node{
Node * Next;
Node * Prev;
DataType Element;
};

template <class DataType>
class Doubly_Linked_List {
private:
    Node<DataType> * Head;
    Node<DataType> * Tail;
    int Current_Size;
public:
    Doubly_Linked_List(){
        Head = NULL;
        Tail = NULL;
        Current_Size = 0;
}
     void Add_First(DataType data){
            Node <DataType> * new_Node = new Node <DataType>;
            new_Node ->Element = data;
        if(Head == NULL)
        {
            Head = Tail = new_Node;
            new_Node->Next = NULL;
            new_Node->Prev = NULL;
        }
        else
        {
            Head->Prev = new_Node;
            new_Node->Next = Head;
            Head = new_Node;
        }
        Current_Size++;
    }

     void Add_Last(DataType data){
            Node<DataType> * new_Node = new Node <DataType>;
            new_Node->Element = data;
            new_Node->Next = NULL;
            if(Head == NULL)
            {
                new_Node->Prev = NULL;
                Head = Tail = new_Node;
            }
            else
            {
                new_Node->Prev = Tail;
                Tail->Next = new_Node;
                Tail = new_Node;
            }
            Current_Size ++;
    }

    void Remove_Last(){
            if(Head == NULL)
            {
                cout<<" List is Empty "<<endl;
                return ;
            }
            else if(Head == Tail){
                Head = Tail = NULL ;
                Current_Size --;
            }
            else{
                Tail->Prev->Next = NULL;
                Tail = Tail->Prev ;
                Current_Size --;
            }
    }

    void Remove_First(){
            if(Head == NULL)
            {
                cout<<" List is Empty "<<endl;
                return ;
            }
            else if(Head == Tail){
                Head = Tail = NULL;
                Current_Size --;
            }
            else{
                Head->Next->Prev = NULL;
                Head = Head->Next;
                Current_Size --;
            }
    }


 void remove_Element(int data)
    {
        Node<int> *p=Head;
        while(p!=NULL){
            if(p->Element==data)
                {
                    p-> prev->next = p->Next;
                    p->next->prev = p->Prev;
            }


        }




    }
//display the content of the list
    void Print_List() {
      Node<DataType>* temp = Head;
      if(temp != NULL) {
        cout<<"The list contains: ";
        while(temp != NULL) {
          cout<<temp -> Element<<" ";
          temp = temp -> Next;
        }
        cout<<endl;
      } else {
        cout<<"The list is empty.\n";
      }
    }

};
int main()
{
  Doubly_Linked_List<int> L  ;
	for(int i =1 ; i<10; i++)
	L.Add_First(i*2);
    L.Print_List();
//    L.Remove_Element(10);
    L.Print_List();
	  cout<<endl<<endl;
/*    L.Add_Last(50);
    L.Add_Last(50);
    L.Add_Last(50);
    L.Add_Last(50);
    L.Add_Last(50);
    L.Add_Last(50);
   L.Print_List();
   L.Remove_Element(50);
   L.Print_List();
   */
    return 0;
}
