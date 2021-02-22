#include <bits/stdc++.h>

using namespace std;

int N,M,B;
int min_time = 200000000, ans = 0;
int low=257, high=0;
int land[501][501];

void flat(int H){
    int over = 0, under = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(land[i][j] > H) over += land[i][j] - H;
            else if(H > land[i][j]) under += H - land[i][j];
        }
    }
    if(under > B+over) return;

    int cur_time;
    if(over == 0) cur_time = under;
    else cur_time = under+over*2;

    if(min_time > cur_time){
        min_time = cur_time;
        ans = H;
    }
    else if(min_time == cur_time){
        if(H > ans) ans = H;
    }
}

int main(){
    cin >> N >> M >> B;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> land[i][j];
            low = min(low,land[i][j]);
            high = max(high,land[i][j]);
        }
    }
    for(int i = low; i <= high; i++){
        flat(i);
    }
    cout << min_time << " " << ans;
	return 0;
}
