#include <iostream>
#include <stack>
using namespace std;
void print(stack<int> stackk)
{
        while ( !stackk . empty())
        {
            cout << stackk.top() <<endl;
            stackk.pop();
        }

}
int main()
{
    stack <int> nubmerstack ;
    nubmerstack.push(1) ;
    nubmerstack.push(4) ;
    nubmerstack.push(8) ;
    print (nubmerstack);
    nubmerstack.pop();
    print (nubmerstack);


    return 0;
}
