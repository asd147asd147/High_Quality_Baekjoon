#include <bits/stdc++.h>

using namespace std;

<<<<<<< HEAD
int N,S;
int half;
vector<int> vec;
vector<int> f,b;

void forwarding(int i, int sum){
    if(i > half) return;
    forwarding(i+1, sum);
    sum+=vec[i];
    f.push_back(sum);
    forwarding(i+1, sum);
}

void backwarding(int i, int sum){
    if(i == N) return;
    backwarding(i+1, sum);
    sum+=vec[i];
    b.push_back(sum);
    backwarding(i+1, sum);
=======
int N,S, cnt = 0;
vector<int> vec;
map<int,int> mp1, mp2;

void leftMap(int idx, int sum){
    if(idx == N/2){
        mp1[sum]++;
        return;
    }
    leftMap(idx+1, sum);
    leftMap(idx+1, sum+vec[idx]);
}

void rightMap(int idx, int sum){
    if(idx == N){
        mp2[sum]++;
        return;
    }
    rightMap(idx+1, sum);
    rightMap(idx+1, sum+vec[idx]);
>>>>>>> 367559d878cbd5f37274e8fe925339f910afd9fa
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> S;
<<<<<<< HEAD
	vec.resize(N);
=======
    vec.resize(N);
>>>>>>> 367559d878cbd5f37274e8fe925339f910afd9fa
	for(int i = 0; i < N; i++){
        cin >> vec[i];
	}

<<<<<<< HEAD
    half = N/2;
    f.push_back(0);
    b.push_back(0);
    forwarding(0,0);
    backwarding(half+1,0);
    sort(f.begin(), f.end());
    sort(b.begin(), b.end(), greater<int>());

    long long cnt = 0;
    int f_i = 0, b_i = 0;

    while(f_i < f.size() && b_i < b.size()){
        int sum = f[f_i] + b[b_i];
        if(sum == S){
            long long f_s = 1, b_s = 1;
            f_i++, b_i++;
            while(f_i < f.size() && f[f_i] == f[f_i-1]){
                f_i++;
                f_s++;
            }
            while(b_i < b.size() && b[b_i] == b[b_i-1]){
                b_i++;
                b_s++;
            }
            cnt += f_s * b_s;
        }
        else if(sum < S) f_i++;
        else if(sum > S) b_i++;
    }

    if(S == 0) cnt--;
    cout << cnt;
=======
	leftMap(0,0);
	rightMap(N/2,0);

	auto frontIndex = mp1.begin();
	auto backIndex = mp2.rbegin();
	while(frontIndex != mp1.end() && backIndex != mp2.rend();)


	if(S == 0) cnt--;
	cout << cnt;
>>>>>>> 367559d878cbd5f37274e8fe925339f910afd9fa

	return 0;
}
