#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> height;

long long divide_conquer(int left, int right){
    if(left == right) return height[left];
    int mid = (left + right) / 2;
    long long l_size = divide_conquer(left, mid);
    long long r_size = divide_conquer(mid+1, right);
    int to_l, to_r;
    to_l = to_r = mid;
    int mid_h = height[mid];
    long long m_size = 0;
    while(left < to_l && to_r < right){
        if(height[to_l - 1] < height[to_r + 1]){
            to_r++;
            mid_h = min(mid_h, height[to_r]);
        }
        else{
            to_l--;
            mid_h = min(mid_h, height[to_l]);
        }
        m_size = max(m_size, (long long)mid_h * (long long)(to_r - to_l + 1));
    }

    while(to_r < right){
        to_r++;
        mid_h = min(mid_h, height[to_r]);
        m_size = max(m_size, (long long)mid_h * (long long)(to_r - to_l + 1));
    }
    while(left < to_l){
        to_l--;
        mid_h = min(mid_h, height[to_l]);
        m_size = max(m_size, (long long)mid_h * (long long)(to_r - to_l + 1));
    }
    return max({m_size, l_size, r_size});
}

void solve(){
    cout << divide_conquer(0,N-1) << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while(1){
        cin >> N;
        if(N == 0) return 0;
        height.resize(N);
        for(int i = 0; i < N; i++){
            cin >> height[i];
        }
        solve();
	}


	return 0;
}
