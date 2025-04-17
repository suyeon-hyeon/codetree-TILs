#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

int n;
int num[20];
int sum;
int total_sum;
int min_diff;

void FindMinDiff(int cnt,int idx){
    if(cnt==n){
        int another_sum = total_sum-sum;
        min_diff=min(min_diff,abs(another_sum-sum));
        return;
    }

    for(int i=idx;i<2*n;i++){
        if(cnt==0&&i==n)
            break;
        sum+=num[i];
        FindMinDiff(cnt+1,i+1);
        sum-=num[i];
    }
}

int main() {
    cin >> n;

    total_sum=0;
    for (int i = 0; i < 2 * n; i++) {
        cin >> num[i];
        total_sum+=num[i];
    }

    sum=0;
    min_diff=INT_MAX;
    FindMinDiff(0,0);

    cout<<min_diff;
    return 0;
}
