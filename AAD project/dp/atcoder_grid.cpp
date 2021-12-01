#include<bits/stdc++.h>
using namespace std;
unsigned int max_ = 1000000007;
int main(){
    int m,n;
    cin>>m;
    n=m;
    vector<vector<unsigned int>>dp(m+1,vector<unsigned int>(n+1,0));
    vector<vector<char>>arr(m,vector<char>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            // if(arr[i][j]=='#'){
            //     dp[i][j]=0;
            // }
        }
    }
    dp[0][0]=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]=='*')
            dp[i][j]=0;
            else{
                if(i>0) dp[i][j]+=dp[i-1][j];
                if(j>0) dp[i][j]+=dp[i][j-1];
                // cout<<dp[i][j]<<" ";
            }
            // cout<<"\n";
            dp[i][j]=dp[i][j]%max_;
        }
    }
    cout<<dp[m-1][n-1]<<"\n";

}