#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    vector<int> squares(N+1,0);
    squares[1] = 1;
    for(int i = 2; i <= N; i++){
        int minn = INT_MAX;
        for(int j = 1; j*j <= i; j++){
            int tmp = i - j*j;
            minn = min(minn, squares[tmp]);
        }
        squares[i] = minn + 1;
    }
    cout << squares[N];

	return 0;
}
