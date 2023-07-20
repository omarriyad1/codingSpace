#include <iostream>

using namespace std;
class rectangle
{
private :
    int width ;
     int length ;
public :
    void setwidth (double ) ;
    void setlength(double );
    double getwidth( ) ;
    double getlength( );
    double getarea ( );
};
void rectangle :: setwidth(double w)
{
  width = w;
}
void rectangle :: setlength(double l)
{
  length= l ;
}

double rectangle:: getlength ()
{
    return length ;
}
double rectangle:: getwidth ()
{
    return width ;
}
double rectangle:: getarea ()
{
    return length * width ;
}



int main()
{
    rectangle box ;
    double rlength;
    double rwidth ;
    cout <<" enter length "<<endl ;
    cin >> rlength ;
    cout <<" enter width "<<endl ;
    cin >> rwidth ;
    box.setwidth(rwidth);
    box.setlength(rlength) ;

    cout << " area = "<< box.getarea() <<endl;

    return 0;
}
