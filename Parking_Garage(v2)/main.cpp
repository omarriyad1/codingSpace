#include <iostream>
#include<string>
using namespace std;
class Vehicle{
public:
    char name;
    string uniqueIdenticationNumber;
    string model_year;
    string vehicle_type;
  Vehicle(){
        name='NULL';
        uniqueIdenticationNumber="NULL";
        model_year="NULL";
        vehicle_type='NULL';
    }
    Vehicle(char n, string unique, string model, char vichleT){
        name=n;
        uniqueIdenticationNumber=unique;
        model_year=model;
        vehicle_type=vichleT;
    }
    bool  operator =(Vehicle v){
        name=v.name;
        uniqueIdenticationNumber=v.uniqueIdenticationNumber;
        model_year=v.model_year;
        vehicle_type=v.vehicle_type;
    }
    void setname(char n)
    {
        name=n;
    }
    void setuniqueID(string unique){
        uniqueIdenticationNumber=unique;
    }
    void setmodelYear(string model)
    {
        model_year=model;
    }
    virtual  void setvichleType();

    void getInformation(){
            cout<<name<<endl;
            cout<<uniqueIdenticationNumber<<endl;
            cout<<model_year<<endl;
            cout << vehicle_type << endl;
    }
};
class car :public Vehicle
        {
public:

            string type = "car";

    void setvichleType(){
        vehicle_type=type;
    }
};
class van :public Vehicle
{
public:

    string type = "van";

    void setvichleType(){
        vehicle_type=type;
    }
};
class motorcycle :public Vehicle
{
public:

    string type = "motorcycle";


    void setvichleType(){
        vehicle_type=type;
    }
};
class truck :public Vehicle
{
public:
    string type = "truck";

    void setvichleType(){
        vehicle_type=type;
    }

};
class parking_slot: public Vehicle{
public:
    string slots[20];
    Vehicle *ArrayVehicle;
    int slotId;
    int availablenumofSlots=20;
    /*parking_slot()
    {

    }*/
    parking_slot(){
        Vehicle();


        for(int i=0;i<20;i++){
            slots[i]="0";
        }
        ArrayVehicle=new Vehicle[20];
        slotId=0;
        availablenumofSlots=0;
    }
    int  check()
    {
        int x=0;
        if(availablenumofSlots==0)
        {
            cout<<"No place available to park in it "<<endl;
            return -1;
        }else
        {
            for(int i=0;i<20;i++){
                if(slots[i]=="0"){
                    cout<<"there is available place in slot ["<<i<<"]"<<endl;
                    x=i;
                    return x;
                }
            }
        }
    }
  /*  void editSlot(Vehicle h,int alter)
    {

        for(int y =0 ; y< 20 ; y++)
        {
            if(h.uniqueIdenticationNumber = slots[y])
            {
                swap(h.uniqueIdenticationNumber,alter);
            }
            else
                cout << " it doesnt exict"<< endl;
        }

    }*/
    /*void addSlot(int x)
    {
              int m=20+x;
              slots =new string[m] ;
    }*/
};
class Entrance :public parking_slot{
public:
    double arrival_time;
    double atime [20];
    int k = 0;
    void setArrivalT(double arrival_time)
    {
       this->arrival_time=arrival_time;
       atime[k] = arrival_time ;
       k++;
    }
    double getarrival(int ll){
        return atime[ll];
    }
    /*void askForSlot()
    {
        check();
    }*/

};
class Exit:public parking_slot{
public:
    double extime [20];
    int p= 0;
    double exit_time;
    void setexitT(double exit_time)
    {
        this->exit_time=exit_time;
        extime[p] = exit_time;
        p++;
    }
    double getexit(int v){
        return extime[v];
    }

};
class Parking_Garage:public parking_slot,public Vehicle{
public:
    Entrance* tim ;
    Exit*ex;
    void parkIN(Vehicle obj)
    {
        cout<<"enter the entrance time"<< endl;
        double timme;
        cin >>timme;
        tim->setArrivalT(timme);
        int x=check();
        if(availablenumofSlots!=0){
            parking_slot OBJ;
            slots[x]=obj.uniqueIdenticationNumber;
            OBJ.ArrayVehicle[x]=obj;
            availablenumofSlots--;
        }
    }
    void park_Out(Vehicle obj)
    {
        cout<<"enter the exit time"<< endl;
        double timmo;
        cin >>timmo;
        ex->setexitT(timmo);
        int x=check();
        slots[x]="0";
        availablenumofSlots++;

    }

};
class parking_time:public Vehicle,public parking_slot{
public:
    double duration;
    Entrance* E ;
    Exit* R;
    parking_time(Vehicle objj){
        for (int i = 0; i < 20; ++i) {
            if ( slots[i]== objj.uniqueIdenticationNumber)
            {
                    duration = R->exit_time-E->arrival_time;
            }
        }


    }
    /*int getdurration() const
    {
        return duration;
    }*/
};
class Parking_fee:public Vehicle
{
    public:
    parking_time* h;
    double total ;
    Parking_fee(Vehicle obbj)
    {
        int hourlyrate=5;

        total = h -> duration *hourlyrate;
    }


};
class Payment:public Vehicle{
public:
    Parking_fee* su;
    parking_time* llo;
    double pay(Vehicle obbj)
    {
        cout<< " pay"<<llo->duration <<endl;
        cout << " enter"<< su->total<<endl;
        double payment ;
        cin >> payment;
        if (payment == su->total)
        {
            cout << "done "<< endl;

        }
        else
            cout << " u still have to pay "<< (su->total) - payment <<endl;
    }
    class controller
    {
        Parking_fee*fo;
        parking_time* ho;
        Entrance* Eo ;
        Exit* Ro;
        parking_slot * po ;

    };


};




