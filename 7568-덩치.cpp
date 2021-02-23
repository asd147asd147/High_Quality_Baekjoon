#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<pair<int, int>> person;
    for(int i = 0; i < N; i++){
        int w,h;
        cin >> w >> h;
        person.push_back(make_pair(w,h));
    }

    for(int i = 0; i < N; i++){
        int cnt = 1;
        for(int j = 0; j < N; j++){
            if(person[i].first < person[j].first && person[i].second < person[j].second) cnt++;
        }
        cout << cnt << " ";
    }

	return 0;
}
