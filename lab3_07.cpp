/*Given a binary string S of length N, count the total number of contiguous substrings that start and end with the character ’1’.

Input Format

The lab interface follows the input structure shown in the original problem and the test cases below. Original example: S = "10101".

Constraints

Use the constraints of the cited original problem. The uploaded lab sheet does not restate numeric bounds, so this reformatted version does not introduce new limits.

Output Format

Produce the value/data structure required by the statement. Original expected output: 6 (substrings: "1", "1", "1", "101", "10101", "101" – note overlapping counted separately).

Sample Input 0

10101
Sample Output 0

6
Explanation 0

The substrings that start and end with '1' are:

1 1 1 101 101 10101

Hence, the total number of such substrings is 6.

Sample Input 1

1
Sample Output 1

1
Explanation 1

The string contains only one character:

1

This single character itself is a substring that starts and ends with '1'.

Hence, the answer is 1.*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    
    string s;
    cin>> s;
 
    int count = 0;
    
    for(int i = 0; i < s.length(); i++){
        if (s[i] == '1'){ 
            for (int j = i; j < s.length(); j++) {
                if (s[j] == '1') {
                    count++;
                }
            }
        }
    }
        
    cout<<count<<endl;
    
    return 0;
    
}