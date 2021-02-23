#include <bits/stdc++.h>

using namespace std;

bool com(pair<int,string> r1, pair<int,string> r2){
    if(r1.first == r2.first) return 0;
    return r1.first < r2.first;
}

int main(){
    int N;
    cin >> N;

    vector<pair<int,string>> reg;
    for(int i = 0; i < N; i++){
        int age;
        string name;
        cin >> age >> name;
        reg.push_back(make_pair(age,name));
    }
    stable_sort(reg.begin(),reg.end(),com);
    for(int i = 0; i < N; i++){
        cout << reg[i].first << " " << reg[i].second << "\n";
    }

	return 0;
}
