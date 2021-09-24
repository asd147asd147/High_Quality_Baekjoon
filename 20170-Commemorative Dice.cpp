#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N = 6;
	vector<int> p1(N, 0), p2(N, 0);

	for(int i = 0 ; i < N ; i++)
        cin >> p1[i];

    for(int i = 0 ; i < N ; i++)
        cin >> p2[i];

    int ans = 0;
    for(int i = 0;  i < N; i++){
        for(int j = 0; j < N; j++){
            if(p1[i] > p2[j]){
                ans++;
            }
        }
    }

    int parent = 36;

    while(1){
        int flag = 0;
        for(int i = 2; i <= ans; i++){
            if(ans % i == 0 && parent % i == 0){
                ans = ans / i;
                parent = parent / i;
                flag = 1;
            }
        }
        if(flag == 0) break;
    }
    cout << ans << "/" << parent;


	return 0;
}
