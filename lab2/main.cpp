#include <iostream>

using namespace std;
class circle
{

    private :

    float radius , area ;
    float  diameter , circumference ;
    static int counter ;

    public :
         circle ()
         {
             counter++ ;
         }

         void setdiameter (int roi)
         {
             radius =roi ;
             diameter = 2 * roi ;
         }
         void setcircumference()
         {
             circumference = 2 * 3.14 * radius ;
         }
         void setarea()
         {
             area =  3.14 * radius * radius ;

         }
         double getcircumference()
         {
             return circumference ;
         }
         double getarea()
         {
             return area  ;
         }
         static double getcounter()
         {
             return counter  ;
         }



};
int circle :: counter = 0 ;

int main()
{ circle k ;
cout << k . getcircumference () ;
cout << k .getarea() ;
cout << k. getcounter  ;

    return 0;
}
