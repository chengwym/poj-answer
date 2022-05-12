#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int w,h,sx,sy,ex,ey;
char maze[45][45];
bool state[45][45];
int direction1[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int direction2[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int bfs(int x,int y){
    queue<pair<int,int>>q;
    q.push(pair<int,int>(x,y));
    int step=1;
    state[x][y]=1;
    while(!q.empty()){
        int size=q.size();
        step++;
        while(size--){
            int oldx=q.front().first;
            int oldy=q.front().second;
            q.pop();
            for (int i=0;i<4;i++){
                int newx=oldx+direction1[i][0];
                int newy=oldy+direction1[i][1];
                if(newx>h||newy>w||newx<1||newy<1||state[newx][newy]==1||maze[newx][newy]=='#') continue;
                state[newx][newy]=1;
                if(newx==ex&&newy==ey) {
                    return step;
                }
                q.push(pair<int,int>(newx,newy));
            }
        }
    }
    return 0;
}
int dfs(int x,int y,int d,int dir[4][2]){
    if(x==ex&&y==ey) return 1;
    int step;
    for (int i=0;i<4;i++){
        int temp=(i+d)%4;
        int newx=x+dir[temp][0];
        int newy=y+dir[temp][1];
        if(newx>=1&&newy>=1&&newx<=h&&newy<=w&&maze[newx][newy]!='#'){
            step=dfs(newx,newy,(temp+3)%4,dir)+1;
            break;
        }
    }
    return step;
}
int main(){
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        memset(state,0,sizeof(state));
        cin>>w>>h;
        int d;
        for (int i=1;i<=h;i++){
            for (int j=1;j<=w;j++){
                cin>>maze[i][j];
                if(maze[i][j]=='S'){
                    sx=i;
                    sy=j;
                    if(sy==1) d=0;
                    if(sx==1) d=1;
                    if(sy==w) d=2;
                    if(sx==h) d=3;
                }
                if(maze[i][j]=='E'){
                    ex=i;
                    ey=j;
                }
            }
        }
        cout<<dfs(sx,sy,d,direction1)<<" "<<dfs(sx,sy,d,direction2)<<" "<<bfs(sx,sy)<<endl;
    }
    return 0;
}
