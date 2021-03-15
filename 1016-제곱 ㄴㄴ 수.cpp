#include <bits/stdc++.h>

using namespace std;
long long m,M;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> m >> M;
	long long ans = M-m+1;
	array<bool,1000001> check;
	check.fill(0);
	long long i = 2;
	while(i * i <= M){
        long long j = m/(i*i);
        if(m % (i*i) != 0) j++;
        while(i*i*j <= M){
            if(!check[i*i*j-m]){
                check[i*i*j-m] = true;
                ans--;
            }
            j++;
        }
        i++;
	}
	cout << ans;

	return 0;
}
