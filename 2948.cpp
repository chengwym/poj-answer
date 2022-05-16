#include <iostream>
#include <cstring>
using namespace std;
int n,m,Y[505][505],G[505][505],y[505][505],g[505][505],dp[505][505];
int main(){
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    while(cin>>n>>m&&n&&m){
        memset(Y,0,sizeof(Y));
        memset(G,0,sizeof(G));
        memset(g,0,sizeof(g));
        memset(y,0,sizeof(y));
        memset(dp,0,sizeof(dp));
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++){
                scanf("%d",&Y[i][j]);
                y[i][j]=y[i][j-1]+Y[i][j];
            }
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++){
                scanf("%d",&G[i][j]);
                g[i][j]=g[i-1][j]+G[i][j];
            }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                dp[i][j]=max(dp[i-1][j]+y[i][j],dp[i][j-1]+g[i][j]);
            }
        }
        cout<<dp[n][m]<<endl;
    }
    return 0;
}
