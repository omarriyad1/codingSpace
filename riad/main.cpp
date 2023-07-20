#include <iostream>

using namespace std;
void insert(string vemo[6][7],string player, int x-countt,int o-countt ,int  roww ,int  columnn )
{
    while(x_counter < 4 || o_counter < 4)
    {
         cout << "enter the place (row , column) u will fill it" << endl ;
         cin >> row >> column ; /*to know the place */
         if (board [roww][columnn] != 'x' || board [roww][columnn] != 'o')
         {
             continue ;

         }
         else if (board [roww][columnn] != 'X' || board [roww][columnn] != 'O')
         {
             continue ;
         }
         else
         {
             cout << "it is empty" << endl;
             cout << "enter your tile " ;
             cin >> playermove ; /*to know the playermove*/
             if ( playermove== 'x' ||playermove == 'X' )

                {
                   board[roww][columnn] ='x' ;

                }
             else if ( playermove == 'o' ||playermove== 'O' )
             {
               board[roww][columnn] ='o' ;
             }
         }
         for (int i = 0 ; i < 6 ; i ++ )
         {
            for (int j = 0 ; j < 7 ; j++ )
            {
                if( board [i][j] =='x' || board [i][j] == 'X' )
                {
                  x-countt = x-countt + 1 ;
                }
                else if ( board [i][j] =='o' || board [i][j] == 'O' )
                {

                    o-countt = o-countt + 1 ;
                }
            }

         }
}


    }
    void isWinning()
    {
        if x-countt == 4
    }

int main()
{int board[6][7] ;
int x_counter = 0 , o_counter = 0 , row ,column ;
string tile ;

{









}

}
