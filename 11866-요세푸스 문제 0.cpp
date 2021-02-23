#include <bits/stdc++.h>

using namespace std;

int main(){
    int N,K;
    cin >> N >> K;
    queue<int> q;
    for(int i = 1; i <= N; i++)
        q.push(i);

    cout << "<";
    int cnt = 0;
    vector<int> ans;
    while(!q.empty()){
        int f = q.front();
        cnt++;
        q.pop();
        if(cnt==K){
            ans.push_back(f);
            cnt = 0;
        }
        else q.push(f);
    }

    for(int i = 0; i < ans.size()-1; i++){
        cout << ans[i] <<", ";
    }
    cout << ans[ans.size()-1] << ">";

	return 0;
}
