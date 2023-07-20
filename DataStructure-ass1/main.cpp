
 ////Name : Omar abdelmoneam riad ibrahim || ID : 20206045
////Name : Omar sayed ramadan  || ID : 20206042
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
        cout<<"add element["<<k<<"]"<<endl;
    }
    void deleteElement(int m){
        arr[m]=0;
        cout<<"delete element["<<m<<"]"<<endl;
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
    integerset(int arrr[],int sizze){
        for(int i=0;i<sizze;i++){
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
    cout<<"obj(T) sets by default constructor"<<endl;
    integerset T;
    cout<<"Print it"<<endl;
    T.printset();
    cout<<endl;
    cout<<"      ------------      "<<endl;
    cout<<"Add 1 to element[2]in T"<<endl;
    T.insertElement(2);
    cout<<"Add 1 to element[7]in T"<<endl;
    T.insertElement(7);
    cout<<"Add 1 to element[16]in T"<<endl;
    T.insertElement(16);
    cout<<"print T"<<endl;
    T.printset();
    cout<<endl;
    cout<<"      ------------      "<<endl;
    cout<<"delete element[7]from T"<<endl;
    T.deleteElement(7);
    cout<<"print T"<<endl;
    T.printset();
    cout<<endl;
    cout<<"      ------------      "<<endl;
    cout<<"Add 1 to element[0]in T"<<endl;
    T.insertElement(0);
    cout<<"Add 1 to element[9]in T"<<endl;
    T.insertElement(9);
    cout<<"Add 1 to element[13]in T"<<endl;
    T.insertElement(13);
    cout<<"Add 1 to element[20]in T"<<endl;
    T.insertElement(20);

    cout<<"print T"<<endl;
    T.printset();
    cout<<endl;
    cout<<"      ------------      "<<endl;
    cout<<"add array {0, 3 , 9 , 22 ,34, 58 , 70 , 82 ,90, 100}to W"<<endl;
    int arrayy[10]{0,3,9,22,34,58,70,82,90,100};
    integerset TW(arrayy,10) ;
    cout<<"print TW"<<endl;
    TW.printset();
    cout<<endl;
    cout<<"      ------------      "<<endl;
    cout<<"check if T is equal to TW"<<endl;
    T.isEqualTo(TW);
    cout<<endl;
    cout<<"      ------------      "<<endl;
    cout<<"T3=TW-T"<<endl;
    integerset T3=TW-T;
    T3.printset() ;
    cout<<endl;
    cout<<"      ------------      "<<endl;
    cout<<"T union TW into TF"<<endl;
    integerset TF=T.unionOfSets(TW);
    cout<<"print TF"<<endl;
    TF.printset();
    cout<<endl;
    cout<<"      ------------      "<<endl;
    cout<<"T intersection TW into V"<<endl;
    integerset V=T.intersectionOfSets(TW);
    cout<<"print V"<<endl;
    V.printset();
    cout<<endl;
    cout<<"      ------------      "<<endl;
    cout<<"TW = !V "<<endl;
    TW= !V;
    TW.printset();
    cout<<endl;
    cout<<"      ------------      "<<endl;
    cout<<":) thanks <3"<<endl;
    return 0;

    return 0;
}
