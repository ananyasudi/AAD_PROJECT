#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int jmp[n];
    for(int i=0;i<n;i++){
        cin>>jmp[i];
    }
    int ans[n];
    ans[0]=0;
    ans[1]=abs(jmp[1]-jmp[0]);
    for(int i=2;i<n;i++){
        ans[i]=min(abs(jmp[i]-jmp[i-2])+ans[i-2],abs(jmp[i]-jmp[i-1])+ans[i-1]);
    }
    cout<<ans[n-1]<<"\n";

}