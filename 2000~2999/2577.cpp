#include <iostream>
using namespace std;
int main(){
    int nums[10]={0},a,b,c,result,idx;
    cin>>a>>b>>c;
    result=a*b*c;
    while(result!=0){
        idx=result%10;
        nums[idx]++;
        result/=10;
    }
    for(int i=0;i<10;i++){
        cout<<nums[i]<<endl;
    }
    return 0;
}