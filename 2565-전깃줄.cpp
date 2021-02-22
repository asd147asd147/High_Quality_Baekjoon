#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main(){
    int N;
    int a,b;
    vector<pair<int,int>> line;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        line.push_back(make_pair(a,b));
    }
    sort(line.begin(),line.end());
    int dp[N];
    for(int i = 0; i < N; i++)
        dp[i] = 0;

    dp[0] = 1;
    for(int i = 1; i < N; i++){
        int max = -1;
        for(int j = 0; j < i; j++){
            if(line[j].second < line[i].second && dp[j] > dp[max]){
                max = j;
            }
        }
        if(max == -1) dp[i] = 1;
        else dp[i] = dp[max]+1;
    }

    cout << N - *max_element(dp,dp+N);


	return 0;
}