int main() {
    int choice ;
    Parking_Garage mo ;
    parking_time mnn ;
    Parking_fee mbo ;
    cout<< "enter the num of service which needed "<<endl;
    cout<< "0- noquestions"<<endl;
    cout<< "1- ask for leaving"<<endl;
    cout<< "2- ask for leaving"<<endl;
    cout<< "3-ask for change your slot"<<endl;
    cout<< "4-wanna know the durration of parking "<<endl;
    cout<< "5- ask for the parking fee"<<endl;

    while(choice != 0)
    {
        if (choice ==2)
        {
            cout<< "enter vehicle name, unique num,  model " << endl ;
            Vehicle mm;
            char name;
            string uniquenum;
             string model;
              char vichleT ;
            cin >>  name,  uniquenum, smodel, vichleT;
            Vehicle mm(name,  uniquenum, smodel, vichleT);
            mo .park_Out(mm);
        }
         if (choice ==1)
        {
            cout<< "enter vehicle name, unique num,  model " << endl ;
            Vehicle mn;
            char namee;
            string uniquenumm;
             string ssmodel;
              char vvichleT ;
            cin >>  namee,  uniquenumm, ssmodel, vvichleT;
            Vehicle mn(namee,  uniquenumm, ssmodel, vvichleT);
            mo .parkIN(mn);
    }
     if (choice ==3)
        {
            cout << "the old slot and the new ont "<<endl;
            int newone;
            cin >> newone;
            mo .editSlot(Vehicle obj,newone);
        }
         if (choice ==4)
        {

            cout<< "enter vehicle name, unique num,  model " << endl ;
            Vehicle zz;
            char name;
            string uniquenum;
             string model;
              char vichleT ;
            cin >>  naame,  uniquenum, smoodel, vicchleT;
            Vehicle zz(naame,  uniquenum, smoodel, vicchleT);
            mnn.parking_time(zz);
        }
        if (choice ==5)
        {
            cout<< "enter vehicle name, unique num,  model " << endl ;
            Vehicle gg;
            char name;
            string uniquenum;
             string model;
              char vichleT ;
            cin >>  name,  uniquenum, smodel, vichleT;
            Vehicle gg(name,  uniquenum, smodel, vichleT);
            mbo .Parking_fee(gg);
        }

        };

    return 0;
}
