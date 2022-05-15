#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <map>
using namespace std;
int W,L;
string str,dic[605];
int dp[306];
int main(){
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin>>W>>L;
    cin>>str;
    for (int i=0;i<W;i++){
        cin>>dic[i];
    }
    dp[L]=0;
    for (int i=L-1;i>=0;i--){
        dp[i]=dp[i+1]+1;
        for (int j=0;j<W;j++){
            int len=dic[j].size();
            if(str[i]==dic[j][0]&&L-i>=len){
                int pSentence=i,pDic=0;
                while(pSentence<L){
                    if(str[pSentence]==dic[j][pDic]){
                        pSentence++;
                        pDic++;
                    }else{
                        pSentence++;
                    }
                    if(pDic==len){
                        dp[i]=min(dp[i],dp[pSentence]+(pSentence-i)-len);
                    }
                }
            }
        }
    }
    cout<<dp[0];
    return 0;
}
