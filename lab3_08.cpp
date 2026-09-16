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
#include <climits> // Needed for INT_MAX

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    if (s.empty() || t.empty()) {
        cout << "" << endl;
        return 0;
    }

    int target[256] = {0}; 
    int window[256] = {0};

    for (int i = 0; i < t.length(); i++) {
        target[t[i]]++;
    }

    int left = 0, right = 0;
    int matches = 0;
    int required_matches = t.length();

    int min_length = INT_MAX;
    int best_start = 0;

    while (right < s.length()) {
        char current_char = s[right];
        
        window[current_char]++; 

        if (target[current_char] > 0 && window[current_char] <= target[current_char]) {
            matches++;
        }

        while (matches == required_matches) {
            
            int current_window_size = right - left + 1;
            if (current_window_size < min_length) {
                min_length = current_window_size;
                best_start = left;
            }

            char left_char = s[left];
            window[left_char]--; 

            if (target[left_char] > 0 && window[left_char] < target[left_char]) {
                matches--;
            }

            left++; 
        }

        right++; 
    }

    if (min_length == INT_MAX) {
        cout << "" << endl;
    } else {
        cout << s.substr(best_start, min_length) << endl;
    }

    return 0;
}