#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    queue<pair<int,int>> stay;
    for(int i = 0; i < priorities.size(); i++){
        if(i == location){
            stay.push(make_pair(priorities[i],i));
        }
        else{
            stay.push(make_pair(priorities[i],i));
        }
    }


    pair<int, int> print;
    int flag = 0;
    while(1){
        print = stay.front();
        stay.pop();
        int q_size = stay.size();

        for(int i = 0; i < q_size; i++){
            if(stay.front().first > print.first){
                flag = 1;
            }
            stay.push(stay.front());
            stay.pop();
        }

        if(flag == 1){
            stay.push(print);
            flag = 0;
        }
        else{
            answer++;
            if(print.second == location){
                break;
            }
        }
    }

    return answer;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int N,M;
        cin >> N >> M;
        vector<int> vec;
        for(int i = 0; i < N; i++){
            int t;
            cin >> t;
            vec.push_back(t);
        }
        cout << solution(vec,M) << "\n";
    }
    return 0;
}
