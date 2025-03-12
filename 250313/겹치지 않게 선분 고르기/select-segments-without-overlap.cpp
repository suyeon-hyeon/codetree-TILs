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

void Choose(int index, int last_end, int count){
    if(index==n) {
        ans=max(ans,count);
        return;
    }

    if (lines[index].start > last_end) {
        Choose(index + 1, lines[index].end, count + 1);
    }
    
    Choose(index + 1, last_end, count);
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
    Choose(0,-1,0);

    cout<<ans;
}
