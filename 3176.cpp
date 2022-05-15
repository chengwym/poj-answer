#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <map>
#define int_max 0x7fffffff
using namespace std;
int a[355][355],dp[355][355];
int main(){
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    int N;
    cin>>N;
    for (int i=1;i<=N;i++){
        for (int j=1;j<=i;j++){
            cin>>a[i][j];
        }
    }
    for (int i=1;i<=N;i++){
        for (int j=1;j<=N;j++){
            dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+a[i][j];
        }
    }
    int ans=0;
    for (int i=1;i<=N;i++){
        ans=max(ans,dp[N][i]);
    }
    cout<<ans;
    return 0;
}
