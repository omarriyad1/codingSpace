#include <iostream>

using namespace std;
class sphere
{
private :
    double radius , area , volume ;
    static int counnter ;
public :
    sphere ()
    {
        counnter ++ ;
    }
    void setradius (double r)
    {
        radius = r ;

    }
    void setarea()
    {
        area = 4 * 3.14 * radius * radius ;

    }
    void setvolume ()
    {
        volume = (4/3)*3.14 *radius*radius * radius ;

    }

    double getarea()
    {
        return area ;
    }
    double getvolume()
    {
        return volume ;
    }
    double getcounter()
    {
        return counnter ;
    }


};
int sphere :: counnter = 0 ;

int main()
{
    double radtiz ;
    sphere kom ;
    sphere mom ;
   cout << "teezak" <<endl;
   cin >>radtiz ;
   kom.setradius(radtiz) ;
   kom.setarea() ;
   kom.setvolume() ;
   cout << kom . getarea () << endl ;
   cout << kom . getvolume () << endl ;
   cout << kom .  getcounter() << endl ;
    return 0;
}
