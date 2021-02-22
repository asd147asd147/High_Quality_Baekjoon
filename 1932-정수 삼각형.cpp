#include <iostream>
#include <algorithm>

using namespace std;

long long DP[100001] {0};

int main(){
    int N;
    cin >> N;

    long long temp;
    long long ans;
    cin >> temp;
    DP[0] = temp;
    ans = DP[0];

    for(int i = 1; i < N; i++){
        cin >> temp;
        DP[i] = max(DP[i-1]+temp,temp);
        ans = max(ans,DP[i]);
    }
    cout << ans;

    return 0;
}
