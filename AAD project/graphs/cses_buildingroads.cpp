#include<bits/stdc++.h>
using namespace std;
bool vis[100000]={false};
int n,m;
vector<vector<int>>arr;

int conn_comp=0;
void dfs(int i){
    vis[i]=true;
    for(auto it: arr[i]){
        if(!vis[it]){
          
            dfs(it);
        }
    }
}
int main(){
    // int arr[n+1][n+1];
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin>>n>>m;
    arr.resize(n+1);
    int x,y;
    vector<int>ans;
    for(int i=0;i<m;i++){
        cin>>x>>y;
       arr[x].push_back(y);
       arr[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            ans.push_back(i);
            dfs(i);
            conn_comp++;
        }
    }
    cout<<conn_comp-1<<"\n";
    for(int i=1;i<conn_comp;i++){
        cout<<ans[i-1]<<" "<<ans[i]<<"\n";
    }
    
}