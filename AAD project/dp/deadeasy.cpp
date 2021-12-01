#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int curr=1;
    int max_l=curr;
    for (int i = 0; i < n-1; i++)
    {
        if(a[i]<=a[i+1])
            curr+=1;
        else
            curr=1;
        if(curr>max_l){
            max_l=curr;
        }
    }
    cout<<max_l<<"\n";
    
}