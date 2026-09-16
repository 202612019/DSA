/*You are given a lowercase string S of length N.

A character is a vowel if it is one of:

a, e, i, o, u

All other lowercase English letters are considered consonants.

A word is considered hard to pronounce if it contains 3 or more consecutive consonants.

Your task is to determine whether the given word is easy to pronounce.

Print "YES" if the word is easy to pronounce.

Print "NO" if the word is hard to pronounce.

Input Format

The first line contains an integer N, representing the length of the string.

The second line contains a lowercase string S of length N.

Constraints

1 ≤ N ≤ 100 S consists only of lowercase English letters.

Output Format

Print "YES" if the string is easy to pronounce.

Print "NO" if the string contains 3 or more consecutive consonants.

Sample Input 0

7
scholar
Sample Output 0

NO
Explanation 0

The string "scholar" contains the consecutive consonants "sch", which has 3 consonants in a row.

Therefore, the word is hard to pronounce.

Sample Input 1

5
apple
Sample Output 1

NO
Explanation 1

The string "apple" contains three consecutive consonants "ppl".

Therefore, the word is hard to pronounce.*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    string s;
    cin>>s;
    
    bool a = true;
    int streak=0;
    
    for(int i = 0; i < n; i++){
        char cur = s[i];
        
        if(cur!='a' && cur!='e' && cur!='i' && cur!='o' && cur!='u'){
            streak++;
            if(streak==3){
                a = false;
                break;
            }
        }
        else{
            streak=0;
        }
    }
    
    if(a){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    
    return 0;
}