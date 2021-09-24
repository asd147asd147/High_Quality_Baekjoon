#include <bits/stdc++.h>

using namespace std;

vector<int> step;
int DDR[5][5];
int dp[100001][5][5];

int solve(int idx, int l, int r){
    cout << idx << endl;
    if(idx == step.size()){
        return 0;
    }
    if(dp[idx][l][r]) return dp[idx][l][r];
    return dp[idx][l][r] = min(solve(idx+1,step[idx],r)+DDR[l][step[idx]],solve(idx+1,l,step[idx])+DDR[r][step[idx]]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for(int i = 0; i < 5; i++){
        DDR[0][i] = 2;
        DDR[i][i] = 1;
	}
	DDR[1][3] = DDR[3][1] = 4;
	DDR[2][4] = DDR[4][2] = 4;
	DDR[1][2] = DDR[1][4] = 3;
	DDR[2][1] = DDR[2][3] = 3;
	DDR[3][2] = DDR[3][4] = 3;
	DDR[4][3] = DDR[4][1] = 3;

	while(1){
        int temp;
        cin >> temp;
        if(!temp) break;
        step.push_back(temp);
	}

    cout << solve(0,0,0);


	return 0;
}
