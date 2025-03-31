#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

string expression;

int max_val;
int alpha[6];

int GetResult() {
    int result=alpha[expression[0]-'a'];

    for(int i=2;i<expression.size();i+=2){
        int cur_val = alpha[expression[i]-'a'];
        if(expression[i-1]=='+')
            result+=cur_val;
        else if(expression[i-1]=='-')
            result-=cur_val;
        else
            result*=cur_val;
    }
    
    return result;
}

void FindMax(int cnt) {
    if(cnt==6){
        max_val=max(max_val,GetResult());
        return;
    }

    for(int i=1;i<=4;i++) {
        alpha[cnt]=i;
        FindMax(cnt+1);
    }
}

int main() {
    cin >> expression;

    max_val=INT_MIN;
    for(int i=0;i<6;i++)
        alpha[i]=0;

    FindMax(0);

    cout<<max_val;
    return 0;
}
