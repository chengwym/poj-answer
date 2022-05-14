#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <string>
using namespace std;
int board[9][9];
bool line[9][10],row[9][10],block[3][3][10];
string str;
bool win=false;
bool check(int i,int j,int k){
	if(row[i][k]||line[j][k]||block[i/3][j/3][k]) return false;
	return true;
}
void dfs(int cnt){
	if(win==true) return;
	if(cnt==81) {
		win=true;
		return;
	}
	int i=cnt/9,j=cnt%9;
	if(board[i][j]!=0) {
		dfs(cnt+1);
		return;
	}
	for (int k=1;k<=9;k++){
		if(win) return;
		if(check(i,j,k)){
			row[i][k]=true;
			line[j][k]=true;
			block[i/3][j/3][k]=true;
			board[i][j]=k;
			dfs(cnt+1);
			if(win) return;
			board[i][j]=0;
			row[i][k]=false;
			line[j][k]=false;
			block[i/3][j/3][k]=false;
		}
	}
}
int main(){
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    int t;cin>>t;
	while(t--){
		memset(board,0,sizeof(board));
		memset(line,0,sizeof(line));
		memset(row,0,sizeof(row));
		memset(block,0,sizeof(block));
		win=false;
		for (int i=0;i<9;i++){
			cin>>str;
			for (int j=0;j<9;j++){
				board[i][j]=str[j]-'0';
				line[j][board[i][j]]=true;
				row[i][board[i][j]]=true;
				block[i/3][j/3][board[i][j]]=true;
			}
		}
		dfs(0);
		for (int i=0;i<9;i++){
			for (int j=0;j<9;j++){
				cout<<board[i][j];
			}
			cout<<endl;
		}
	}
    return 0;
}
