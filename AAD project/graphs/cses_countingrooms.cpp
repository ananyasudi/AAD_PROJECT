#include<bits/stdc++.h>
using namespace std;
int m,n;
bool vis[1000][1000];
vector<pair<int,int>>moves = {{-1,0},{1,0},{0,1},{0,-1}};
bool isvalid(int i,int j){
    if(i>=m||j>=n||i<0||j<0){
        return false;
    }
    if(vis[i][j])
    return false;
    return true;
}
void dfs(int i,int j){
    vis[i][j]=true;
    for(auto p: moves){
        if(isvalid(i+p.first,j+p.second)){
            dfs(i+p.first,j+p.second);
        }
    }
    return;
}
int main(){
    cin>>m>>n;
    // char c;
    for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			char c; cin >> c;
			if(c == '#')
			{
				vis[i][j] = true;
			}
            else{
                vis[i][j]=false;
            }
		}
	}
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         cin>>c;
    //         if(c=='#'){
    //             vis[i][j]=true;
    //         }
    //         else{
    //             vis[i][j]=false;
    //         }
    //     }
    // }
    int conn_comp=0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(vis[i][j]==false){
                dfs(i,j);
                conn_comp++;
            }
        }
    }
    cout<<conn_comp<<"\n";
    
}