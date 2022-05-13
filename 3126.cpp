#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
bool prime[10000],state[10000];
int p[10000];
void Prime(){
    int cnt=0;
    for (int i=2;i<10000;i++){
        if(prime[i]==false) p[cnt++]=i;
        for (int j=0;j<cnt&&i*p[j]<10000;j++){
            prime[i*p[j]]=true;
            if(i%p[j]==0) break;
        }
    }
}
void bfs(int a,int b){
    queue<int>q;
    q.push(a);
    int step=0;
    if(a==b) {
        cout<<step<<endl;
        return;
    }
    while(!q.empty()){
        int size=q.size();
        step++;
        while(size--){
            int now=q.front();
            q.pop();
            int temp=now;
            int num[4],tnum[4],c=0;
            while(temp){
                tnum[c]=temp%10;
                num[c]=temp%10;
                c++;
                temp/=10;
            }
            for (int i=0;i<4;i++){
                for (int j=0;j<10;j++){
                    if(i==3&&j==0) continue;
                    tnum[i]=j;
                    int result=tnum[0]+tnum[1]*10+tnum[2]*100+tnum[3]*1000;
                    if(prime[result]==true||result==now||state[result]==true) continue;
                    q.push(result);
                    state[result]=true; 
                    if(result==b){
                        cout<<step<<endl;
                        return;
                    }
                }
                tnum[i]=num[i];
            }
        }
    }
}
int main(){
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    Prime();
    int n;cin>>n;
    while(n--){
        memset(state,0,sizeof(state));
        int a,b;
        cin>>a>>b;
        bfs(a,b);
    }
    return 0;
}
