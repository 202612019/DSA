#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;

    int arr[n];
    int arr2[n];

    int start = 0;
    int count = n - 1;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {

        if (arr[i] != 0) {
            arr2[start] = arr[i];
            start++;
        }
        else {
            arr2[count] = arr[i];
            count--;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << arr2[i] << " ";
    }
    
    return 0;
}


// #include <iostream>
// using namespace std;


// int main() {
   
//     int n;
//     cin >> n;


//     int arr[n];
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
   
//     int in_zero = 0;
   
//     for (int i = 0; i < n; ++i) {
//         if (arr[i] != 0) {
//             arr[in_zero] = arr[i];
//             in_zero++;
//         }
//     }
   
//     while (in_zero < n) {
//         arr[in_zero] = 0;
//         in_zero++;
//     }
   
//     for (int i = 0; i < n; ++i) {
//         cout << arr[i] << (i == n - 1 ? "" : " ");
//     }
//     cout << "\n";
     
//     return 0;
// }
