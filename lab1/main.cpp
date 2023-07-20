#include <iostream>

using namespace std;
double upper_m (double* mosalah  ,int eldon)
{
    cout << "enter the size of arr " <<endl ;
    cin >> eldon ;

    double avr ;
    int  sum =0 ;
    int counter = 0 ;
    mosalah =new double [eldon] ;
   for ( int ion = 0 ; ion < eldon ;ion ++)
   {
       cout << "enter mosalah[" <<ion<<"]"<< endl ;
       cin >> mosalah[ion] ;
       sum = sum + mosalah[ion] ;
   }
   avr = sum / eldon ;
   for ( int kon = 0 ; kon < eldon ;kon ++ )
   {
       if (mosalah[kon ] > avr)
       {
           counter ++ ;

       }
       else{
        continue ;
       }


   }
   cout << counter<< endl  ;



return counter ;

}
int main()
{

    int donn ;
    double * abumaka ;
    upper_m ( abumaka , donn) ;
    return 0;
}
