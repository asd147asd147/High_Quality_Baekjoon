#include <bits/stdc++.h>

using namespace std;

int N;
unsigned long long W, coin = 0;
int p[17] = {0,};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> W;

	for(int i = 1; i <= N; i++){
        cin >> p[i];
	}

	unsigned long long price = 0;
	for(int i = 1; i <= N; i++){
        W += coin*p[i];
        if(p[i] <= p[i+1]){
            coin = W / p[i];
            W = W % p[i];
        }
        else{
            coin = 0;
        }
	}
	W += coin*p[N];
	cout << W;

	return 0;
}
