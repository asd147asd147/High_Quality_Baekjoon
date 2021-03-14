#include <bits/stdc++.h>

using namespace std;

int N, M;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    set<char> remind;
    vector<set<char>> word;
    for(char a = 'a'; a <= 'z'; a++)
        remind.insert(a);

    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        set<char> tmp;
        for(int j = 0; j < s.size(); j++){
            tmp.insert(s[j]);
        }
        word.push_back(tmp);
    }
    for(int i = 0; i < M; i++){
        int o;
        char x;
        cin >> o >> x;
        if(o == 1){
            remind.erase(x);
        }
        else{
            remind.insert(x);
        }

        if(remind.size() == 26){
            cout << word.size() << "\n";
        }
        else{
            int cnt = 0;
            for(int j = 0; j < word.size(); j++){
                set<char> tmp;
                set_difference(word[j].begin(),word[j].end(),
                               remind.begin(),remind.end(),
                               inserter(tmp,tmp.begin()));
                if(tmp.empty()) cnt++;
            }
            cout << cnt << "\n";
        }
    }

	return 0;
}
