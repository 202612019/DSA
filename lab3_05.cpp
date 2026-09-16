/*Given two non-negative integers low and high, return the count of odd numbers between low and high (inclusive).

For example, if low = 3 and high = 7, the odd numbers in the range are:

3, 5, 7

Therefore, the answer is 3.

Input Format

The first line contains two space-separated non-negative integers low and high.

Constraints

0 <= low <= high <= 10^9

Output Format

Print a single integer representing the count of odd numbers between low and high, inclusive.

Sample Input 0

3 7
Sample Output 0

3
Explanation 0

The odd numbers between 3 and 7 are:

3 5 7

There are 3 odd numbers.

Hence, the answer is 3.

Sample Input 1

8 10
Sample Output 1

1
Explanation 1

The only odd number between 8 and 10 is:

9

Hence, the answer is 1.*/

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