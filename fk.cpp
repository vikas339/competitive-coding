#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n,k,count=0;
        string a;
        cin>>n>>k;
        cin>>a;
        bool gg = 0;
        bool solved = 0;
        for(int i=0 ; i<=n ; i++){
            if(count>=k){
                solved=1;
                break;
            }
            if(a[i]=='*' && gg==0){
                count=1;
                gg = 1;
                continue;
            }
            if(a[i]=='*' && gg==1){
                count++;
                continue;

            }
            if(a[i]!='*' && gg==1){
                gg=0;
                count=0;
            }


        }
        if(count>=k){
            solved=1;
        }
        if(solved){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    
}