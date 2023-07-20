#include <iostream>

using namespace std;
void insertt(int A[] ,int n )
{
    int i = n , temp ;
    temp=A[i] ;
    while(i>1&& temp > A[i/ 2])
    {
        A[i] = A[i/2];
        i=i/2;
    }
    A[i]=temp;
}
int deletee (int A[] , int n)
{
    int i , j, x ,temp ,val ;
     x = A[n];
     val = A[1];
     A[1] = A[n];
     A[n]=val;
     i = 1 ;
     j = i * 2 ;
     while ( j< n - 1)
     {
         if (A[j+1 ] > A[j ])

             j = j+1 ;
             if (A[i]< A[j])
             {
                 temp = A[i];
                 A[i]= A[j];
                 A[j]= temp;
                 i= j;
                 j=2*j;
             }
             else
                break;
     }
     return val;
}
int heapsort (int A[] , int n)
{
    int i , j, x ,temp ,val ;
     x = A[n];
     val = A[1];
     A[1] = A[n];
     A[n]=val;
     i = 1 ;
     j = i * 2 ;
     while ( j< n - 1)
     {
         if (A[j+1 ] > A[j ])

             j = j+1 ;
             if (A[i]< A[j])
             {
                 temp = A[i];
                 A[i]= A[j];
                 A[j]= temp;
                 i= j;
                 j=2*j;
             }
             else
                break;
     }
     return val;
}
int main()
{

    int H[] = {0,10,20,30,25,5,40,35};
    for(int j = 2 ; j<= 7 ; j++)
    {
         insertt(H,j);
    }

//cout<<"deleted element is "<<deletee(H,6)<<endl;
/*for(int m=7 ; m>1 ;m--)
    {
        cout<<heapsort(H,m)<<endl;
    }*/
    cout<<"deleted element is "<<deletee(H,7)<<endl;
    for(int i=1 ; i<= 7 ;i++)
    {
        cout<<H[i]<<endl ;
    }

    return 0;
}
