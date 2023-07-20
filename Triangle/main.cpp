#include <iostream>

using namespace std;

class line
{
private :
    int * length ;
    static int linesCount ;
     int sizz ;
public :
    void setlength (int sizee)
    {
        sizz =sizee ;
        length = new int [sizee];
    }
    double getlength()
    {
        return length ;
    }
    line ()
    {
        linesCount ++ ;
    }
    double getcounter ()
    {
        return linesCount
    }
    line ()
    {

        for (int i = 0 ; i <sizz ;i++ )
        {
            length[i] = default ;
        }
    }
    line (const line & obj )
    {
        length = new int [sizz] ;
        for (int y =0 ;y < sizz ; y ++)
        {
           length [i] = obj . length[i] ;

        }
    }


};
line:: linesCount = 0 ;
int main()
{

    return 0;
}
