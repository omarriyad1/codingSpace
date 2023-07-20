#include <iostream>

using namespace std;
void swap(double * ptr1 ,double * ptr2 ,double * ptr3 )
{
    cout << *ptr1 <<" "<< *ptr2 <<"   "<< *ptr3 ;
    double temp ;
    temp = *ptr2 ;
    *ptr2 = *ptr1 ;
    *ptr3 = temp ;
    cout << *ptr1<< "   " << *ptr2 <<"   "<< *ptr3;



}
int main()
{
    double zuul , zuua ,zuug ;
    zuul = 15 ;
    zuua = 500;
    zuug = 46 ;

    swap(&zuul , &zuua ,&zuug ) ;
    cout << zuul<< '  ' << zuua << '  ' << zuug ;
    return 0 ;

}


