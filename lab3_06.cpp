/*Given two strings s and t, return the minimum window substring of s such that every character in t (including duplicates) is included in the window.

If there is no such substring, return the empty string "".

Input Format

The first line contains the string s.

The second line contains the string t.

Constraints

Use the constraints of the cited original problem. The uploaded lab sheet does not restate numeric bounds, so this reformatted version does not introduce new limits.

Output Format

Print the minimum window substring of s that contains every character in t.

If no such substring exists, print an empty string.

Sample Input 0

ADOBECODEBANC
ABC
Sample Output 0

BANC
Explanation 0

The string s is:

ADOBECODEBANC

The string t is:

ABC

The minimum window substring of s that contains A, B, and C is:

BANC

Hence, the answer is BANC.

Sample Input 1

a
aa
Explanation 1

The string s contains only one 'a', while t requires two 'a' characters.

Therefore, no valid window exists.

Hence, the answer is an empty string.*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    
    string s;
    cin >>s;
    
    int n = s.length();
    
    int mid = n/2;
    
    string str1, str2;
    
    if(n%2==0){
         str1 = s.substr(0, mid);
         str2 = s.substr(mid, mid); 
    }
    
    if(n%2!=0){
        str1 = s.substr(0, mid);
        str2 = s.substr(mid+1, mid); 
    }
    
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    
    if (str1==str2){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    
    return 0;
}