#include<bits/stdc++.h>
using namespace std;
int n,a,b,g;
char x;
main(){
    for(cin>>n;cin>>n;a=b=0){
        map<pair<int,int>,int>m;
        for(;n--;){
        cin>>x,a+=x=='D',b+=x=='K';
        g=gcd(a,b);
        cout<<++m[{a/g,b/g}]<<' ';
    }}
}
