#include <iostream>

using namespace std;
class player
{
private :
    int iddd ;
   string name ;
public :
    double get_iddd (){
        return iddd ;
    }
    string get_name (){
        return name ;
    }


    void display (int id_val , string name_val )
    {
        cout << get_iddd() << endl ;

        cout << get_name()<< endl ;

    }
    player(int id_val ,string name_val)

   {
       iddd = id_val ;
       name = name_val ;
   }
   player (const player&source )
   {
      iddd = source.iddd ;
      name = source.name ;
      cout << "copy constructor 0"<< endl ;
   }



};

int main()
{
    string reyaad  = "biibo";
    int id = 32 ;
 player obj(id ,reyaad) ;
obj .display(id , reyaad);

    return 0;
}

