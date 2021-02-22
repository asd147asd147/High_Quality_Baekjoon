#include <iostream>
#include <queue>

using namespace std;

int main(){
    int N;
    cin >> N;
    queue<int> card;

    for(int i = 1; i <= N; ++i){
        card.push(i);
    }
    int last;
    while(1){
        last = card.front();
        card.pop();
        if(card.empty()) break;
        last = card.front();
        card.push(last);
        card.pop();
        if(card.empty()) break;
    }
    cout << last;
	return 0;
}
