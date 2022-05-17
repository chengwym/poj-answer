#include <iostream>
#include <cstring>
#include <math.h>
#define INF 0x7f
using namespace std;
struct Node{
    long long  x,y;
}node[5005];
int dp[1000005];
int main(){
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        memset(dp,-1,sizeof(dp));
        memset(node,0,sizeof(node));
        
        for (int i=0;i<n;i++){
            cin>>node[i].x>>node[i].y;
        }
        dp[node[0].x]=0;
        for (int i=1;i<n;i++){
            int dis=sqrt(double(node[i].y*node[i].y)-double((node[i].y-node[0].y)*(node[i].y-node[0].y)));
            for (int j=1;j<=dis;j++){
                if(node[i].x-j<node[0].x) break;
                if(dp[node[i].x-j]==-1) continue;
                else{
                    int temp=min(node[i].x+j,node[n-1].x);
                    if(dp[temp]==-1) dp[temp]=dp[node[i].x-j]+1;
                    else dp[temp]=min(dp[node[i].x-j]+1,dp[temp]);
                }
            }
        }
        cout<<dp[node[n-1].x]<<endl;
    }
    return 0;
}
