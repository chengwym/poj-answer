#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <string>
using namespace std;
int a,b,c;
bool state[105][105];
struct node{
    int x,y;
    string ans;
    node(int x_,int y_,string ans_=""):x(x_),y(y_),ans(ans_){}
};
void bfs(){
    queue<node>q;
    state[0][0]=true;
    q.push(node(0,0));
    int step=0;
    while(!q.empty()){
        int size=q.size();
        step++;
        while(size--){
            node no=q.front();
            q.pop();
            if(no.x!=a&&state[a][no.y]==false){
                q.push(node(a,no.y,no.ans+"FILL(1)\n"));
                state[a][no.y]=true;
                if(a==c||no.y==c){
                    cout<<step<<endl<<no.ans+"FILL(1)\n";
                    return;
                }
            }
            if(no.y!=b&&state[no.x][b]==false){
                q.push(node(no.x,b,no.ans+"FILL(2)\n"));
                state[no.x][b]=true;
                if(no.x==c||b==c){
                    cout<<step<<endl<<no.ans+"FILL(2)\n";
                    return;
                }
            }
            if(no.x!=0&&state[0][no.y]==false){
                q.push(node(0,no.y,no.ans+"DROP(1)\n"));
                state[0][no.y]=true;
                if(0==c||no.y==c){
                    cout<<step<<endl<<no.ans+"DROP(1)\n";
                    return;
                }
            }
            if(no.y!=0&&state[no.x][0]==false){
                q.push(node(no.x,0,no.ans+"DROP(2)\n"));
                state[no.x][0]=true;
                if(no.x==c||0==c){
                    cout<<step<<endl<<no.ans+"DROP(2)\n";
                    return;
                }
            }
            if(no.x+no.y>=b&&state[no.x+no.y-b][b]==false){
                q.push(node(no.x+no.y-b,b,no.ans+"POUR(1,2)\n"));
                state[no.x+no.y-b][b]=true;
                if(no.x+no.y-b==c||b==c){
                    cout<<step<<endl<<no.ans+"POUR(1,2)\n";
                    return;
                }
            }
            if(no.x+no.y<b&&state[0][no.x+no.y]==false){
                q.push(node(0,no.x+no.y,no.ans+"POUR(1,2)\n"));
                state[0][no.x+no.y]=true;
                if(0==c||no.x+no.y==c){
                    cout<<step<<endl<<no.ans+"POUR(1,2)\n";
                    return;
                }
            }
            if(no.x+no.y>=a&&state[a][no.x+no.y-a]==false){
                q.push(node(a,no.x+no.y-a,no.ans+"POUR(2,1)\n"));
                state[a][no.x+no.y-a]=true;
                if(a==c||no.x+no.y-a==c){
                    cout<<step<<endl<<no.ans+"POUR(2,1)\n";
                    return;
                }
            }
            if(no.x+no.y<a&&state[no.x+no.y][0]==false){
                q.push(node(no.x+no.y,0,no.ans+"POUR(2,1)\n"));
                state[no.x+no.y][0]=true;
                if(no.x+no.y==c||0==c){
                    cout<<step<<endl<<no.ans+"POUR(2,1)\n";
                    return;
                }
            }
        }   
    }
    cout<<"impossible";
}
int main(){
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin>>a>>b>>c;
    bfs();
    return 0;
}
