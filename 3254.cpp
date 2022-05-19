#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int map[14][14],dp[14][(1<<13)];
int state[14];
int main(){
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    int m,n;
    cin>>m>>n;
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++){
            cin>>map[i][j];
            if(map[i][j] == 0) state[i]+=(1<<(j-1));
        }
    }
    int num=(1<<n);
    for (int j=0;j<num;j++){
        if((state[1]&j)||(j&(j<<1))) continue;
        dp[1][j]=1;
    }
    for (int i=2;i<=m;i++){
        for (int j=0;j<num;j++){
            if((state[i]&j)||(j&(j<<1))) continue;
            for (int k=0;k<num;k++){
                if(state[i-1]&k||k&j||(k&(k<<1))) continue;
                dp[i][j]+=(dp[i-1][k]%100000000);
                dp[i][j]%=100000000;
            }
        }
    }
    int ans=0;
    for (int j=0;j<num;j++){
        if(state[m]&j) continue;
        ans+=(dp[m][j]%100000000);
    }
    cout<<ans%100000000;
    return 0;
}
