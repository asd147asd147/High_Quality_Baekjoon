#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;

	int tri[N+1] = {0,};
	tri[4] = 1;

	for(int i = 5; i <= N; i++){
        tri[i] = tri[(i+1)/2] + 2;
	}
	cout << tri[N];

	return 0;
}
