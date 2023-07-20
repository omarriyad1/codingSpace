#include <iostream>

using namespace std;
class circle
{
    private :
        double redius ;
    public :

        void setredius (double ) ;
        double grtarea();
        double getperimetar() ;


};
void circle :: setredius (double r)
{
    redius = r ;
}
double circle::getarea()
{
    return radius * radius * 3.14 ;
}
double circle :: getperimetar()
{
    return 2 * radius * 3.14 ;
}
int main()
{ double red ;
 cout << "enter redius"<< endl  ;
 cin >> red ;
 circle r ;
 r.getarea();
 r.getperimetar();
 cout << r.getarea << "--------"<< r.getperimetar ;

    return 0;
}
