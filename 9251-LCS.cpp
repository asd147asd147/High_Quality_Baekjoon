#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main(){
    string s1, s2;

    cin >> s1 >> s2;

    int dp[s1.size()+1][s2.size()+1];

    memset(dp,0,sizeof(dp));

    for(int i = 0; i < s1.size(); i++){
        for(int j = 0; j < s2.size(); j++){
            if(s2[j] == s1[i]){
                dp[i+1][j+1] = dp[i][j] + 1;
            }
            else{
                dp[i+1][j+1] = max({dp[i][j+1],dp[i+1][j],dp[i][j]});
            }
        }
    }
    cout << dp[s1.size()][s2.size()];

    return 0;
}
