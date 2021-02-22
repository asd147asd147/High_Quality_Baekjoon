#include <bits/stdc++.h>

using namespace std;

vector<tuple<long long,int,int>> NUM;

bool comp(tuple<long long,int,int> t1, tuple<long long,int,int> t2){
    return get<1>(t1) < get<1>(t2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        long long t;
        cin >> t;
        NUM.push_back(make_tuple(t,i,0));
    }
    sort(NUM.begin(),NUM.end());
    for(int i = 1; i < N; i++){
        if(get<0>(NUM[i]) == get<0>(NUM[i-1])){
            get<2>(NUM[i]) = get<2>(NUM[i-1]);
        }
        else{
            get<2>(NUM[i]) = get<2>(NUM[i-1])+1;
        }
    }
    sort(NUM.begin(),NUM.end(),comp);
    for(auto s : NUM)
        cout << get<2>(s) << " ";
	return 0;
}
