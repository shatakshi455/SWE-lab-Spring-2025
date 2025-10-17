//SHATAKSHI SINGH
//23CS30048
//WEEK 1 QUESTION 1

#include <iostream>
using namespace std;

int get_num_after_increment(int k)
{
    k++;
    return k;
}
int main()
{
    int n;
    cout<<"Enter a start:";
    cin>>n;
    int t=4;
    cout<<n<<endl;
    int p=get_num_after_increment(n);
    while(t--){
        cout<<p<<endl;
        p=get_num_after_increment(p);
    }

    cout<<"Printed five numbers. Enter end:";
    int en;
    cin>>en;

    while(p<=en){
        cout<<p<<endl;
        p=get_num_after_increment(p);
    }

    return 0;
}
