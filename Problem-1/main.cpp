#include <iostream>

using namespace std;
 int row = 6 ;
void memo( int boardd[][7], int tile , int col)
{

    cout << " enter your tile (x for player 1 & o for player 2 ) " ;
    cin >> tile ;
    cout << " enter the column u want to fill " ;
    cin >> col ;
    for ( int i = 0 ; i < 6  ; i ++ )
    {
        if (boardd[i][col] == 0|| boardd[i][col] == 0)
        {
            continue ;
        }
         else if (boardd[i][col] == 1 || boardd[i][col] == 1 )
        {
            continue ;
        }
        else

            boardd[i][col] = tile ;

            break ;

    }
    for (int i = 0 ; i <6 ; i ++)
    {
        for (int j = 0 ; j < 7 ; j ++)
        {
            cout << boardd[i][j] ;
        }
    }
}
void mario(int boarddd[][7] , int x_counter,int o_counter)
{
    for (int i = 0 ; i < 6 ; i++)
      {  x_counter  = 0 ;
       o_counter = 0 ;
          for (int j = 0 ; j < 7 ; j++)
          {
              if (boarddd[i][j] == 0 || boarddd[i][j] == 0 )
              {
               x_counter = x_counter + 1 ;
                o_counter = o_counter - o_counter ;
              }
              else if (boarddd[i][j] == 1 ||boarddd[i][j] == 1)
              {
                  o_counter = o_counter + 1 ;
                   x_counter = x_counter - x_counter ;
              }
              if ( x_counter >= 4 )
              {
                  cout << 'X' ;
                  break ;

              }
               else if ( o_counter >= 4 )
              {
                  cout << 'O' ;
                  break ;

              }
              else
               cout << "   " ;

          }

      }
      for (int i = 0 ; i < 7; i++)
      {int  x_counter  = 0 , o_counter = 0 ;
          for (int j = 0 ; j < 6 ; j++)
          {
              if (boarddd[i][j] == 0 ||boarddd[i][j] == 0 )
              {
               x_counter = x_counter + 1 ;
                o_counter = o_counter - o_counter ;
              }
              else if (boarddd[i][j] == 1 ||boarddd[i][j] == 1)
              {
                  o_counter = o_counter + 1 ;
                   x_counter = x_counter - x_counter ;
              }
              if ( x_counter >= 4 )
              {
                  cout << 'X' ;
                  break ;

              }
               else if ( o_counter >= 4 )
              {
                  cout << 'O' ;
                  break ;

              }
              else
               cout << "   " ;

          }

      }
     for (int i = 0 ; i < 6 ; i ++ )
     {
         for (int j = 0 ; j < 7 ; j++)
         {
             if (boarddd[i][i-2] == 0 || boarddd[i][i-2] == 0 )
             {
                  x_counter = x_counter + 1 ;
                o_counter = o_counter - o_counter ;
             }
             else if (boarddd[i][i-2] == 1 || boarddd[i][i-2] ==1 )
             {
                  o_counter = o_counter + 1 ;
                x_counter = x_counter - x_counter ;
             }
               else if (boarddd[i][i-1] == 0 || boarddd[i][i-1] == 0)
             {
                  x_counter = x_counter + 1 ;
                o_counter = o_counter - o_counter ;
             }
             else if (boarddd[i][i-1] == 1 || boarddd[i][i-1] == 1 )
             {
                  o_counter = o_counter + 1 ;
                x_counter = x_counter - x_counter ;
             }
              else if (boarddd[i][i] == 0 || boarddd[i][i] == 0 )
             {
                  x_counter = x_counter + 1 ;
                o_counter = o_counter - o_counter ;
             }
              else if (boarddd[i][i] == 1 || boarddd[i][i] == 1 )
             {
                  o_counter = o_counter + 1 ;
                x_counter = x_counter - x_counter ;
             }
               else if (boarddd[i][i+1] == 0 || boarddd[i][i+1] == 0 )
             {
                  x_counter = x_counter + 1 ;
                o_counter = o_counter - o_counter ;
             }
              else if (boarddd[i][i+1] == 1 || boarddd[i][i+1] == 1 )
             {
                  o_counter = o_counter + 1 ;
                x_counter = x_counter - x_counter ;
             }
              else if (boarddd[i][i+2] == 0 || boarddd[i][i+2] == 0 )
             {
                  x_counter = x_counter + 1 ;
                o_counter = o_counter - o_counter ;
             }
               else if (boarddd[i][i+2] == 1 || boarddd[i][i+2] == 1 )
             {
                  o_counter = o_counter + 1 ;
                x_counter = x_counter - x_counter ;
             }
              else if (boarddd[i][i+3] == 0 || boarddd[i][i+3] == 0 )
             {
                  x_counter = x_counter + 1 ;
                o_counter = o_counter - o_counter ;
             }
              else if (boarddd[i][i+3] == 1 || boarddd[i][i+3] == 1 )
             {
                  o_counter = o_counter + 1 ;
                x_counter = x_counter - x_counter ;
             }
             if ( x_counter >= 4 )
              {
                  cout << 'X' ;
                  break ;

              }
               else if ( o_counter >= 4 )
              {
                  cout << 'O' ;
                  break ;

              }
              else
               cout << "   " ;


         }

     }



}
int main()
{

    int playerstile ;
     int column ;
     int x_counterr = 0 ;
     int  o_counterr = 0 ;
     const int roww = 6 ;
      const int columnn = 7 ;
     int board[roww][columnn] ;
    while (x_counterr < 4 && o_counterr < 4 )
    {
       memo( board[roww][7]  ,playerstile , column ) ;
        mario( board[roww][column] , x_counterr ,  o_counterr) ;
    }
    return 0;
}
