#include <iostream>
using namespace std;
int main(){
    int a,max=1,index;
    for(int i=1;i<=9;i++){
        cin>>a;
        if(a>max){
            max=a;
            index=i;
        }
    }
    cout<<max<<endl<<index<<endl;
    return 0;
}