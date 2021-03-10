#include <bits/stdc++.h>

using namespace std;

long long A,B;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> A >> B;

	queue<long long> q;
	q.push(A);
	int size = q.size();
	long long cnt = 0, ans = 0;
	while(!q.empty()){
        long long cur = q.front();
        q.pop();
        if(cur == B){
            cout << ans + 1;
            return 0;
        }
        if(cur*2 <= B){
            q.push(cur*2);
        }
        if(cur*10+1 <= B){
            q.push(cur*10+1);
        }

        cnt++;
        if(cnt == size){
            cnt = 0;
            ans++;
            size = q.size();
        }
	};

	cout << -1;
	return 0;
}
