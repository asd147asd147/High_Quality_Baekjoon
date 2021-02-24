#include <bits/stdc++.h>

using namespace std;

void solve(){
    string p;
    int n;
    deque<int> vec;
    string num;
    cin >> p;
    cin >> n;
    cin >> num;
    int temp = 0;
    for(int i = 1; i < num.size()-1; i++){
        if('0' <= num[i] && num[i] <= '9'){
            temp *= 10;
            temp += num[i] - '0';
        }
        else if(num[i] == ','){
            vec.push_back(temp);
            temp = 0;
        }
    }
    if(num.size()>2){
        vec.push_back(temp);
    }
    bool r_toggle = 0;
    for(int i = 0; i < p.size(); i++){
        if(p[i] == 'R'){
            r_toggle = !r_toggle;
        }
        else{
            if(!r_toggle){
                if(!vec.empty()){
                    vec.pop_front();
                }
                else{
                    cout << "error\n";
                    return;
                }
            }
            else{
                if(!vec.empty()){
                    vec.pop_back();
                }
                else{
                    cout << "error\n";
                    return;
                }
            }
        }
    }
    if(r_toggle) reverse(vec.begin(),vec.end());

    cout << "[";
    if(!vec.empty()){
        for(int i = 0; i < vec.size()-1; i++){
            cout << vec[i] << ",";
        }
        cout << vec[vec.size()-1]<<"]\n";
    }
    else cout << "]\n";
}

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }

	return 0;
}
