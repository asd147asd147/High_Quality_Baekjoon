#include <bits/stdc++.h>

using namespace std;

long long N;

bool primeArray[4000001];
vector<long long> prime;
vector<long long> subsum;

void calcPrime(){
    subsum.push_back(0);
    for(long long i = 2; i <= N+1; i++){
        primeArray[i] = true;
    }
    for (long long i = 2; i <= N+1; i++){
		if (primeArray[i]){
            subsum.push_back(subsum.back() + i);
			for (long long j = i * i; j <= N+1; j += i)
			    primeArray[j] = false;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	calcPrime();
	long long answer  = 0;
	int left = 0, right = 0;

	while(left <= right && right < subsum.size()){
        if(subsum[right] - subsum[left] < N){
            right++;
        }
        else if(subsum[right] - subsum[left] > N){
            left++;
        }
        else{
            answer++;
            right++;
        }
	}
	cout << answer;

	return 0;
}
