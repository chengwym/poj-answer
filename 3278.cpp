#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int N=200005;
int n,k;
bool state[N];
void bfs(){
    queue<int>q;
    q.push(n);
    int step=0;
    state[n]=true;
    if(n==k) {
        cout<<step;
        return;
    }
    while(!q.empty()){
        int size=q.size();
        step++;
        while(size--){
            int now=q.front();
            q.pop();
            if(now+1<N&&state[now+1]==false){
                q.push(now+1);
                state[now+1]=true;
                if(now+1==k) {
                    cout<<step;
                    return;
                }
            }
            if(now-1>=0&&state[now-1]==false){
                q.push(now-1);
                state[now-1]=true;
                if(now-1==k) {
                    cout<<step;
                    return;
                }
            }
            if(2*now<N&&state[2*now]==false){
                q.push(now*2);
                state[now*2]=true;
                if(now*2==k) {
                    cout<<step;
                    return;
                }
            }
        }
    }
}
int main(){
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin>>n>>k;
    memset(state,0,sizeof(state));
    bfs();
    return 0;
}
