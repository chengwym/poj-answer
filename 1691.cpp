#include <iostream>
#include <cstring>
using namespace std;
#define int_max 0x7fffffff
const int N = 20;
int deg[N],n;
bool map[N][N],vis[N];
int ans=int_max;
struct Node{
    int x1 ,x2 ,y1 ,y2 ,color;
}e[N];

void init(){
    memset(deg,0,sizeof(deg));
    memset(map,0,sizeof(map));
    memset(e,0,sizeof(e));
    memset(vis,0,sizeof(vis));
    ans=int_max;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>e[i].y1>>e[i].x1>>e[i].y2>>e[i].x2>>e[i].color;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if(e[i].y2==e[j].y1&&e[i].x2>=e[j].x1&&e[i].x1<=e[j].x2){
                deg[j]++;
                map[i][j]=true;
            }
        }
    }
}

void dfs(int sum,int step,int color){
    if(step>ans) return;
    if(sum==n){
        ans=min(ans,step);
        return;
    }
    for (int i=1;i<=n;i++){
        if(!vis[i]&&!deg[i]){
            vis[i]=1;
            for (int j=1;j<=n;j++){
                if(map[i][j]){
                    deg[j]--;
                }
            }
            if(e[i].color==color){
                dfs(sum+1,step,color);
            }else{
                dfs(sum+1,step+1,e[i].color);
            }
            vis[i]=0;
            for (int j=1;j<=n;j++){
                if(map[i][j]){
                    deg[j]++;
                }
            }
        }
    }
}

int main(){
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    int t;cin>>t;
    while(t--){
        init();
        dfs(0,0,0);
        cout<<ans<<endl;
    }
    return 0;
}
