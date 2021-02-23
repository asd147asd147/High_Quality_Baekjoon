#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool com(string s1, string s2){
    if(s1.size() != s2.size()){
        return s1.size() < s2.size();
    }
    return s1 < s2;
}

int main(){
    int N;
    vector<string> s;
    cin >> N;
    for(int i = 0; i < N; i++){
        string t;
        cin >> t;
        s.push_back(t);
    }
    sort(s.begin(), s.end(),com);
    cout << s[0] << "\n";
    for(int i = 1; i < N; i++){
        if(s[i] == s[i-1]) continue;
        cout << s[i] << "\n";
    }

	return 0;
}
