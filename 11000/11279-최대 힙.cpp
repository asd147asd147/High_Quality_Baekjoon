#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    priority_queue<int,vector<int>,less<int>> heap;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
         int t;
         cin >> t;
         if(!t){
            if(heap.empty()) cout << 0 << "\n";
            else{
              cout << heap.top() << "\n";
              heap.pop();
            }
         }
         else{
            heap.push(t);
         }
    }

	return 0;
}
