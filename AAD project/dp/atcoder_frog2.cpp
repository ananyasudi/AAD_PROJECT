#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int jmp[n];
    for(int i=0;i<n;i++){
        cin>>jmp[i];
    }
    int ans[n];
    vector<int>vec;
    // vec[0]=9999;
    ans[0]=0;
    ans[1]=abs(jmp[1]-jmp[0]);
    for(int i=2;i<n;i++){
        for(int j=1;j<=k&&(i-j>=0);j++){
            vec.push_back(abs(jmp[i]-jmp[i-j])+ans[i-j]);
            // cout<<vec[j]<<" ";
        }
        ans[i]=*min_element(vec.begin(),vec.end());
        vec.clear();

    }
    cout<<ans[n-1]<<"\n";

}