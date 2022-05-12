#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int p,q;
int direction[8][2]={{-1,-2},{1,-2},{-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2}};
bool state[26][26];
vector<char>ans;
bool win=false;
void dfs(int x,int y,int num,vector<char>temp){
    if(win) return;
    temp.push_back('A'+y-1);
    temp.push_back('1'+x-1);
    state[x][y]=true;
    if(num==p*q) {
        win=true;
        ans=temp;
        return;
    }
    for (int i=0;i<8;i++){
        if(win) return; 
        int newx=x+direction[i][0];
        int newy=y+direction[i][1];
        if(newx<1||newy<1||newx>p||newy>q||state[newx][newy]==1) continue;
        dfs(newx,newy,num+1,temp);
    }
    state[x][y]=false;
    temp.pop_back();
    temp.pop_back();
}
int main(){
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    int n;
    cin>>n;
    for (int k=1;k<=n;k++){
        cout<<"Scenario #"<<k<<":"<<endl;
        cin>>p>>q;
        if(q*p>26) {
            cout<<"impossible"<<endl;
            continue;
        }
        win=false;
        memset(state,0,sizeof(state));
        ans.clear();
        vector<char>temp;
        dfs(1,1,1,temp);
        if(win){
            for (int i=0;i<ans.size();i++){
                cout<<ans[i];
            }
            cout<<endl;
        }else{
            cout<<"impossible"<<endl;
        }
        cout<<endl;
    }
    return 0;
}
