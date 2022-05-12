#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int L,R,C,sx,sy,sz,ex,ey,ez;
char board[35][35][35];
bool state[35][35][35];
int direction[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
struct node{
    int x,y,z;
    node(int x_,int y_,int z_):x(x_),y(y_),z(z_){}
};
void bfs(){
    queue<node>q;
    q.push(node(sx,sy,sz));
    state[sx][sy][sz]=true;
    int step=0;
    while(!q.empty()){
        int size=q.size();
        step++;
        while(size--){
            node no=q.front();
            q.pop();
            int nx=no.x,ny=no.y,nz=no.z;
            for (int i=0;i<6;i++){
                int newx=nx+direction[i][0],newy=ny+direction[i][1],newz=nz+direction[i][2];
                if(newx<1||newy<1||newz<1||newx>L||newy>R||newz>C||state[newx][newy][newz]==true||board[newx][newy][newz]=='#') continue;
                state[newx][newy][newz]=true;
                if(newx==ex&&newy==ey&&newz==ez) {
                    printf("Escaped in %d minute(s).\n",step);
                    return;
                }
                q.push(node(newx,newy,newz));
            }
        }
    }
    cout<<"Trapped!"<<endl;
}
int main(){
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    while(cin>>L>>R>>C&&L&&R&&C){
        memset(board,0,sizeof(board));
        memset(state,0,sizeof(state));
        for (int i=1;i<=L;i++){
            for (int j=1;j<=R;j++){
                for (int k=1;k<=C;k++){
                    cin>>board[i][j][k];
                    if(board[i][j][k]=='S'){
                        sx=i;sy=j;sz=k;
                    }
                    if(board[i][j][k]=='E'){
                        ex=i;ey=j;ez=k;
                    }
                }
            }
        }
        bfs();
    }   
    return 0;
}
