#include <iostream>
using namespace std;
int main(){
    int a,b,b100,b10,b1;
    cin>>a>>b;
    b100=b/100;
    b10=(b%100)/10;
    b1=b%10;
    cout<<a*b1<<endl;
    cout<<a*b10<<endl;
    cout<<a*b100<<endl;
    cout<<a*b<<endl;
    return 0;
}