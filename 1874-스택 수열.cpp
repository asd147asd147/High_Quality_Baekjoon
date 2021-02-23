#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
    int N;
    int num[100001] = {0,};
    stack<int> s;
    vector<char> ans;
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> num[i];
    }
    int i=1, j=1;
    while(1){
        if(i<=num[j]){
            s.push(i), ans.push_back('+');
            if(i < N) i++;
        }
        if(s.top()==num[j]){
            s.pop(), ans.push_back('-'), j++;
            if(j > N) break;
        }
        if(!s.empty() && s.top()>num[j]){
            cout << "NO";
            return 0;
        }
    }

    for(auto a : ans)
        cout << a << "\n";

	return 0;
}
