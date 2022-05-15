#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <map>
#define int_max 0x7fffffff
using namespace std;
int a[105],dp[105],p[105],sum[105];
int main(){
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        memset(dp,0,sizeof(dp));
        memset(a,0,sizeof(a));
        memset(sum,0,sizeof(sum));
        memset(p,0,sizeof(p));
        int c;
        cin>>c;
        for (int i=1;i<=c;i++){
            cin>>a[i]>>p[i];
            sum[i]=sum[i-1]+a[i];
        }
        for (int i=1;i<=c;i++){
            dp[i]=dp[i-1]+(10+a[i])*p[i];
            for (int j=1;j<i;j++){
                dp[i]=min(dp[i],dp[j-1]+(sum[i]-sum[j-1]+10)*p[i]);
            }
        }
        cout<<dp[c]<<endl;
    }
    return 0;
}
