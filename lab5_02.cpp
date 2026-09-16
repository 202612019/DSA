/*
A communication center has M signal towers arranged from left to right. Each tower has a unique signal-strength value.

For every selected tower, the center wants to know the first tower appearing to its right whose signal strength is strictly greater than its own.

If no stronger tower exists to its right, the answer for that tower is -1.

You are given:

a list of selected towers A
the complete tower arrangement B
Every value in A is guaranteed to appear in B.

For each value in A, return its first greater value appearing after it in B.

The answers must be printed in the same order as the towers appear in A.

Input Format

The first line contains an integer N, the number of selected towers.

The second line contains N space-separated integers representing array A.

The third line contains an integer M, the number of towers in the complete arrangement.

The fourth line contains M space-separated integers representing array B.

Constraints

1 ≤ N ≤ 100000 N ≤ M ≤ 200000 1 ≤ A[i] ≤ 10^9 1 ≤ B[i] ≤ 10^9

Additional conditions:

All elements in B are distinct.
Every element of A appears in B.
A contains only elements from B.
Output Format

Print N space-separated integers.

For each element of A, print the first strictly greater element to its right in B.

Print -1 if no such element exists.

Sample Input 0

3
4 1 2
4
1 3 4 2
Sample Output 0

-1 3 -1
Explanation 0

The complete tower arrangement is:

1 3 4 2

For 4, nothing greater appears after it:

4 → -1

For 1, the first greater tower is 3:

1 → 3

For 2, there is no tower after it:

2 → -1

Hence:

-1 3 -1

Sample Input 1

3
2 4 3
5
5 2 7 4 3
Sample Output 1

7 -1 -1
Explanation 1

For 2, the first greater value to its right is 7.

For 4, there is no greater value after it.

For 3, there is no value after it
*/

#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

int main() {
    
    int N;
    cin >>N;
    
    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int M;
    cin >> M;
    
    int B[M];
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }

    unordered_map<int, int> next_greater;
    stack<int> st;

    for (int i = 0; i < M; i++) {
        while (!st.empty() && st.top() < B[i]) {
            next_greater[st.top()] = B[i];
            st.pop();
        }
        st.push(B[i]);
    }

    while (!st.empty()) {
        next_greater[st.top()] = -1;
        st.pop();
    }

    for (int i = 0; i < N; i++) {
        cout << next_greater[A[i]] << (i == N - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}