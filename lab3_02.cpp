#include <iostream>
using namespace std;

int main() {
    
    int n;
    cin>> n;
    int arr[n];
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    if(n==0){
        return 0;
    }
    
    int k = 1;

    for(int i=1; i<n; i++){
        if(arr[i]!= arr[i-1]){
            arr[k]= arr[i];
            k++;
        }
    }

    cout<<k;

    return 0;
}