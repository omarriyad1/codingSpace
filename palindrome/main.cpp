#include <iostream>

using namespace std;

int main()
{
    int index , counter;
    int * goal =new int [index] ;
    cout << "enter the index" ;
    cin >> index ;
    for (int i = 0 ; i < index ; i ++)
    {
         cout<<" enter goal[" << i << ']' << endl ;
        cin >> goal[i] ;
    }
    int lim ;
    lim = index / 2 ;
    for (int h = 0 ; h < lim ; h++)
    {
        if (goal [h] == goal [lim - h ])
    {
        counter = index -1 ;
         continue;
    }
    else
        counter = index ;
        break ;
    }

    for (int i = 0 ; i < index ; i ++)
    {
         cout<< goal[i] << "  " ;

    }
    if (counter == 0 )
    {
         cout<< "goal is plaindrome " << endl ;

    }
    else
         cout<< "goal is not  plaindrome " << endl ;




    return 0;
}
