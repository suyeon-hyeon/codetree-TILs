#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

#define MAX_N 10

int n;
int num[MAX_N+1];

int min_val;

void FindMin(int cnt,int idx) {
    if(idx>=n){
        min_val=min(min_val,cnt);
        return;
    }

    int cur_val = num[idx];
    for(int i=1;i<=cur_val;i++) {
        FindMin(cnt+1, idx+i);
    }
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }

    min_val=INT_MAX;

    FindMin(0,1);

    if(min_val==INT_MAX)
        cout<<-1;
    else
        cout<<min_val;

    return 0;
}
