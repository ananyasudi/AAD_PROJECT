#include<bits/stdc++.h>
using namespace std;
 char s[140000];
int cost(int l,int r,char ch){
    int ret=0;
    for(int i=l;i<=r;i++){
        if(s[i]!=ch) ret++;
    }
    return ret;
}
int getMin(int l,int r,char ch){
    if(l==r){
        if(s[l]==ch) return 0;
        else return 1;
    }
    int mid=(l+r)/2;
    return min(cost(l,mid,ch)+getMin(mid+1,r,ch+1),cost(mid+1,r,ch)+getMin(l,mid,ch+1));
}
int main(){
    int tc,n;
    cin>>tc;
   
    while(tc--){
        cin>>n;
        cin>>s;
        int m=getMin(0,n-1,'a');
        cout<<m<<"\n";
    }
}