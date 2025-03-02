#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int k, n;
vector<int> answer;

void PrintAnswer() {
    for(int i:answer)
        cout<<i<<" ";
    cout<<endl;
}

void Choose(int cur_num) {
    if(cur_num == n+1) {
        PrintAnswer();
        return;
    }

    for(int select=1;select<=k;select++){
        if(cur_num>=3 && select==answer[cur_num-2] && select==answer[cur_num-3])
            continue;
        answer.push_back(select);
        Choose(cur_num+1);
        answer.pop_back();
    }

}

int main() {
    cin >> k >> n;

    Choose(1);
    return 0;
}
