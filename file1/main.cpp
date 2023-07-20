#include <iostream>
#include<fstream>
using namespace std;

int main()
{
    fstream myfile ;
    myfile.open("mora",ios::out);
    if (myfile.is_open())
    {
        myfile<<"some words  \n";
        myfile<<"aaaaaaaaaaaaaaaaa\n";
        myfile.close() ;
    }
    return 0;
}
