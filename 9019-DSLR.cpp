#include <bits/stdc++.h>

using namespace std;

deque<char> R(deque<char> d){
    int num = d.back();
    if(num == 0) return d;
    d.push_front(num);
    d.pop_back();
    return d;
}

deque<char> L(deque<char> d){
    d.push_back(d.front());
    d.pop_front();
    while(d.size() > 1 && d.front() == 0){
        d.pop_front();
    }
    return d;
}

deque<char> S(deque<char> d){
    int num = 0;
    while(!d.empty()){
        num *= 10;
        num += d.front();
        d.pop_front();
    }
    num -= 1;
    if(num == -1){
        for(int i = 0; i < 4; i++)
            d.push_front(9);
        return d;
    }
    if(num == 0){
        d.push_front(0);
        return d;
    }
    while(num > 0){
        d.push_front(num%10);
        num /= 10;
    }
    return d;
}

deque<char> D(deque<char> d){
    int num = 0;
    while(!d.empty()){
        num *= 10;
        num += d.front();
        d.pop_front();
    }
    num *= 2;
    num %= 10000;
    if(!num){
        d.push_front(0);
        return d;
    }
    while(num > 0){
        d.push_front(num%10);
        num /= 10;
    }
    return d;
}

void answer(int ans){
    string cmd[4] = {"D","S","L","R"};
    string s = "";
    while(ans > 0){
        s += cmd[ans%10-1];
        ans/=10;
    }
    for(int i = s.size()-1; i >= 0; i--){
        cout << s[i];
    }
    cout <<"\n";
}

void solve(){
    deque<char> a,b;
    set<deque<char>> check;
    deque<char> (*f[4])(deque<char>) = {D,S,L,R};
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        a.push_back(s[i]-'0');
    }
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        b.push_back(s[i]-'0');
    }
    queue<pair<deque<char>,int>> bfs;
    for(int i = 0; i < 4; i++){
        bfs.push(make_pair(f[i](a),i+1));
    }
    while(!bfs.empty()){
        pair<deque<char>,int> temp = bfs.front();
        bfs.pop();
        if(temp.first == b){
            answer(temp.second);
            return;
        }
        for(int i = 0; i < 4; i++){
            bfs.push(make_pair(f[i](temp.first),temp.second*10+i+1));
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
	return 0;
}
