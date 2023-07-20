#include <iostream>

using namespace std;
class MyPhoneBook
{
 string* names;
 string* phones;
 int phoneBookSize;
 int counter {0};

 public:
 MyPhoneBook(int); //Takes size
 MyPhoneBook(const MyPhoneBook&); //Copy Constructor
 bool addEntry(string ,string);
 bool displayEntryAtIndex(int);
 void displayEntryAtIndices(int*);
 void displayAll();
 int* findByName(string);
 int* findByPhone(string);
 bool updateNameAt(string, int);
 bool updatePhoneAt(string, int);
 ~MyPhoneBook();
};
MyPhoneBook ::MyPhoneBook (int sizee)
{    phoneBookSize = sizee ;
    string *names = new string [phoneBookSize] ;
    string *phones = new string [phoneBookSize] ;
}
MyPhoneBook ::MyPhoneBook(const MyPhoneBook& obj)
{
    phoneBookSize = obj.phoneBookSize ;
    names =  obj. names;
    phones= obj. phones;
    for (int i = 0 ; i < phoneBookSize ; i++)
    {
        names[i] = obj. names ;
    }
    for (int i = 0 ; i < phoneBookSize ; i++)
    {
        phones[i] = obj. phones ;
    }
}


bool MyPhoneBook::addEntry (string namee ,string phonesnum)
{
    int counterrr= 0 ;
    if(phonesnum . length() == 11)
    {
        for (int k = 0 ; k <11 ; k++)
        {
            if (phonenum.at(k)>='0' && phonesnum.at(k) <='9')
            {
                counterrr = counterrr +1 ;
            }
            else
            {
                counterrr = 0 ;
                break ;
            }


        }

    }

        if (counterrr == 11 )
        {

            phones[counter] = phonesnum ;
            names[counter] = namee ;
            counter  ++ ;
            return true ;
        }
        else
        {
            return false ;
        }


    }
bool MyPhoneBook::displayEntryAtIndex(int numm)
{
    if (numm <= phoneBookSize)
    {
        cout << names[num] << endl ;
        cout << phones[num] << endl ;
        return true ;
    }
    else
    {
        return false ;
        cout << "Try with another index" << endl;
    }
}
void  MyPhoneBook::displayEntryAtIndices(int*sizeee)
{

    phoneBookSize = sizeee ;
    int*Parameterarray = new int [phoneBookSize] ;
    for (int h=0 ; h < sizeee ; h++)
    {
         cout <<Parameterarray[h] << "    " ;
        }
        cout << endl ;
        for (int n=0 ; n< sizeee ; n++)

        {
            cout <<names[n] <<  "    "  ;
        }
          cout << endl ;

         for (int x=0 ; x < sizeee ; x++)
         {
             cout <<phones[x] <<"    " ;
         }
           cout << endl ;




    }
}
 void MyPhoneBook::displayAll();
 {
     for ( int r = 0 ;r < phoneBookSize ; r ++)
     {
         cout <<names[r] << endl ;
         cout <<phones[r] << endl ;
     }
 }
 int* MyPhoneBook::findByName(string namme);
 {
     int counterr =0 ;
     for (int p =0 ; p < phoneBookSize ;p ++)
     {
         for (int o ; o < namme . length() ; o++)
         {
              if(namme . at(o) ==names[p] .at(o) )
              {
                 counterr = counterr + 1 ;
              }
              else
              {
                  counterr = 0 ;
                  Parameterarray[p] = 0 ;
                  continue ;
              }

              if (counterr ==namme . length())
              {
                  Parameterarray[p] = 1 ;
              }

                }


 }
 for (int t=0 ; t < phoneBookSize ;t++)
    {
        cout <<Parameterarray[t] << "    " ;
        }
        cout << endl ;
 for (int s=0 ; s< phoneBookSize ; s++)

        {
            cout <<names[s] <<  "    "  ;
        }

        cout << endl ;

         for (int z=0 ; z < phoneBookSize ; z++)
         {
             cout <<phones[z] <<"    " ;
         }

        cout << endl ;
         }

