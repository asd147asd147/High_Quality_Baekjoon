#include <bits/stdc++.h>

using namespace std;

typedef struct _point{
    double x, y;
} Point;

vector<Point> P_set;
int N;
double ans;

void matching(int idx, pair<double,double> sum, int select_num){
    if(idx == N && select_num == N/2){
        ans = min(ans, sqrt(pow(sum.first,2) + pow(sum.second,2)));
        return;
    }
    else if(idx == N && select_num != N/2) return;
    matching(idx+1, {sum.first+P_set[idx].x, sum.second+P_set[idx].y}, select_num+1);
    matching(idx+1, {sum.first-P_set[idx].x, sum.second-P_set[idx].y}, select_num);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while(T--){
        cin >> N;
        ans = 99999999;
        P_set.resize(N);
        for(int i = 0; i < N; i++){
            cin >> P_set[i].x >> P_set[i].y;
        }
        matching(0,{0.0,0.0},0);
        cout << fixed;
        cout.precision(12);
        cout << ans << "\n";
	}

	return 0;
}
