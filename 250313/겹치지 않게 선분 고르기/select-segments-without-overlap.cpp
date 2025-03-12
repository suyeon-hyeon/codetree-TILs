#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_N 15

struct Line {
    int start, end;
};

int n;
vector<Line> lines;
int ans;

void Choose(int cur_num, int last_index, int sum){
    if(cur_num==n) {
        ans=max(ans,sum);
        return;
    }

    int idx=last_index;
    for(int i=0;i<n;i++){
        if(idx<lines[i].start) {
            idx=lines[i].end;
            Choose(cur_num+1,idx,sum+1);
        }
        else
            Choose(cur_num+1,idx,sum);
    }
}

bool compare(const Line &a, const Line &b){
    return a.start<b.start;
}

int main() {
    ans = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int start, end;
        cin>>start>>end;
        lines.push_back({start,end});
    }

    sort(lines.begin(),lines.end(),compare);
    Choose(0,0,0);

    cout<<ans;
}
