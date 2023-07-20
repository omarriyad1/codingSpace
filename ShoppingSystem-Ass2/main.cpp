#include <iostream>
#include <cstring>
using namespace std;
class item
{
private :
    int id;
    string  name;
    int quantity;
    double  price ;
public :
    static int id_counter ;
    item ()
    {
        id = 0;
        name = "nobody" ;
        quantity = 0 ;
        price = 0 .0;
        id_counter++ ;
    }
    item  ( string namee,int quantityy, double pricee)
    {
         id = id_counter;
        name = namee ;
        quantity = quantityy ;
        price = pricee ;
    }
    item (const item & source)
    {
         id =source.id  ;
        name =source.name  ;
        quantity = source.quantity ;
        price = source.price ;
    }
  //  void setid (int Idd)
   // {
      //  id = Idd;
   // }
   // void setname(string namee)
   // {
    //    name = namee ;
    //}
   // void setquantity(double quantityye)
   // {
   //     quantity = quantityy;
  //  }
   // void setprice ( double pricee)
   // {
   //     price = pricee;
   // }
     int getid ()
    {
       return id ;
    }
    string getname()
    {
       return name ;
    }
    double getquantity()
    {
        return returnquantity ;
    }

    double getprice ()
    {
        return  price ;
    }
    bool operator ==(const item & rhs)
   {
       if (id==rhs.id && name==rhs.name) // lw nafs elname hatnadi += tzawd 3la ad el3dd (num )
       {
           return true ;
       }
       else
            return false ;

   }
    item operator +=(int num)
    {
        quantity = quantity + num ;
    }
     item operator -=(int num)
    {
        quantity = quantity - num ;

    }
    friend ostream & operator<<(ostream&os,const item & rhs )
    {
        os<<"name "<< rhs.name <<endl ;
        os<<"quantity "<< rhs.quantity<<endl ;
        os<<"price"<< rhs.price <<endl ;
    }
    friend istream & operator >> ( istream &is , const item & lhs )
    {
        is >> lhs.name >> lhs.quantity >> lhs . price ;
    }

};
class seller
{

private:
    string name ;
    string email ;
    int maxItems;
    item*arrayofitem;
    static int itemsNumber;
public :
    friend class item ;
    seller (string name ,string e ,int m)
    {
        name = n ;
        email = e ;
        maxItems = m ;
       arrayofitem = new item [m] ;
    }
    bool additem (item &pot)
    {
        if (maxItems > 0 )
        {
            for (int i=0 ; i<maxItems ; i++ )
              {
                  if (pot.name == arrayofitem[i].getname)
                  {
                      cout<<"Already available, the price has been added to the old price"<<endl;

                      arrayofitem[i].getquantity += pot.getquantity ;
                      arrayofitem[i].id_counter=arrayofitem[i].id_counter-1;
                      return true ;
                  }
                  else if(id_counter <maxItems  )
                  {
                      arrayofitem[i] = pot ;
                      return true;
                      itemsNumber++;
                  }
                  else
                  {
                      cout <<"error max number "<<endl;
                      return false ;
                  }
                  }


              }

        }
        bool Sellanaitem (string namme ,int  quantitty)
        {
           for (int t=0 ; t< maxItems ; t++)
           {
               if (namme == arrayofitem[t].getname)
               {
                   if (arrayofitem[t].getquantity <= quantitty)
                   {
                       arrayofitem[t].getquantity-=quantitty ;
                       return true ;
                   }
                   else
                   {
                       cout << "There is only {"<<arrayofitem.getquantity<<"} left for this item "<< endl ;
                       return false ;
                   }
               }
           }
        }
        void  printitems()
        {
            for (int i = 0 ; i<maxItems ;i++)
            {
                cout << arrayofitem[i]<<endl ;
            }
        }
       friend ostream & operator <<(ostream & os , const seller & obj )
        {
            os << "name" << obj . name <<endl ;
            os << " email " << obj . email <<endl ;
        }
        void findanitembyid (int  id )
        {
           for (int m=0 ;m< maxItems ; m ++ )
           {
               if (arrayofitem[m].getid == id )
               {
                   return arrayofitem[m]
               }
           }
           cout << "no matching " <<endl ;
        }
        ~seller()
        {
            delete[]arrayofitem;
        }

};
int seller::itemsNumber=0;
int item ::id_counter =0 ;
int main()
{
    string namee ;
    string emaill ;
    int maxnumofitems ;
    cout<< "enter seller details"<<endl ;
    cout<< "-------------------------------"<<endl ;
    cout <<"enter items name "<<endl ;
    cin>> namee;
    cout <<"enter items email "<<endl ;
    cin>> emaill;
    cout <<"enter maxnumofitems"<<endl ;
    cin>> emaill;
    seller mn( namee , emaill ,maxnumofitems )
    cout<< "choose the option u want " << endl ;
    int  choose ;
    do
    {
        cout<<"1. Print My Info" <<endl;
     cout<<"2. Add An Item"<<endl;
     cout<<"3. Sell An Item"<<endl;
     cout<<"4. Print Items"<<endl;
    cout<< "5. Find an Item by ID"<<endl;
     cout<<"6. Exit"<<endl;
     cin >>choose ;
     if (choose ==1 )
     {
         cout<<mn;
     }
     else if (choose ==2)
     {
         while (true )
         {
             string namee ;
             int quantityy ;
             double pricee ;
             cout <<"enter items name "<<endl ;
             cin>> namee;
             cout <<"enter items quantityy "<<endl ;
             cin>> quantityy;
             cout <<"enter items pricee "<<endl ;
             cin>> pricee;
             pott .item(namee,quantityy , pricee ) ;
             mn.additem(pott);
             int addanother ;
             cout<< "if u wanna add another item enter 1 " << endl ;
             cin >> addanother ;
             if (addanother ==1)
             {
                 continue ;
             }
             else
             {
                 break ;
             }
     }
     else if (choose ==3)
     {
         while (true )
         {
            string itemname ;
         int quantitty ;
         cout<< "enter item s name " <<endl;
         cin >>itemname ;
         cout<< "enter the quantity whitch needed " <<endl;
         cin >>quantitty;
         mn.Sellanaitem(itemname,quantitty);
         int addanotherr ;
             cout<< "if u wanna add another item enter 1 " << endl ;
             cin >> addanotherr ;
            if (addanotherr ==1)
            {
                continue ;
            }
            else
            {
                break
            }
     }

         }
    else if(choose ==4)
    {
        mn.printitems;
    }
    else if(choose ==5)
    {
         while (true )
         {
            cout<<"enter id which u search for " <<endl ;
            cin idd ;
            mn.findanitembyid(idd) ;
            int addanotherrr ;
             cout<< "if u wanna add another item enter 1 " << endl ;
             cin >> addanotherrr ;
            if (addanotherrr ==1)
            {
                continue ;
            }
            else
            {
                break
            }


    }


    }while(choose!=6);


    return 0;
}
