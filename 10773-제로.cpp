#include <bits/stdc++.h>

using namespace std;

int main(){
    int K;
    vector<int> num;
    cin >> K;
    for(int i = 0; i < K; i++){
        int tmp;
        cin >> tmp;
        if(!tmp) num.pop_back();
        else num.push_back(tmp);
    }
    cout << accumulate(num.begin(),num.end(),0);
	return 0;
}
