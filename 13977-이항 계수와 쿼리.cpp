#include <bits/stdc++.h>
#define MOD 1'000'000'007
using namespace std;

int N;
long long fac[4000001];

long long pmod(long long a, long long p){
    if(p == 1) return a % MOD;
    if(p & 1) return pmod(a,p-1) * a % MOD;

    return pmod(a * a % MOD, p/2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    fac[0] = fac[1] = 1;
    for(long long i = 2; i < 4000001; i++){
        fac[i] = fac[i-1] * i % MOD;
    }

    for(int i = 0; i < N; i++){
        long long n, r;
        cin >> n >> r;
        cout << fac[n] * pmod(fac[n-r] * fac[r] % MOD, MOD-2) % MOD << "\n";
    }
    return 0;
}

