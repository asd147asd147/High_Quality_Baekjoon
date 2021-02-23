#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    int dp[N][3];
    cin >> dp[0][0] >> dp[0][1] >> dp[0][2];
    for(int i = 1; i < N; i++){
        int R,G,B;
        cin >> R >> G >> B;
        dp[i][0] = R+min(dp[i-1][1],dp[i-1][2]);
        dp[i][1] = G+min(dp[i-1][0],dp[i-1][2]);
        dp[i][2] = B+min(dp[i-1][0],dp[i-1][1]);
    }
    cout << min({dp[N-1][0],dp[N-1][1],dp[N-1][2]});

	return 0;
}
