#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <string>
using namespace std;
int n,map[21][21];
bool state[21];
int ans=0;
void dfs(int id,int sum){
    state[id]=1;
    int temp=sum;
    for (int i=1;i<=n;i++){
        if(state[i]) temp-=map[id][i];
        else temp+=map[id][i];
    }
    ans=max(temp,ans);
    if(temp>sum){
        for (int i=id+1;i<=n;i++){
            dfs(i,temp);
        }
    }
    state[id]=0;
}
int main(){
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin>>map[i][j];
        }
    }
    dfs(1,0);
    cout<<ans;
    return 0;
}
