#include <bits/stdc++.h>

using namespace std;

int N,M;
vector<pair<int,int>> vec;
int dp[1010][1010];

int calc(int x1, int y1, int x2, int y2){
    return abs(x1 - x2) + abs(y1 - y2);
}

int minDist(int A, int B){
    if(A == M || B == M) return 0;
    if(dp[A][B] != -1) return dp[A][B];

    dp[A][B] = 987654321;
    int next = max(A,B) + 1; 
    int distA, distB;
    if(A == 0){
        distA = calc(1,1, vec[next].first, vec[next].second);
    }
    else{
        distA = calc(vec[next].first, vec[next].second, vec[A].first, vec[A].second);
    }
    if(B == 0){
        distB = calc(N,N, vec[next].first, vec[next].second);
    }
    else{
        distB = calc(vec[next].first, vec[next].second, vec[B].first, vec[B].second);
    }
    int ret1, ret2;
    ret1 = minDist(next,B)+distA;
    ret2 = minDist(A,next)+distB;

    return dp[A][B] = min(ret1, ret2);
}

void findNum(int A, int B){
    if(A == M || B == M) return;

    int next = max(A,B) + 1;
    int distA, distB;
    if(A == 0){
        distA = calc(1,1, vec[next].first, vec[next].second);
    }
    else{
        distA = calc(vec[next].first, vec[next].second, vec[A].first, vec[A].second);
    }
    if(B == 0){
        distB = calc(N,N, vec[next].first, vec[next].second);
    }
    else{
        distB = calc(vec[next].first, vec[next].second, vec[B].first, vec[B].second);
    }

    int ret1, ret2;
    ret1 = minDist(next,B) + distA;
    ret2 = minDist(A,next) + distB;

    if(ret1 < ret2){
        cout << "1\n";
        findNum(next,B);
    }
    else{
        cout << "2\n";
        findNum(A,next);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    memset(dp, -1, sizeof(dp));
    vec.resize(M+1);
    for(int i = 1; i <= M; i++){
        cin >> vec[i].first >> vec[i].second;
    }
    cout << minDist(0,0) << "\n";
    findNum(0,0);
    return 0;
}

