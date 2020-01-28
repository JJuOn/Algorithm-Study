#include <iostream>
using namespace std;
int main(){
    int n,m,a;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a<m){
            cout<<a<<" ";
        }
    }
    return 0;
}