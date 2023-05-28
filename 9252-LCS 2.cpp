#include <bits/stdc++.h>

using namespace std;

string s1, s2;
int dp[1001][1001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> s1 >> s2;
    for(int i = 0; i <= s1.size(); i++){
        dp[i][0] = 0;
    }
    for(int i = 0; i <= s2.size(); i++){
        dp[0][i] = 0;
    }

    for(int i = 1; i <= s1.size(); i++){
        for(int j = 1; j <= s2.size(); j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }


    if(dp[s1.size()][s2.size()] == 0){
        cout << 0;
        return 0;
    }

    string ans = "";
    int i = s1.size();
    int j = s2.size();
    while(ans.length() != dp[s1.size()][s2.size()]){
        if(s1[i-1] == s2[j-1]){
            ans += s1[i-1];
            i--;
            j--;
        }
        else{
            if(dp[i-1][j] == dp[i][j]){
                i--;
            }
            else{
                j--;
            }
        }
    }

    reverse(ans.begin(), ans.end());
    cout << dp[s1.size()][s2.size()] << "\n" << ans;

	return 0;
}
