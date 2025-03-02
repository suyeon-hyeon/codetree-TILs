#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> answer;

void PrintAnswer() {
    for(int i:answer)
        cout<<i<<" ";
    cout<<endl;
}

void Choose(int start, int cnt) {
    if(cnt == m) {
        PrintAnswer();
        return;
    }

    for(int select=start;select<=n;select++){
        answer.push_back(select);
        Choose(select+1, cnt+1);
        answer.pop_back();
    }

}

int main() {
    cin >> n >> m;

    Choose(1,0);
    return 0;
}
