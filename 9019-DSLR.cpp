#include <bits/stdc++.h>

using namespace std;


inline int D(int num){
    num = (num*2)%10000;
    return num;
}
inline int S(int num){
    num = num-1 >= 0 ? num-1 : 9999;
    return num;
}
inline int L(int num){
    num *= 10;
    num += (num%100000) / 10000;
    num %= 10000;
    return num;
}
inline int R(int num){
    num += (num%10)*10000;
    num /= 10;
    return num;
}


void solve(){
    int src, des;
    bool mem[10000] = {0,};
    string c[4] = {"D","S","L","R"};
    cin >> src >> des;
    queue<pair<int,string>> bfs;
    memset(mem,0,10000);
    mem[src] = 1;
    int (*DSLR[4])(int) = {D,S,L,R};
    for(int i = 0; i < 4; i++){
        int num = DSLR[i](src);
        if(mem[num]) continue;
        mem[num] = 1;
        bfs.push(make_pair(num,c[i]));
    }
    while(!bfs.empty()){
        pair<int, string> p = bfs.front();
        bfs.pop();
        if(p.first == des){
            cout << p.second << "\n";
            return;
        }
        for(int i = 0; i < 4; i++){
            int num = DSLR[i](p.first);
            if(mem[num]) continue;
            mem[num] = 1;
            bfs.push(make_pair(num,p.second+c[i]));
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
