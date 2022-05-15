#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <map>
#define int_min -0x7fffffff
using namespace std;
string str1,str2;
int n1,n2;
char c;
int s1[105],s2[105],dp[105][105];
int Map[5][5]={{int_min,-3,-4,-2,-1},{-3,5,-1,-2,-1},{-4,-1,5,-3,-2},{-2,-2,-3,5,-2},{-1,-1,-2,-2,5}};
void init(){
    memset(s1,0,sizeof(s1));
    memset(s2,0,sizeof(s2));
    memset(dp,0,sizeof(dp));
    cin>>n1;
    for (int i=1;i<=n1;i++){
        cin>>c;
        if(c=='A') s1[i]=1;
        if(c=='C') s1[i]=2;
        if(c=='G') s1[i]=3;
        if(c=='T') s1[i]=4;
    }
    cin>>n2;
    for (int i=1;i<=n2;i++){
        cin>>c;
        if(c=='A') s2[i]=1;
        if(c=='C') s2[i]=2;
        if(c=='G') s2[i]=3;
        if(c=='T') s2[i]=4;
    }
}
int main(){
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    int N;
    cin>>N;
    while(N--){
        init();
        for (int i=1;i<=n1;i++){
            dp[i][0]=dp[i-1][0]+Map[0][s1[i]];
        }
        for (int i=1;i<=n2;i++){
            dp[0][i]=dp[0][i-1]+Map[s2[i]][0];
        }
        for (int i=1;i<=n1;i++){    
            for (int j=1;j<=n2;j++){
                dp[i][j]=max(max(dp[i-1][j]+Map[0][s1[i]],dp[i][j-1]+Map[0][s2[j]]),dp[i-1][j-1]+Map[s1[i]][s2[j]]);
            }
        }   
        cout<<dp[n1][n2]<<endl;
    }
    return 0;
}
