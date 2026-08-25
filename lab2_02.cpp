#include <iostream>
using namespace std;

int main() {
   
    int n;
    cin >> n;

    int arr[n];
   
    int sum = n * (n + 1) / 2;
    int actualSum = 0;
   
   for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
        actualSum += arr[i];
    }
   
   int missing = sum - actualSum;

    cout << missing << endl;
     
    return 0;
    
}