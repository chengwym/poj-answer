#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int board[22][22];
int direction[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int w,h,sx,sy,ex,ey;
const int int_max = 0x7fffffff;
int ans=int_max;
void dfs(int x,int y,int step){
    if(step==0) return;
    for (int i=0;i<4;i++){
        int tx=x;
        int ty=y;
        while(x+direction[i][0]<=h&&y+direction[i][1]<=w&&x+direction[i][0]>=1&&y+direction[i][1]>=1&&board[x+direction[i][0]][y+direction[i][1]]!=1){
            if(board[tx][ty]==3){
                ans=min(ans,11-step);
                break;
            }
            if(tx+direction[i][0]>h||ty+direction[i][1]>w||tx+direction[i][0]<1||ty+direction[i][1]<1) break;
            if(board[tx+direction[i][0]][ty+direction[i][1]]==1){
                board[tx+direction[i][0]][ty+direction[i][1]]=0;
                dfs(tx,ty,step-1);
                board[tx+direction[i][0]][ty+direction[i][1]]=1;
                break;
            }
            tx+=direction[i][0];
            ty+=direction[i][1];
        }
    }
}
int main(){
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    while(cin>>w>>h&&w&&h){
        memset(board,0,sizeof(board));
        ans=int_max;
        for (int i=1;i<=h;i++){
            for (int j=1;j<=w;j++){
                cin>>board[i][j];
                if(board[i][j]==2){
                    sx=i;
                    sy=j;
                }
                if(board[i][j]==3){
                    ex=i;
                    ey=j;
                }
            }
        }
        dfs(sx,sy,10);
        if(ans==int_max) cout<<-1<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}
