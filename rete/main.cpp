#include <iostream>

using namespace std;
void sew(int) ;
int main()
{
    int num ;
 cout << "enter num" << endl ;
 cin >> num ;
 sew (num) ;
    return 0;
}
void sew (int mom )
{


    for ( int i = 1 ; i <= mom; i++ )
    {
        for (int j = 1 ; j <= mom; j++ )
        {
            if (i == 1 || i ==mom )
            {
                cout << "*"  ;
            }
            else if (j == 1 || j ==mom )
            {
                cout << "*"  ;
            }
            else
            {
                cout << " " ;
            }
        }
         cout << "\n"  ;

    }
}




