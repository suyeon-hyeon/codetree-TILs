#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 10

int n;
bool visited_x[MAX_N+1];
bool visited_y[MAX_N+1];
int grid[MAX_N+1][MAX_N+1];
int max_result;

void Choose(int cur_num, int result) {
    if(cur_num == n+1) {
        max_result=max(max_result,result);
        return;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) {
            if(visited_x[i]||visited_y[j])
            continue;
            
            visited_x[i]=true;
            visited_y[j]=true;

            Choose(cur_num+1,result+grid[i][j]);

            visited_x[i]=false;
            visited_y[j]=false;
        }
    }

}

int main() {
    max_result=0;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>grid[i][j];
        }
    }
    Choose(1,0);
    cout<<max_result;
    return 0;
}
