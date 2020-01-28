#include <iostream>
using namespace std;
int main(){
    int n,temp,count=0,d10,d1;
    cin>>n;
    temp=n;
    do{
        d10=temp/10;
        d1=temp%10;
        temp=(d10+d1)%10+d1*10;
        count++;
    }while(temp!=n);
    cout<<count<<endl;
    return 0;
}