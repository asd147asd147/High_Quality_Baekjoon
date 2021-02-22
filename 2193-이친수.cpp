#include <iostream>

using namespace std;


long long DP[91][2] {0};

int main(){
    int N;
    cin >> N;

    DP[0][0] = 0;
    DP[0][1] = 1;

    for(int i = 1; i < N; i++){
        DP[i][0] = DP[i-1][0] + DP[i-1][1];
        DP[i][1] = DP[i-1][0];
    }
    cout << DP[N-1][0] + DP[N-1][1];
    return 0;
}
