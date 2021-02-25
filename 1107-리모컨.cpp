#include <bits/stdc++.h>

using namespace std;

int N,M;
bool num[10] = {false,};

int validNum(int n){
    int cnt = 0;
    if(n == 0) return !num[0];
    while(n>0){
        if(!num[n%10]){
            n /= 10;
            cnt++;
        }
        else{
            return 0;
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int t;
        cin >> t;
        num[t] =  true;
    }
    int ans = abs(N-100);
    int ran = ans;
    for(int i = N; i >= max(N - ran, 0); i--){
        int k = 0;
        if(k = validNum(i)){
            if(N == i) ans = min(ans,k);
            else ans = min(ans, k+N-i);
        }
    }
    for(int i = N; i <= N + ran; i++){
        int k = 0;
        if(k = validNum(i)){
            if(N == i) ans = min(ans,k);
            else ans = min(ans, k+i-N);
        }
    }
    cout << ans;

	return 0;
}
