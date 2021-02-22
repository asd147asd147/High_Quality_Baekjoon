#include <bits/stdc++.h>

using namespace std;
vector<pair<int,int>> yx;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int x,y;
        cin >> x >> y;
        yx.push_back(make_pair(y,x));
    }
    sort(yx.begin(),yx.end());
    for(auto s : yx)
        cout << s.second << " " << s.first << "\n";
	return 0;
}
