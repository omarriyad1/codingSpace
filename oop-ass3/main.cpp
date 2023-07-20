
//Name : Amr Mahmoud Said || ID :20206050
//Name : Omar Abdelmoneam Riad Ibrahim || ID : 20206045
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;
// FloatArray class
class FloatArray{
protected:
    double *array;  //allocate
    int size; //array size
    int index;
public:
    FloatArray(int size){
        this->size = size;
        array = new double [size];
        index = size;
        for (int i = 0; i < size; ++i) {
            array[i]=0;
        }
    }
    virtual void addMethod (double number ){
        array[size-index]=number;
        index--;
    }
    friend ifstream& operator>>(ifstream& in , FloatArray& fa){
        double number;
        for(int i=0; i<fa.size; i++)
        {
            in>>number;
            fa.addMethod(number);
        }
        return in;
    }
    friend ofstream& operator<<(ofstream& out, const FloatArray& fa){
        out<<fa.size<<"| \t";
        for (int i=0; i<fa.size; i++){
            if (fa.index==-1){
                if (fa.array[i]!=0){
                    out<<fa.array[i]<<"\t";
                }
            } else
                out<<fa.array[i]<<"\t";
        }
        out << endl;
        return out;
    }

    ~FloatArray(){
        delete [] array;
    }
};
// SortedArray class
class SortedArray: public FloatArray{
public:
    SortedArray(int size) : FloatArray(size){
    }
    void addMethod(double number){
        for (int i = 0; i < size-1; ++i) {
            if (array[i]==0){
                array[i]=number;
                sort(this->array, this->array+size);
                break;
            }
        }
    }
};
// FrontArray class
class FrontArray : public FloatArray{
public:
    FrontArray(int size):FloatArray(size){
    }
    void addMethod(double number) {
        double z[size];
        for (int i = 0; i < size-1; ++i) {
            z[i]=array[i];
        }
        array[0]=number;
        for (int i = 0; i <size-1; ++i) {
            array[i+1]=z[i];
        }
    }
};
// PositiveArray class
class PositiveArray : public SortedArray{
public:
    PositiveArray(int size): SortedArray(size){
    }
    void addMethod(double number){
        if (number>0){
            SortedArray::addMethod(number);
        } else
            index=-1;
    }
};
//  NegativeArray  class
class NegativeArray : public SortedArray{
public:
    NegativeArray(int size): SortedArray(size){
    }
    void addMethod(double number){
        if (number<0){
            SortedArray::addMethod(number);
        } else
            index=-1;
    }
};
int main() {
    cout<<"Enter the name of the input file :"<<endl;
    string nameOFinFile;cin>>nameOFinFile;
    cout<<"Enter the name of the outputfile :"<<endl;
    string nameOFoutFile;cin>>nameOFoutFile;
    int cnt{0};
    FloatArray *Farray[10];
    ifstream fin;
    ofstream out;
    fin.open(nameOFinFile );
    if (fin.is_open()){
        while (!fin.eof()){
            string X;
            fin>>X;
            if (X=="Array"){
                int x;
                fin>>x;
                Farray[cnt] = new FloatArray(x);
                fin >> *Farray[cnt];
                cnt++;
            } else if (X=="Sorted") {
                int x;
                fin >> x;
                Farray[cnt] = new SortedArray(x);
                fin >> *Farray[cnt];
                cnt++;
            }else if (X=="Front"){
                int x;
                fin >> x;
                Farray[cnt] = new FrontArray(x);
                fin >> *Farray[cnt];
                cnt++;
            } else if (X=="Positive"){
                int x;
                fin >> x;
                Farray[cnt] = new PositiveArray(x);
                fin >> *Farray[cnt];
                cnt++;
            } else if (X=="Negative"){
                int x;
                fin >> x;
                Farray[cnt] = new NegativeArray(x);
                fin >> *Farray[cnt];
                cnt++;
            }
        }
        fin.close();
        out.open(nameOFoutFile);
        for (int i = 0; i < cnt; ++i) {
            out<<*Farray[i];
        }
        out.close();
    } else
        cout<<"File open error!"<<endl;
    return 0;
}
