#include<bits/stdc++.h>
using namespace std;
int sx,sy,ex,ey;
int m,n;
int p,s;
char A[1000][1000];
bool vis[1000][1000];
vector<pair<int,int>>moves = {{-1,0},{1,0},{0,1},{0,-1}};
vector<vector<pair<int,int>>>par(1000,vector<pair<int,int>>(1000));
bool isvalid(int i,int j){
    if(i>=m||j>=n||i<0||j<0){
        return false;
    }
    if(vis[i][j])
    return false;
    return true;
}
void bfs(){
    queue<pair<int,int>> q;
    q.push({sx,sy});
    int cx,cy;
    while (!q.empty())
    {
        cx=q.front().first;
        cy=q.front().second;
        q.pop();
        for(auto move:moves){
            p=move.first+cx;
            s=move.second+cy;
            if(isvalid(p,s)){
                vis[p][s]=true;
                q.push({p,s});
                par[p][s]={move.first,move.second};
            }    
        }
    }
}

int main(){
    
    cin>>m>>n;
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>A[i][j];
            if(A[i][j]=='#'){
               vis[i][j]=true;
            }
            else if(A[i][j]=='.'){
               vis[i][j]=false;
            }
            else if(A[i][j]=='A'){
                sx=i;
                sy=j;
                vis[i][j]=false;
            }
            if(A[i][j]=='B'){
                ex=i;
                ey=j;
                vis[i][j]=false;
            }
        }
    }
    bfs();
    string path;
    int path_len=0;
    int x,y;
    int c_x,c_y;
    c_x=ex;
    c_y=ey;
    if(!vis[ex][ey]){
        cout<<"NO"<<"\n";
        return 0;
    }
    cout<<"YES"<<"\n";
    // for (int i = 0; i < m; i++)
    // {
    //     for(int j=0;j<n;j++){
    //         if(vis[i][j]){
    //         cout<<"("<<par[i][j].first<<","<<par[i][j].second<<" ";
    //         }
    //         else{
    //         cout<<"(0,0)"<<" ";
    //         }
    //     }
    //     cout<<"\n";
    // }
    
    // while (c_x!=sx or c_y!=sy)
    // {
    //     if(par[c_x][c_y].first==-1 and par[c_x][c_y].second==0 ){
    //         path.push_back('U');
    //     }
    //     else if(par[c_x][c_y].first==1 and par[c_x][c_y].second==0){
    //         path.push_back('D');
    //     }
    //     else if(par[c_x][c_y].first==0 and par[c_x][c_y].second==1){
    //         path.push_back('R');
    //     }
    //     else if(par[c_x][c_y].first==0 and par[c_x][c_y].second==-1){
    //         path.push_back('L');
    //     }
    //     path_len++;
    //     c_x=c_x-par[c_x][c_y].first;
    //     c_y=c_y-par[c_x][c_y].second;
    // }
    // cout<<path_len<<"\n";
    // for(int i=path.length();i>=0;i--){
    //     cout<<path[i];
    // }
    vector<pair<int,int>> ans;
	pair<int,int> end = {ex,ey};
 
	while(end.first != sx or end.second != sy)
	{
		ans.push_back(par[end.first][end.second]);
		end.first -= ans.back().first;
		end.second -= ans.back().second;	
	}
 
	reverse(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for(auto c: ans)
	{
		if(c.first == 1 and c.second ==0)
		{
			cout << 'D';
		}
		else if(c.first == -1 and c.second ==0)
		{
			cout << 'U';
		}
		else if(c.first == 0 and c.second == 1)
		{
			cout << 'R';
		}
		else if(c.first == 0 and c.second == -1)
		{
			cout << 'L';
		}
	}

    
}