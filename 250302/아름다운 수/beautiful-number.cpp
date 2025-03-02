#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define SELECT 4

int n;
vector<int> v;
int answer;

void BeautifulNum(int cur_num){
    if(cur_num==n) {
        if(v[cur_num-1]!=1) {
            int continus_num=1;
            for(int i=cur_num-2;i>=0;i--) {
                if(v[i]!=v[cur_num-1])
                    break;
                continus_num++;
            }
            if(continus_num%v[cur_num-1]!=0)
                return;
        }
        answer++;
        return;
    }
    
    for(int select=1;select<=SELECT;select++){
        if(cur_num!=0&&v[cur_num-1]!=1&&select!=v[cur_num-1]) {
            int continus_num=1;
            for(int i=cur_num-2;i>=0;i--) {
                if(v[i]!=v[cur_num-1])
                    break;
                continus_num++;
            }
            if(continus_num%v[cur_num-1]!=0)
                continue;
        }
        v.push_back(select);
        BeautifulNum(cur_num+1);
        v.pop_back();
    }
}

int main() {
    cin >> n;
    answer=0;
    BeautifulNum(0);
    cout<<answer;
    return 0;
}
