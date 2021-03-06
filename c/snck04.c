//sg
#include <stdio.h>
#include <stdlib.h>
typedef long long LL;
int phi[1000005], prime[1000005];
LL dn[1000005];

int fi(int n)
{
    //already have the result
    if(phi[n] != -1) {
        return phi[n];
    }
   
    //prime number
    
    if(prime[n] == 1) {
        phi[n] = n - 1;
        return phi[n];
    }
    
    int i = 2;
    double result = n;
    int nb = n;

    while(n != 1)
    {
        if(n % i == 0) {//found a divisor
            result = result * (1 - ((float)1 / i));
        }
        while(n % i == 0) {
            n = n / i;
        }
        i++;
    }
    phi[nb] = result;
    return phi[nb];
}

void Dn(int N)
{
    int i;
    for(i = 2; i <= N; i++) {
        dn[i] = dn[i-1] + phi[i];
    }
}

int main(int argc, char *argv[])
{

    LL i, j , ib;
    int N = 1000005;
    for(i = 0; i < N; i++) {
        dn[i] = -1;
        phi[i] = i;
        prime[i] = 1;
    }

  
    dn[0] = 0;
    dn[1] = 0;

    phi[1] = 1;
    phi[2] = 1;
    phi[3] = 2;
    int t, n;
    scanf("%d", &t);

    prime[0] = prime[1] = 0; 

    for(i = 2; i * i <= N; i++) {
        if(prime[i] == 1) {
            for(j = i * i; j <= N; j += i) {
                prime[j] = 0;
            }
        }
    }
    
   for(i = 2; i <= N; i++) {
      if(prime[i] == 1) {
           for(j = i; j <= N; j += i)
               phi[j] = phi[j] * ((float)(i - 1) / i);   
      }
   }

    Dn(N);

    while(t--) {
        scanf("%d", &n);
        printf("%lld\n", dn[n] + 2);
    } 

    return 0;
}
