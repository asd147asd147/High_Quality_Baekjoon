#include <bits/stdc++.h>

using namespace std;

int N, M, K;
long long arr[1'000'001] = {0,};
long long num[1'000'001] = {0,};

long long sum(int i){
    long long result = 0;
    while(i > 0){
        result += arr[i];
        i -= (i & -i);
    }
    return result;
}

void update(int i, long long diff){
    while(i <= N){
        arr[i] += diff;
        i += (i & -i);
    }
}

long long getSection(int s, int e){
    return sum(e) - sum(s-1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;


	for(int i = 1; i <= N; i++){
        cin >> num[i];
        update(i, num[i]);
	}

	for(int i = 0; i < M+K; i++){
        long long a,b,c;
        cin >> a >> b >> c;
        if(a == 1){
            update(b,c-num[b]);
            num[b] = c;
        }
        else{
            cout << getSection(b,c) << "\n";
        }
	}

	return 0;
}
