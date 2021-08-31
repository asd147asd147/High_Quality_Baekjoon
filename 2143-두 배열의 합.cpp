#include <bits/stdc++.h>

using namespace std;

long long T;
int N,M;
vector<long long> A, B;
map<long long,long long> A_cnt, B_cnt;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T >> N;
	A.resize(N+1);
	A[0] = 0;
	for(int i = 1; i <= N; i++){
        cin >> A[i];
        A[i] += A[i-1];
	}
	cin >> M;
	B.resize(M+1);
	B[0] = 0;
	for(int i = 1; i <=M; i++){
        cin >> B[i];
        B[i] += B[i-1];
	}

	for(int i = 0; i < N; i++){
        for(int j = i+1; j <= N; j++){
            A_cnt[A[j] - A[i]] += 1;
        }
	}

	for(int i = 0; i < M; i++){
        for(int j = i+1; j <= M; j++){
            B_cnt[B[j] - B[i]] += 1;
        }
	}

	auto a_iter = A_cnt.begin();
	auto b_iter = B_cnt.rbegin();
    long long ans = 0;
	while(a_iter != A_cnt.end() && b_iter != B_cnt.rend()){
        if(a_iter->first+b_iter->first == T){
            ans += a_iter->second * b_iter->second;
            a_iter++;
        }
        else if(a_iter->first+b_iter->first > T){
            b_iter++;
        }
        else if(a_iter->first+b_iter->first < T){
            a_iter++;
        }
	}
    cout << ans;

	return 0;
}
