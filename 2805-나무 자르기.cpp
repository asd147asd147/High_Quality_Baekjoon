#include <bits/stdc++.h>

using namespace std;

long long N, M;
vector<unsigned long long> trees;
long long ans = 0;

void bin_search(long long low, long long high){
    long long m = 0;
    long long mid = (low+high)/2;
    if(low > high) return;
    for(int i = 0; i < N; i++){
        long long gap = trees[i]-mid;
        if(gap > 0) m += gap;
    }
    if(m>=M){
        ans = mid;
        bin_search(mid+1,high);
    }
    else{
        bin_search(low,mid-1);
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        long long tmp;
        cin >> tmp;
        trees.push_back(tmp);
    }
    sort(trees.begin(), trees.end());
    bin_search(0,trees[N-1]);
    cout << ans;
	return 0;
}
