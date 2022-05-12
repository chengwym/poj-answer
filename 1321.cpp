#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int n,k,num;
char board[10][10];
bool stater[10],statel[10];
void dfs(int cnt,int k){
    if(cnt==n*n){
        if(k==0) num++;
        return;
    }
    int x=cnt/n,y=cnt%n;
    if(board[x][y]=='#'&&stater[x]==0&&statel[y]==0){
        stater[x]=1;
        statel[y]=1;
        dfs(cnt+1,k-1);
        stater[x]=0;
        statel[y]=0;
        dfs(cnt+1,k);
    }else{
        dfs(cnt+1,k);
    }
}
int main(){
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    while(cin>>n>>k&&n!=-1&&k!=-1){
        memset(board,0,sizeof(board));
        memset(stater,0,sizeof(stater));
        memset(statel,0,sizeof(statel));
        num=0;
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                cin>>board[i][j];
            }
        }
        dfs(0,k);
        cout<<num<<endl;
    }
    return 0;
}
