#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;

    int s[N];
    for(int i = 0; i < N; i++){
        cin >> s[i];
    }

    int dp[N] = {0,};

    dp[0] = s[0];
    dp[1] = s[0]+s[1];
    for(int i = 2; i < N; i++){
        dp[i] = s[i]+max(dp[i-2], s[i-1]+dp[i-3]);
    }

//    for(auto t : dp){
//        cout << t << " ";
//    }
//    cout << endl;

    cout << dp[N-1];
	return 0;
}
