#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <string>
using namespace std;
const int N=7500;
int C,G,c[21],g[21],dp[21][15005];
int main(){
    cin>>C>>G;
    for (int i=1;i<=C;i++){
        cin>>c[i];
    }
    for (int i=1;i<=G;i++){
        cin>>g[i];
    }
    dp[0][N]=1;
    for (int i=1;i<=G;i++){
        for (int j=1;j<=C;j++){
            for (int k=0;k<=15005;k++){
                if(k+g[i]*c[j]>=0){
                    dp[i][k+g[i]*c[j]]+=dp[i-1][k];
                }
            }
        }
    }
    cout<<dp[G][N];
    return 0;
}
