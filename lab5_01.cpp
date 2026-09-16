/*
In an ancient laboratory, a ritual is represented by a sequence of six special symbols:

( ) [ ] { }

An opening sigil starts a new ritual layer, while its corresponding closing sigil attempts to finish that layer.

The ritual follows one strict rule:

The most recently opened layer must always be the first one to be closed.

For example:

{ [ ( ) ] }

is valid because each layer is closed in the reverse order in which it was opened.

However:

{ [ ( ] ) }

is invalid because [ cannot be closed while ( is still open.

Your task is to determine whether the complete ritual sequence can be executed without violating this rule.

Important Rules

A ritual is Balanced only when:

Every closing sigil has a corresponding opening sigil.
The opening and closing sigils are of the same type.
The most recently opened sigil is always closed first.
No unopened sigil remains at the end.
Input Format

The input contains a single line containing a string S.

The string contains only the following six characters:

( ) [ ] { }

Constraints

1 ≤ |S| ≤ 100000

S contains only (, ), [, ], {, and }.

Output Format

Print:

Balanced

if the ritual is valid.

Otherwise, print:

Not Balanced

Sample Input 0

{[()]}
Sample Output 0

Balanced
Explanation 0

The ritual opens the layers in this order:

{ [ (

They are closed in the reverse order:

) ] }

Therefore, the ritual is valid.

Sample Input 1

{[(])}
Sample Output 1

Not Balanced
Explanation 1

After opening:

{ [ (

the next symbol is ].

But the most recently opened layer is (, so ] cannot close it.

Therefore, the ritual is invalid.
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

string isBalanced(string s) {
    stack<char> st;
    
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } 
        
        else {
            if (st.empty()) {
                return "Not Balanced";
            }
            
            char top = st.top();
            st.pop();
            
            if ((c == ')' && top != '(') || 
                (c == ']' && top != '[') || 
                (c == '}' && top != '{')) {
                return "Not Balanced";
            }
        }
    }
    
    if (st.empty()) {
        return "Balanced";
    } else {
        return "Not Balanced";
    }
}

int main() {
    string s;
    cin >> s;
    cout << isBalanced(s) << "\n";
    
    return 0;
}