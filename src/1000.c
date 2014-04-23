#include <stdio.h>

int main(void)
{
    long long a,b;
    
    while(scanf("%lld %lld",&a,&b) != EOF){
        printf("%lld\n",a+b);
    }
}
