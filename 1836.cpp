#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <map>
using namespace std;
int dp[1005][2];
double h[1005];
int main(){
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>h[i];
    }
    int ans1=0,ans2=0;
    for (int i=1;i<=n;i++){
        dp[i][0]=1;
        for (int j=1;j<i;j++){
            if(h[i]>h[j]){
                dp[i][0]=max(dp[i][0],dp[j][0]+1);
            }
        }
    }
    for (int i=n;i>=1;i--){
        dp[i][1]=1;
        for (int j=n;j>i;j--){
            if(h[i]>h[j]){
                dp[i][1]=max(dp[i][1],dp[j][1]+1);
            }
        }
    }
    for(int i=1;i<=n;i++){
        dp[i][0]=max(dp[i][0],dp[i-1][0]);
    }
    for (int i=n;i>=1;i--){
        dp[i][1]=max(dp[i+1][1],dp[i][1]);
    }
    int ans=0;
    for (int i=1;i<=n;i++){
        ans=max(ans,dp[i][0]+dp[i+1][1]);
    }
    cout<<n-ans;
    return 0;
}
