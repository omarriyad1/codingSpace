#include <iostream>
#include<string>
using namespace std;
class integerset{
private:
    int arr[100];
public:
    integerset(){
        for (int i=0;i<101;i++){
            arr[i]=0;
        }
    }
    integerset unionOfSets(integerset I){
        integerset s3;
        for(int i=0;i<101;i++){
            if(arr[i]==1||(I.arr[i]==1)){
                s3.arr[i]=1;
            }
        }
        return s3;
    }
    integerset intersectionOfSets(integerset I){
        integerset s3;
        for(int i=0;i<101;i++){
            if((arr[i]==1)&&(I.arr[i]==1)){
                s3.arr[i]=1;
            }
        }
        return s3;
    }

    void insertElement(int k){
        arr[k]=1;
    }
    void deleteElement(int m){
        arr[m]=0;
    }
    void printset(){
        for(int i=0;i<101;i++){
            if (arr[i]==1){
                cout<<i;
                cout<<' ';
            }
        }
    }
    void isEqualTo(integerset I){
        int counter=0;
        for(int k=0;k<101;k++){
            if(arr[k]!=I.arr[k]){
                counter++;
            }
        }
        if (counter>0)
            cout<<"they are equal"<<endl;
        else
            cout<<"they are not equal"<<endl;
    }
    integerset(int arrr[],int size){
        for(int i=0;i<size;i++){
            arr[arrr[i]]=1;
        }
    }
    integerset operator-(integerset a){
        integerset b;
        for(int i=0;i<101;i++){
            if (arr[i]==1&&a.arr[i]==0)
                b.arr[i]=1;
        }
        return b;
    }
    integerset operator! (){
        for (int i = 0; i < 101; ++i) {
            if ( arr[i]==0) arr[i]=1;
            else if (arr[i]==1) arr[i]=0;
        }
        return *this;
    }
};

int main() {
    cout<<"obj (T)set to 0 by default constructor"<<endl;
    IntegerSet T;
    cout<<"Print it "<<endl;
    T.pr;
    cout<<"==========================="<<endl;
    cout<<"Add element 5 to obj1"<<endl;
    I1.insertElement(5);
    cout<<"Add element 10 to obj1"<<endl;
    I1.insertElement(10);
    cout<<"print obj1"<<endl;
    I1.printSet();
    cout<<"==========================="<<endl;
    cout<<"delete element 10 from obj1"<<endl;
    I1.deleteElement(10);
    cout<<"print obj1"<<endl;
    I1.printSet();
    cout<<"==========================="<<endl;
    cout<<"Add element 12 to obj1"<<endl;
    I1.insertElement(12);
    cout<<"Add element 15 to obj1"<<endl;
    I1.insertElement(15);
    cout<<"Add element 100 to obj1"<<endl;
    I1.insertElement(100);
    cout<<"Add element 0 to obj1"<<endl;
    I1.insertElement(0);
    cout<<"print obj1"<<endl;
    I1.printSet();
    cout<<"==========================="<<endl;
    cout<<"make array {0, 5 , 10 , 15 , 99 , 100} and add to new obj2"<<endl;
    int array[9]{0,1,2,3,5,10,15,99,100};
    IntegerSet I2{array,9};
    cout<<"print obj 2"<<endl;
    I2.printSet();
    cout<<"==========================="<<endl;
    cout<<"cheak if obj1 is equal to obj2"<<endl;
    if (I1.isEqualTo(I2)) cout<<"there are equal"<<endl;
    else cout<<"not equal"<<endl;
    cout<<"==========================="<<endl;
    cout<<"obj3=obj2-obj1"<<endl;
    IntegerSet I3=I2-I1;
    I3.printSet();
    cout<<"==========================="<<endl;
    cout<<"obj1 union obj2 into obj4"<<endl;
    IntegerSet I4=I1.unionOfSets(I2);
    cout<<"print obj4"<<endl;
    I4.printSet();
    cout<<"==========================="<<endl;
    cout<<"obj1 intersection obj2 into obj5"<<endl;
    IntegerSet I5=I1.intersectionOfSets(I2);
    cout<<"print obj5"<<endl;
    I5.printSet();
    cout<<"==========================="<<endl;
    cout<<"obj1 = !obj4 "<<endl;
    I1= !I4;
    I1.printSet();
    cout<<"==========================="<<endl;
    cout<<"DONE , THANK YOU :)"<<endl;
    return 0;


    return 0;
}
