#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

bool com(pair<int,int> p1, pair<int,int> p2){
    if(p1.second == p2.second) return p1.first < p2.first;
    return p1.second < p2.second;
}

int main(){
    int N;
    pair<int,int> meet[100001];
    cin >> N;

    for(int i = 0; i < N; i++){
        int start, end;
        cin >> start >> end;
        meet[i] = make_pair(start,end);
    }

    sort(meet, meet+N, com);

    int ans = 0;
    int time = -1;
    for(int i = 0; i < N; i++){
        if(meet[i].first >= time){
            ans++;
            time = meet[i].second;
        }
    }
    cout << ans;

	return 0;
}
