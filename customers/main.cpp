#include <iostream>

using namespace std;
class PersonData
{
string lastName;
string firstName;
string address;
string city;
string phone;
public:
PersonData(string ln,string fn,string a,string c, string p)
{setPData(ln,fn,a,c,p);}
void printPerson()
{
cout<<"First Name:"<<firstName<<endl;
cout<<"Last Name:"<<lastName<<endl;
cout<<"Address:"<<address<<endl;
cout<<"City:"<<city<<endl;
cout<<"Phone:"<<phone<<endl;
}
void setPData(string ln,string fn,string a,string c, string p)
{lastName=ln;
firstName=fn;
address=a;
city=c;
phone=p;
}
};
class CustomerData:public PersonData
{
protected :
    int customerNumber ;
    bool mailingList ;
public :
    CustomerData()
    {
        customerNumber = 0 ;
    }
        CustomerData (CustomerData (string lastName , string firstName,string city,string address,string phone,int customerNumberr,bool mailingListt):PersonData(string {lastName,firstName,address,city,  phone);
        {
            mailingListt =mailing;
            customerNumberr =customerNumber;
        }
        void printCustomer()
        {

            cout<< firstName<< endl ;
            cout<<lastName << endl ;
             cout<<mailingLis << endl ;
            cout<<customerNumber << endl ;
            cout<<phone << endl ;
            cout<<city << endl ;
             cout<<address << endl ;
        }


};


int main()
{
    string lastName ;
     string firstName;
     string city;
     string address;
     string phonee;
     int customerNumberr;
     bool mailingListt;
    int custno ;
    cout << "enter  customer s no !" << endl;
    cin>>custno ;
    custarrayy = new CustomerData [custno] ;
    for (int i = 0 ; i< custno; i ++)
    {
       cout<<"Enter last name - first name - address - city - phone - customer numberR -mailing listT"<<endl;
       cin>> lastName >>  firstName>> city>> address>> phonee>> customerNumberr>> mailingListt;
       CustomerData(CustomerData (lastName ,  firstName, city, address, phonee, customerNumberr, mailingListt )

    }

    return 0;
}

// Create a dynamic Array of customers
// Read the info of the Customers in a loop , and print using printCustomer
//delete the array before ending the main

