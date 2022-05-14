#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <string>
using namespace std;
#define int_max 0x7fffffff
bool map[27][27];
bool state[27][27];
bool empty[27];
int n;
string str;
int ans=int_max;
bool win=false;
void dfs(int id,int num){
    if(id==n+1) {
		win=true;
        return;
    }
    for (int i=1;i<=num;i++){
		if(win) return;
        bool flag=true;
        for (int j=1;j<=n;j++){
            if(state[i][j]==true&&map[j][id]==true){
                flag=false;
                break;
            }
        }
        if(flag){
            state[i][id]=true;
            dfs(id+1,num);
            state[i][id]=false;
        }
    }

}
int main(){
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    while(cin>>n&&n){
        memset(map,0,sizeof(map));
        memset(state,0,sizeof(state));
        memset(empty,0,sizeof(empty));
		win=false;
        int tmp=n;
        ans=int_max;
        while(tmp--){
            cin>>str;
            for (int i=2;i<str.size();i++){
                map[str[0]-'A'+1][str[i]-'A'+1]=true;
            }
        }
        for (int i=1;i<=n;i++){
			dfs(1,i);
			if(win){
				if(i==1){
		            cout<<i<<" channel needed."<<endl;
		        }else{
		            cout<<i<<" channels needed."<<endl;
		        }
				break;
			}
		}
        
    }
    return 0;
}
