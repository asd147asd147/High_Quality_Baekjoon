#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    getline(cin,s);
    while(s[0] != '.' && s.size()!=1){
        stack<char> b;
        int i;
        for(i = 0; i < s.size(); i++){
            if(s[i]=='[' || s[i]=='(' || s[i]=='{'){
                b.push(s[i]);
            }
            else if(s[i]==']'){
                if(!b.empty()){
                    if(b.top()=='[') b.pop();
                    else{
                        break;
                    }
                }
                else{
                    break;
                }
            }
            else if(s[i]==')'){
                if(!b.empty()){
                    if(b.top()=='(') b.pop();
                    else{
                        break;
                    }
                }
                else{
                    break;
                }
            }
        }
        if(i == s.size() && b.empty()){
            cout << "yes\n";
        }
        else{
            cout << "no\n";
        }
        getline(cin,s);
    }
	return 0;
}
