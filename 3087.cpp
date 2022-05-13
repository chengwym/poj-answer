#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <string>
using namespace std;
int c;
string s1,s2,s12,aim;
void f(){
    set<string>vis;
    for (int k=1;;k++){
        s12="";
        for (int i=0;i<c;i++){
            s12+=s2[i];
            s12+=s1[i];
        }
        if(s12==aim){
            cout<<k<<endl;
            return;
        }else if(s12!=aim&&vis.count(s12)) {
            cout<<-1<<endl;
            return;
        }else{
            vis.insert(s12);
            for (int i=0;i<c;i++){
                s1[i]=s12[i];
                s2[i]=s12[i+c];
            }
        }
    }
}
int main(){
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    int t;
    cin>>t;
    for (int i=1;i<=t;i++){
        cin>>c;
        cin>>s1>>s2>>aim;
        cout<<i<<" ";
        f();
    }
    return 0;
}
