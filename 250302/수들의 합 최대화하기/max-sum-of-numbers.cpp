#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 10

int n;
bool visited[MAX_N+1];
int grid[MAX_N+1][MAX_N+1];
int max_result;

void Choose(int row, int result) {
    if(row == n+1) {
        max_result=max(max_result,result);
        return;
    }

    for(int i=1;i<=n;i++){
        if(visited[i])
            continue;
            
        visited[i]=true;

        Choose(row+1,result+grid[row][i]);

        visited[i]=false;
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
