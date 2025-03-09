#include <iostream>

using namespace std;

#define MAX_N 45

int N;

int arr[MAX_N+1];

int main() {
    cin >> N;

    arr[1]=1;
    arr[2]=1;
    for(int i=3;i<=N;i++){
        arr[i]=arr[i-1]+arr[i-2];
    }

    cout<<arr[N];
    return 0;
}
