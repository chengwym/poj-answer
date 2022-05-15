#include <iostream>
using namespace std;
short n,dp[5001][5001];
char *s1,*s2,c;
void init(){
    cin>>n;
    s1=new char [n+1];
    s2=new char [n+1];
    for (int i=1;i<=n;i++){
        cin>>c;
        s1[i]=s2[n+1-i]=c;        
    }
}
int main(){
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    init();
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if(s1[i]==s2[j]){
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    delete []s1;
    delete []s2;
    cout<<n-dp[n][n];
    return 0;
}
