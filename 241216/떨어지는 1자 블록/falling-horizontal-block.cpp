#include <iostream>
#include <algorithm>

#define MAX_N 100

using namespace std;

int n, m, k;
int grid[MAX_N+1][MAX_N+1];

int main() {
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>grid[i][j];
    int max_row=1;
    for(int i=1;i<=n;i++) {
        bool isEmpty = true;
        for(int j=k;j<k+m;j++) {
            if(grid[i][j]==1) {
                isEmpty=false;
                break;
            }
        }
        if(!isEmpty)
            break;
        max_row=i;
    }

    for(int j=k;j<k+m;j++)
        grid[max_row][j]=1;


    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++)
            cout<<grid[i][j]<<" ";
        cout<<endl;
    }
}