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