#include <bits/stdc++.h>

using namespace std;

string e;
map<char,int> prio = {{'*',1}, {'/',1}, {'+',0}, {'-',0}};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> e;
    stack<char> op;
    for(int i = 0; i < e.size(); i++){
        if('A' <= e[i] && e[i] <= 'Z'){
            cout << e[i];
        }
        else{
            if(e[i] == '('){
                op.push(e[i]);
            }
            else if(e[i] == ')'){
                while(!op.empty() && op.top() != '('){
                    cout << op.top();
                    op.pop();
                }
                op.pop();
            }
            else if (e[i] == '*' || e[i] == '/'){
                while (!op.empty() && (op.top() == '*' || op.top() == '/')){
                    cout << op.top();
                    op.pop();
                }
                op.push(e[i]);
            }
            else if (e[i] == '+' || e[i] == '-'){
                while (!op.empty() && op.top() != '(')
                {
                    cout << op.top();
                    op.pop();
                }
                op.push(e[i]);
            }
        }
    }
    while(!op.empty()){
        cout << op.top();
        op.pop();
    }
	return 0;
}
