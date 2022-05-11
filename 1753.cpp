#include <iostream>
#include <cstring>
#define int_max 0x7fffffff
using namespace std;
int board[5][5];
int press[6][5];
int ans=int_max;
int guess(int goal){
    int temp=0;
    for (int i=1;i<=4;i++){
        if(press[1][i]==1) temp++;
    }
    for (int i=2;i<=4;i++){
        for (int j=1;j<=4;j++){
            press[i][j]=(press[i-1][j]+press[i-2][j]+board[i-1][j]+press[i-1][j-1]+press[i-1][j+1]+goal)%2;
            if(press[i][j]==1) temp++;
        }
    }
    for(int i=1;i<=4;i++){
        if(board[4][i]!=(press[4][i]+press[4][i-1]+press[4][i+1]+press[3][i]+goal)%2) return int_max;
    }
    return temp;
}
void enumerate(int goal){
    memset(press,0,sizeof(press));
    int c=1;
    press[1][1]=0;
    int s=1<<4;
    while(s--){
        ans=min(guess(goal),ans);
        c=1;
        press[1][c]++;
        while(press[1][c]>1){
            press[1][c]=0;
            c++;
            press[1][c]++;
        }
    }
}
int main(){
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    char c;
    for (int i=1;i<=4;i++){
        for (int j=1;j<=4;j++){
            cin>>c;
            if(c=='w') board[i][j]=1;
            else board[i][j]=0;
        }
    }
    enumerate(1);
    enumerate(0);
    if(ans==int_max){
        cout<<"Impossible";
    }else{
        cout<<ans;
    }
    return 0;
}
