#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <vector>

using namespace std;

int n, m;
int x[20], y[20];
int min_diff;
vector<int> selected;

int FindMaxDist() {
    int max_dist = 0;
    for(int i=0;i<selected.size()-1;i++){
        for(int j=i;j<selected.size();j++){
            int dx = x[selected[i]] - x[selected[j]];
            int dy = y[selected[i]] - y[selected[j]];
            max_dist=max(max_dist,dx * dx + dy * dy);
        }
    }
    return max_dist;
}

void FindMinDiff(int cnt, int idx) {
    if(cnt==m){
        min_diff=min(min_diff,FindMaxDist());
        return;
    }
    for(int i=idx;i<n;i++){
        selected.push_back(i);
        FindMinDiff(cnt+1,i+1);
        selected.pop_back();
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    min_diff=INT_MAX;

    FindMinDiff(0,0);

    cout<<min_diff;

    return 0;
}
