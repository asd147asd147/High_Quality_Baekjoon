#include <bits/stdc++.h>

using namespace std;
long long N;
long long ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    ans = N;
    for(long long i = 2; i <= sqrt(N); i++){
        if(N % i == 0){
            ans -= ans/i;
            while(N % i == 0){
                N /= i;
            }
        }
    }
    if(N > 1){
        ans -= ans/N;
    }
    cout << ans;

    return 0;
}

