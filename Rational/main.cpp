#include <iostream>
#include <iostream>
class player
{
private :
    int iddd ;
    std::string name ;
public :
    player (int id_val ,std::string name_val) ;
    player( const player & source) ;
    double get_iddd (){
        return iddd ;
    };
    double get_name (){
        return name ;
    };

    ~ player () {

player(int id_val ,std::string name_val)
{
    iddd = id_val ;
    name = name_val ;
};
 player (const player & source ):iddd (source .iddd ) ,name (source . name )
{
    cout << "copy constructor 0"<< endl ;
} ;
};
 void display (player p)
    {
        cout << p . get_iddd << endl ;

        cout << p . get_name << endl ;

    }

int main()
{
    string reyaad ;
    int id = 32 ;
  player obj ;
 player obj(id, reyaad) ;
 display (obj) ;
    return 0;
}
