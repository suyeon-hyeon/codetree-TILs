#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> answer;
int max_result;

void Choose(int start, int cnt, int result) {
    if(cnt == m) {
        max_result=max(max_result,result);
        return;
    }

    for(int select=start;select<=n;select++){
        answer.push_back(select);
        Choose(select+1, cnt+1, result^select);
        answer.pop_back();
    }

}

int main() {
    cin >> n >> m;
    max_result=0;
    Choose(1,0,0);
    cout<<max_result;
    return 0;
}
