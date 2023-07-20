#include <iostream>

using namespace std;
class node
{
public :

    int info ;
    node*next ;

   /* node(int l)
    {
        info = l;
    }*/

};

void Printlist(node* n)
    {

        while (n!=NULL)
        {

            cout << n->info<< "   " ;
            n = n->next ;

        }
    }
   void removee (int mero, node*first)
    {
         node * temp = new node() ;
        if (first->info == mero  )
                { first = temp ;
                    first = first->next;
                    delete temp ;

                }
       node * ptrr = new node() ;
        while (first !=NULL)
        {
            if (first -> info == mero)
                {
                    ptrr->next = first ->next;
                }
            else

                 ptrr = first ;
                 first = first->next ;


        }



    }
   /* void removee (int mero, node*first)
    {
        node * ptrr = new node() ;
        ptrr = first ;
        first = first->next ;

        while (first !=NULL)
        {
            if (first -> info == mero)
            {
               ptrr->next = first ->next;
            }


        }
    }*/
int main()
{
   /* node*head = new node(2);
    node*second = new node(5);
    node*third = new node(6);*/
    node*Head = new node();

    node*second = new node();

    node*third = new node();
    Head->info=31;
    Head -> next = second ;
    second -> next =third  ;
    node * fourth = new node ();
    node * ff = new node ();
    third -> next =fourth;
    fourth -> info =31 ;
    fourth-> next =ff  ;
    ff -> info =60 ;
    ff-> next =NULL  ;

    second->info=7;
    third->info=10;

     Printlist(Head);
       removee(31,Head);
       cout << endl;

       Printlist(Head);


    return 0;
}
