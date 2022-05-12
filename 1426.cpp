#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
long long n;
bool flag=false;
void dfs(long long t,int step){
    if(flag||step>18){
        return;
    }
    if(t%n==0){
        flag=true;
        printf("%lld\n",t);
        return;
    }
    dfs(t*10,step+1);
    if(flag) return;
    dfs(t*10+1,step+1);
    if(flag) return; 
}
int main(){
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    while((cin>>n)&&n){
        flag=false;
        dfs(1,0);
    }
    return 0;
}
