#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int board[4][4];
bool state[4][4];
int main(){
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    char c;
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
           cin>>c;
           if(c=='+'){
               state[i][j]=!state[i][j];
               for (int k=0;k<4;k++){
                   state[i][k]=!state[i][k];
                   state[k][j]=!state[k][j];
               }
           }
        }
    }
    vector<pair<int,int>>ans;
    int sum=0;
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            if(state[i][j]==1){
                sum++;
                ans.push_back(pair<int,int>(i,j));
            }
        }
    }
    cout<<sum<<endl;
    for (int i=0;i<sum;i++){
        cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
    }
    return 0;
}
