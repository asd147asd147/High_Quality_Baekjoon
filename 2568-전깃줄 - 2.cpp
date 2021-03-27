#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<pair<int,int>> vec;
    for(int i = 0; i < N; i++){
        int a,b;
        cin >> a >> b;
        vec.push_back({a,b});
    }
    sort(vec.begin(), vec.end());

    vector<int> LIS;
    vector<int> record;
    LIS.push_back(vec[1].second);
    for(int i = 0; i < N; i++){
        if(LIS.back() < vec[i].second){
            LIS.push_back(vec[i].second);
            record.push_back(LIS.size());
        }
        else{
            int idx = lower_bound(LIS.begin(),LIS.end(),vec[i].second)-LIS.begin();
            LIS[idx] = vec[i].second;
            record.push_back(idx+1);
        }
    }
    vector<int> ans;
    int max_idx = max_element(record.begin(), record.end()) - record.begin();
    int cnt = record[max_idx];
    for(int i = record.size()-1; i >= 0; i--){
        if(record[i] == cnt){
            cnt--;

        }
        else{
            ans.push_back(vec[i].first);
        }
    }

    cout << ans.size() << "\n";
    for(auto a = ans.rbegin(); a != ans.rend(); a++)
        cout << *a << "\n";


	return 0;
}
