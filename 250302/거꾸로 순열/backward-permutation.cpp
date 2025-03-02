#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 8

int n;
bool visited[MAX_N+1];
vector<int> answer;

void PrintAnswer() {
    for(int i:answer)
        cout<<i<<" ";
    cout<<endl;
}

void Choose(int cur_num) {
    if(cur_num == 0) {
        PrintAnswer();
        return;
    }

    for(int i=n;i>=1;i--){
        if(visited[i])
            continue;
        
        visited[i]=true;
        answer.push_back(i);

        Choose(cur_num-1);

        answer.pop_back();
        visited[i]=false;
    }

}

int main() {
    cin >> n;

    Choose(n);
    return 0;
}
