#include <bits/stdc++.h>

using namespace std;

int N, M;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    bitset<26> remind;
    vector<bitset<26>> word;
    remind.set();
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        bitset<26> tmp;
        for(int j = 0; j < s.size(); j++){
            tmp.set(s[j]-'a',true);
        }
        word.push_back(tmp);
    }
    for(int i = 0; i < M; i++){
        int o;
        char x;
        cin >> o >> x;
        if(o == 1){
            remind.set(x-'a',false);
        }
        else{
            remind.set(x-'a',true);
        }

        if(remind.all()){
            cout << word.size() << "\n";
        }
        else{
            int cnt = 0;
            for(int j = 0; j < word.size(); j++){
                if((word[j] & remind) == word[j]) cnt++;
            }
            cout << cnt << "\n";
        }
    }

	return 0;
}
