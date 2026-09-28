
#include<iostream>
using namespace std;

int main(){
    string e; cin>>e;
    int s[100],t=-1,x,y;
    for(char c:e)
        if(c>='0'&&c<='9') s[++t]=c-'0';
        else{
            y=s[t--]; x=s[t--];
            if(c=='+')s[++t]=x+y;
            if(c=='-')s[++t]=x-y;
            if(c=='*')s[++t]=x*y;
            if(c=='/')s[++t]=x/y;
        }
    cout<<s[t];
}