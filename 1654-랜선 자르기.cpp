#include <bits/stdc++.h>

using namespace std;

long long K, N;
vector<long long> LAN;
unsigned long long ans = 0;

void bin_search(long long min, long long max){
    if(min > max) return;
    long long mid = (min+max)/2;
    unsigned long long n = 0;
    for(int i = 0; i < K; i++){
        n += LAN[i]/mid;
    }
    if(n >= N){
        ans = mid;
        bin_search(mid+1,max);
    }
    else{
        bin_search(min,mid-1);
    }
}

int main(){
    cin >> K >> N;
    for(int i = 0; i < K; i++){
        long long lan;
        cin >> lan;
        LAN.push_back(lan);
    }
    sort(LAN.begin(), LAN.end());
    bin_search(1,LAN[K-1]);
    cout << ans;
	return 0;
}
