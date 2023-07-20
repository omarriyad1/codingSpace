#include <iostream>

using namespace std;

int main()
{
    int sixe , odd = 0 ,
      even = 0  ;
    cout << " enter sixe ";
    cin >> sixe ;
    int * nuurr = new int [sixe] ;
    for ( int i = 0 ; i < sixe  ; i ++)

    {
        cout <<"enter nuurr ["<< i << ']' <<endl;
        cin  >>nuurr[i] ;
        if( nuurr[i] % 2 != 0 )
        {
            odd = odd + 1 ;
        }
        else
            even = even +1 ;
    }
    if ( even > odd )
    {
        cout << "its lucky " ;
    }
    else
         cout << "its not lucky " ;
    return 0;
}
