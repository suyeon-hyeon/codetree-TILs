#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_N 20

int n, m;
vector<int> grid[MAX_N+1][MAX_N+1];
int dir_num = 8;
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
bool is_done;

void move(int move_num) {
    bool findNum=false; // 숫자 발견 
    int cur_x=-1;
    int cur_y=-1;
    vector<int> vals;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(grid[i][j].empty())
                continue;
            
            auto it = grid[i][j].begin();
            while (it != grid[i][j].end()) {
                if (*it == move_num) {
                    findNum = true;
                    cur_x = i;
                    cur_y = j;
                }
                if (findNum) {
                    vals.push_back(*it);
                    it = grid[i][j].erase(it);
                } else {
                    it++;
                }
            }

            if(findNum)
                break;
        }
        if(findNum)
            break;
    }

    bool canGo = false;
    int max=0;
    int max_x=-1;
    int max_y=-1;
    for(int dir=0;dir<dir_num;dir++) {
        int nx = cur_x+dx[dir];
        int ny = cur_y+dy[dir];
        if(nx<1||nx>n||ny<1||ny>n||grid[nx][ny].empty())
            continue;
        canGo=true;
        for(int num:grid[nx][ny]) {
            if(num>max) {
                max=num;
                max_x=nx;
                max_y=ny;
            }
        }
    }

    if(!canGo) {
        for(int num:vals) {
            grid[cur_x][cur_y].push_back(num);
        }
        is_done=true;
        return;
    }

    for(int num:vals) {
        grid[max_x][max_y].push_back(num);
    }
}

int main() {
    is_done=false;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int input;
            cin >> input;
            grid[i][j].push_back(input);
        }
    }

    for (int i = 0; i < m; i++) {
        if(is_done)
            break;
        int move_num;
        cin >> move_num;
        move(move_num);
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(grid[i][j].empty()) {
                cout<<"None";
            } else {
                for (auto it = grid[i][j].rbegin(); it != grid[i][j].rend(); it++) {
                cout << *it << " ";
                }
            }
            cout<<endl;
        }
    }
}
