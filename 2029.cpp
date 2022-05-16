#include <iostream>
#include <cstring>
using namespace std;
#define int_max 0x7fffffff
#define lowbit(a) a&(-a)
int w,h,map[105][105];
void update(int x,int y){
    for (int i=x;i<=w;i+=lowbit(i))
        for (int j=y;j<=h;j+=lowbit(j))
            map[i][j]++;
}
int ask(int x,int y){
    int ans=0;
    for (int i=x;i>0;i-=lowbit(i))
        for (int j=y;j>0;j-=lowbit(j))
            ans+=map[i][j];
    return ans;
}
int main(){
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    int n;
    while(cin>>n&&n){
        memset(map,0,sizeof(map));
        cin>>w>>h;
        while(n--){
            int x,y;
            cin>>x>>y;
            update(x,y);
        }
        int S,T;
        cin>>S>>T;
        int ans=-1;
        for (int i=S;i<=w;i++){
            for (int j=T;j<=h;j++){
                ans=max(ans,ask(i,j)-ask(i-S,j)-ask(i,j-T)+ask(i-S,j-T));
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
