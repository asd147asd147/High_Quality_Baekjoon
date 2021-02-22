#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N,M;
    cin >> N >> M;
    vector<string> s1,s2,diff_s;
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        s1.push_back(s);
    }
    for(int i = 0; i < M; i++){
        string s;
        cin >> s;
        s2.push_back(s);
    }
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());

    diff_s.clear();
    diff_s.resize(s1.size()+s2.size());
    auto iter = set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),diff_s.begin());
    diff_s.erase(iter,diff_s.end());
    cout << diff_s.size() << "\n";
    for(auto s : diff_s)
        cout << s << "\n";

	return 0;
}
