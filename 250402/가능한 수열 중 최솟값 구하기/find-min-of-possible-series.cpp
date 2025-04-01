#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 80

int n;
int num[MAX_N];
bool stop;

bool IsPossible(int idx){
    for(int i=1;i<=(idx+1)/2;i++){
        bool flag=true;
        for(int j=0;j<i;j++){
            if(num[idx-j]!=num[idx-i-j]) {
                flag=false;
                break;
            }
        }
        if(flag)
            return false;
    }
    return true;
}

void FindMin(int cnt) {
    if(stop)
        return;
    
    if(cnt==n){
        stop=true;
        for(int i=0;i<n;i++)
            cout<<num[i];
        return;
    }

    for(int i=4;i<=6;i++){
        num[cnt]=i;
        if(!IsPossible(cnt))
            continue;
        FindMin(cnt+1);
    }

}


int main() {
    cin >> n;

    stop = false;

    FindMin(0);

    return 0;
}