int* MyPhoneBook::findByPhone(string phonenumm);
 {
     int counterr =0 ;
     for (int d =0 ; d < phoneBookSize ;d ++)
     {
         for (int y ; y < phonenumm . length() ; y++)
         {
              if(phonenumm . at(y) ==phones[d] .at(y) )
              {
                 coounterr = coounterr + 1 ;
              }
              else
              {
                  coounterr = 0 ;
                  Parameterarray[d] = 0 ;
                  continue ;
              }

              if (coounterr ==phonenumm . length())
              {
                  Parameterarray[d] = 1 ;
              }

                }


 }
 for (int w=0 ;w < phoneBookSize ;w++)
    {
        cout <<Parameterarray[w] << "    " ;
        }
        cout << endl ;
 for (int v=0 ; v< phoneBookSize ; v++)

        {
            cout <<names[v] <<  "    "  ;
        }

        cout << endl ;

         for (int g=0 ; g < phoneBookSize ; g++)
         {
             cout <<phones[g] <<"    " ;
         }

        cout << endl ;
         }
bool MyPhoneBook:: updateNameAt(string newname, int indexx)
{

    names[indexx] = newname ;
}
bool MyPhoneBook:: updatePhoneAt(string newphonenum, int indexxx)
{

    phones[indexxx] = newphonenum ;
}
~MyPhoneBook()
{
    delete[]names ;
    delete[]phones ;
    delete []Parameterarray ;
}










int main()
{int size ;
MyPhoneBook obj ;
string name , phonemum ;
cout << "Enter The Size Of your Phonebook"<<endl  ;
cin >>size ;
obj.MyPhoneBook(size) ;
MyPhoneBook b1 ,
for (int i = 0 ; i < size ; i++)
{
    cout << "Enter The Name "<<endl ;
    cin >>name ;
    cout << "Enter The phonenum " <<endl;
    cin >>phonemum ;
    b1 .addEntry(name , phonemum) ;

}
int choice ;
cout <<" enter your choice : " <<endl ;
cout <<" 1- display all phone book " << endl ;
cout <<" 2-search for entry /entries by name " <<endl ;
cout <<" 3-search for entry /entries by phone " <<endl ;
cout <<" 4-find an entry by index " <<endl ;
cout <<" 5-update name by index" <<endl ;
cout <<" 6-update phone by index" <<endl ;
cout <<" 7-copy phone book to another and display entries of a new phone book" <<endl ;
cout <<" 8-exit " <<endl ;
cin >> choice ;
switch (choice)
{
case '1':
    b1 . displayAll() ;
    break ;
case '2' :
    string namme ;
    cout << "enter the name : " <<endl ;
    cin >> namme ;
    b1 . findByname(namme);
    break ;
case '3' :
    string phonenuum ;
    cout << "enter the nunmber: " <<endl ;
    cin >>phonenuum ;
    b1 . findByPhone(phonenuum) ;
    break ;
case '4' :
    int index
    cout << " enter index of entry u search for "<< endl ;
    cin >> index ;
    b1 . displayEntryAtIndex (index) ;
    break ;
case '5' :
    int indeex ;
    string newname ;
    cout << " Enter The New Name : "<<endl ;
    cin >> newname ;
     cout << " Enter Index : "<<endl ;
    cin >> indeex ;
    b1 . updateNameAt(newname , indeex) ;
    break ;
case '6' :
    int inddex ;
    string newnum ;
    cout << " Enter The New Num: "<<endl ;
    cin >> newnum ;
     cout << " Enter Index : "<<endl ;
    cin >> inddex ;
    b1 . updatePhoneAt(newnum , inddex) ;
    break ;
case '7' :
    MyPhoneBook(const MyPhoneBook&b1) ;
    break ;
case '8' :
    break ;
}


    return 0;
}
