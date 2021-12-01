#include<bits/stdc++.h>
using namespace std;



void depth(int l,int r,int d,vector<int> &depth_A,vector<int> A){

    int m=l;
    for(int i=l;i<=r;i++){
        if(A[m]<A[i]){
            m=i;
        }
    }
    depth_A[m]=d;
    if(l<m){
        depth(l,m-1,d+1,depth_A,A);
    }
    if(r>m){
        depth(m+1,r,d+1,depth_A,A);
    }
    return;
}

int main(){
    int tc; //number of tcs;
    int n; //n for each tc
    cin>>tc;
    int k;
    while(tc--){
        cin>>n;
        vector<int>A;
        for(int i=0;i<n;i++){
            cin>>k;
            A.push_back(k);
        }
        vector<int>depth_A(n);
        depth(0,n-1,0,depth_A,A);
        for(int i=0;i<n;i++){
            cout<<depth_A[i]<<" ";
        }
        cout<<"\n";
    }


















}