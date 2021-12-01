#include<bits/stdc++.h>
using namespace std;
int n,m,sv,ev;
vector<bool>vis;
vector<int>parent(100,-1);
vector<vector<int>>arr;
bool dfs(int i,int p){
    vis[i]=true;
    parent[i]=p;
    for(auto v: arr[i]){
        if(v==p)continue;
        if(vis[v]){
            sv=v;
            ev=i;
            return true;
        }
        if(!vis[v]){
            if(dfs(v,i))return true;
        }
    }
    return false;
}
bool vis_all(){
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(dfs(i,-1))return true;
        }
    }
    return false;
}
int main(){
    cin>>n>>m;
    vis.resize(n+1);
    arr.resize(n+1);
    parent.resize(n+1);
    int x,y,temp;
    for (int i = 0; i < m; i++)
    {
        cin>>x>>y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    bool var=vis_all();
    if(!var){
        cout<<"IMPOSSIBLE"<<"\n";
        return 0;
    }
   else if(var){
        vector<int>ans;
        // if(parent[sv]==-1){
        //     temp=sv;
        //     sv=ev;
        //     ev=temp;
        // }
        int t=ev;
        ans.push_back(ev);
        while(t!=sv){
            ans.push_back(parent[t]);
            t=parent[t];
        }
        ans.push_back(ev);
        cout<<ans.size()<<"\n";
 
        for(auto it:ans){
            cout<<it<<" ";
        }
 
        cout<<"\n";
 
    }
    return 0;

    
}