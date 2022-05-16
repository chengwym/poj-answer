#include <iostream>
#include <cstring>
using namespace std;
#define int_max 0x7fffffff
int vis[11],ans=int_max,n,m;
bool moneyRoad[11][11];

struct Road{
    int a,b,c,P,R;
}road[11];

void dfs(int nowCity,int sum){
    if(nowCity==n) {
        ans=min(ans,sum);
        return;
    }
    for (int i=1;i<=m;i++){
        if(nowCity==road[i].a&&vis[nowCity]<=3){
            vis[road[i].b]++;
            if(vis[road[i].c]){
                dfs(road[i].b,sum+road[i].P);
            }else{
                dfs(road[i].b,sum+road[i].R);
            }
            vis[road[i].b]--;
        }
    }
}

void init(){
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        cin>>road[i].a>>road[i].b>>road[i].c>>road[i].P>>road[i].R;
    }
}

int main(){
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    init();
    dfs(1,0);
    if(ans==int_max){
        cout<<"impossible";
    }else{
        cout<<ans;
    }
    return 0;
}
