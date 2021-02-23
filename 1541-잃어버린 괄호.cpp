#include <iostream>
#include <string>
#include <vector>
#define INF 999999

using namespace std;

int main(){
    vector<int> num;
    vector<char> op;
    string s;
    cin >> s;
    int n=0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '-' || s[i] == '+') op.push_back(s[i]), num.push_back(n), n = 0;
        else{
            n *= 10;
            n += s[i] - '0';
        }
    }
    num.push_back(n);
    int dp[num.size()][num.size()];
    for(int i = 0; i < num.size(); i++)
        for(int j = 0; j < num.size(); j++)
            dp[i][j] = INF;

    for(int i = 0; i < num.size(); i++)
        dp[i][i] = num[i];

    for(int i = 1; i < num.size(); i++){
        for(int j = 0; j < num.size()-i; j++){
            for(int k = 0; k < i; k++){
                int o = 1;
                if(op[j] == '-') o = -1;
                dp[j][i+j] = min(dp[j][i+j], dp[j][j+k]+(o*dp[j+k+1][i+j]));
            }
        }
    }
    cout << dp[0][num.size()-1];

	return 0;
}
