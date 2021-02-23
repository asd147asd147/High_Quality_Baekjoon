#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;

    int dp[N+1] = {0,};

    dp[1] = 1;
    dp[2] = 0;
    dp[3] = 1;
    for(int i = 4; i < N+1; i++){
        dp[i] = dp[i-1] && dp[i-3] ? 0 : 1;
    }

    cout << (dp[N] ? "CY" : "SK");
	return 0;
}
