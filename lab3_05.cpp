#include <iostream>
using namespace std;

int main() {
    
    int low;
    cin >> low;
    
    int high;
    cin >> high;
    
    int count = 0;
    
    for( low ; low <= high; low++){
        if(low % 2 != 0){
            count++;
        }
    }
    
    cout<<count<<endl;
    
    return 0;
}



// #include <iostream>
// using namespace std;

// int main() {
//     int low, high;
    
//     if (cin >> low >> high) {
     
//         int odds_up_to_high = (high + 1) / 2;
//         int odds_before_low = low / 2; 
//         cout << odds_up_to_high - odds_before_low << "\n";
//     }
    
//     return 0;
// }