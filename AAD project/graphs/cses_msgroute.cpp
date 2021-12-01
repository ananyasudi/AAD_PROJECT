#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>arr;
vector<bool>vis(false);
vector<int>dist;
vector<int>par;

void bfs(){
    queue<int>q;
    int x,level=1;
    dist[1]=1;
    q.push(1);
    vis[1]=true;
    while (!q.empty())
    {
        x=q.front();
        q.pop();

        for(auto it:arr[x]){
            if(!vis[it]){
                q.push(it);
                dist[it]=dist[x]+1;
                par[it]=x;
                vis[it]=true;
            }
        }    
    }
    return;
    
}


int main(){
    int n,m,c1,c2,x;
    cin>>n>>m;
    arr.resize(n+1);
    vis.resize(n+1);
    dist.resize(n+1);
    par.resize(n+1);
    vector<int>path(n+1);

    for (int i = 0; i < m; i++)
    {
        cin>>c1>>c2;
        arr[c1].push_back(c2);
        arr[c2].push_back(c1);
    }
    bfs();
    if(vis[n]){
    cout<<dist[n]<<"\n";
    x=n;
    path.push_back(n);
    while(x!=1){
        path.push_back(par[x]);
        x=par[x];
    }
    reverse(path.begin(),path.end());
    for(int i=0;i<dist[n];i++){
        cout<<path[i]<<" ";
    }
    }
    else{
        cout<<"IMPOSSIBLE"<<"\n";
    }

    

}