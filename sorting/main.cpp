#include <iostream>

using namespace std;

int main()
{ int sizee , temp ;
    cout << " enter the size " ;
     cin >> sizee ;
   int * ghalba = new int [sizee];
    for (int u = 0 ; u < sizee ; u++)
   {
        cout <<"enter" << "ghalba[" << u << "] "<<endl ;
        cin >> ghalba[u] ;
   }

   for ( int i =0 ; i < sizee ; i ++ )
   {
       for ( int j = 0 ; j < sizee ; j ++)
       {
            if (ghalba[i] == ghalba[j] )
            {
                continue;
            }
            else if (ghalba[i] > ghalba[j] )
           {
               continue ;
           }
           else

            temp = ghalba [ i] ;
            ghalba[i] = ghalba[j] ;
            ghalba[j] = temp ;











       }

   }
   for (int y = 0 ; y < sizee ; y++)
   {
        cout << ghalba[y] << "  " ;
   }

    return 0;
}
