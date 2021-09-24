#include <bits/stdc++.h>

using namespace std;

long long A, B;
long long cnt = 0;
long long mem[55] = {0,};

long long sum(long long x){
    long long ans = x & 1;
    for(int i = 54; i > 0; i--){
        if(x & (1LL << i)){
            ans += mem[i]+(x - (1LL << i) + 1);
            x -= 1LL << i;
        }
    }
    return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> A >> B;
    for(int i = 1; i <= 54; i++){
        mem[i] = i* (1LL << i-1);
    }

    cout << sum(B) - sum(A-1);

	return 0;
}
