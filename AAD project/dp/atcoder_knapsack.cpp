#include<bits/stdc++.h>
using namespace std;
int main(){
    long int N,W;
    cin>>N>>W;
    long int max_val=0;
    long int a[N][2];
    long int dp[N][W+1];
    for(long int i=0;i<N;i++){
        cin>>a[i][0]>>a[i][1];
    }
    for(long int i=0;i<N;i++){
        dp[i][0]=0;
    }
    for(long int i=1;i<=W;i++){
        if(i>=a[0][0]){
            dp[0][i]=a[0][1];
        }
        else{
            dp[0][i]=0;
        }
    }
    for(long int i=1;i<N;i++){
       for(long int j=1;j<=W;j++){
           if(j>=a[i][0]){
               dp[i][j]=max(dp[i-1][j],dp[i-1][j-a[i][0]]+a[i][1]);
           }
           else{
               dp[i][j]=dp[i-1][j];
           }
       }
    }
    cout<<dp[N-1][W]<<"\n";

   

}