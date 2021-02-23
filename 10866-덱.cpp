#include <bits/stdc++.h>

using namespace std;

int main(){
    deque<int> dq;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        int n;
        if(s=="push_back"){
            cin >> n;
            dq.push_back(n);
        }
        else if(s=="push_front"){
            cin >> n;
            dq.push_front(n);
        }
        else if(s=="pop_front"){
            if(dq.empty()){
                cout << -1 << endl;
            }
            else{
                cout << dq.front() << endl;
                dq.pop_front();
            }
        }
        else if(s=="pop_back"){
            if(dq.empty()){
                cout << -1 << endl;
            }
            else{
                cout << dq.back() << endl;
                dq.pop_back();
            }
        }
        else if(s=="size"){
            cout << dq.size() << endl;
        }
        else if(s=="empty"){
            if(dq.empty()) cout << 1 << endl;
            else cout << 0 << endl;
        }
        else if(s=="front"){
            if(dq.empty()){
                cout << -1 << endl;
            }
            else{
                cout << dq.front() << endl;
            }
        }
        else if(s=="back"){
            if(dq.empty()){
                cout << -1 << endl;
            }
            else{
                cout << dq.back() << endl;
            }
        }
    }

	return 0;
}
