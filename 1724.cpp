#include <iostream>
#include <cstring>
using namespace std;
#define int_max 0x7fffffff
int ans=int_max,K,N,R;
bool vis[105];

struct Road{
    int l,t,d;
}road[105][105];
int length[105];
int minLen[105][10005];

void init(){
    cin>>K>>N>>R;
    memset(road,0,sizeof(road));
    memset(minLen,1,sizeof(minLen));
    int s,d,l,t;
    while(R--){
        scanf("%d%d%d%d",&s,&d,&l,&t);
        road[s][length[s]].d=d;
        road[s][length[s]].l=l;
        road[s][length[s]].t=t;
        length[s]++;
    }
    vis[1]=true;
}

void dfs(int nowstate,int len,int k){
    if(nowstate==N){
        ans=min(ans,len);
        return;
    }
    for (int i=0;i<length[nowstate];i++){
        if(road[nowstate][i].l!=0&&k>=road[nowstate][i].t&&vis[road[nowstate][i].d]==false){
            if(len+road[nowstate][i].l>ans||(len+road[nowstate][i].l)>minLen[road[nowstate][i].d][k-road[nowstate][i].t]) continue;
            vis[road[nowstate][i].d]=true;
            minLen[road[nowstate][i].d][k-road[nowstate][i].t]=len+road[nowstate][i].l;
            dfs(road[nowstate][i].d,len+road[nowstate][i].l,k-road[nowstate][i].t);
            vis[road[nowstate][i].d]=false;
        }
    }
}

int main(){
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    init();
    dfs(1,0,K);
    if(ans==int_max){
        cout<<-1;
    }else{
        cout<<ans;
    }
    return 0;
}
