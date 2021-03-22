#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<long long>> vec;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++){
        vector<long long> v;
        for(int j = 0; j < 4; j++){
            long long num;
            cin >> num;
            v.push_back(num);
        }
        vec.push_back(v);
    }

    vector<long long> sum;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            sum.push_back(vec[i][2] + vec[j][3]);
        }
    }

    sort(sum.begin(),sum.end());
    long long ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            long long h = vec[i][0] + vec[j][1];
            long long low = lower_bound(sum.begin(),sum.end(),-h) - sum.begin();
            long long high = upper_bound(sum.begin(),sum.end(),-h) - sum.begin();
            if(-h == sum[low]) ans += (high-low);
        }
    }
    cout << ans;

	return 0;
}
