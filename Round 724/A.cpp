#include<iostream>
int n,x,b;
main(){
    for(scanf("%d");std::cin>>n;b=0){for(;n--;std::cin>>x,b|=x<0);
    if(b)puts("No");
    else {puts("Yes 101");while(b!=101)std::cout<<b++<<' ';}
    }
}
