/*
Professor X has received N assignment scores.

He is angry because the scores are all over the place:

73 12 98 41 41 65 ...

So he creates a completely unnecessary rule:

"Put all scores in increasing order. Then I will ask you for the score standing at position K."

Unfortunately, Professor X forgot to tell the students that positions start from 0.

Your job is to save the class.

Given the original list of scores and an integer K, find the score that appears at position K after sorting the scores in non-decreasing order.

But there is one final problem.

Professor X wants to know where that particular score originally came from.

So you must print:

original index

of the score occupying sorted position K.

Important Rules Positions are 0-based. Scores may be repeated. If the same score appears multiple times, the copy with the smallest original index comes first. K is guaranteed to be a valid position.

Input Format

The first line contains two integers:

N K

The second line contains N space-separated integers representing the assignment scores.

Constraints

1 ≤ N ≤ 100000 0 ≤ K < N 0 ≤ score[i] ≤ 10^9

Output Format

Print the 0-based original index of the score that occupies position K after sorting.

Sample Input 0

7 3
40 10 70 20 50 30 60
Sample Output 0

0
Explanation 0

Original:

Index: 0 1 2 3 4 5 6 Score: 40 10 70 20 50 30 60

After sorting:

Score: 10 20 30 40 50 60 70 Original index: 1 3 5 0 4 6 2

K = 3, so we need the element at sorted position 3.

That element is:

40

and 40 originally appeared at index:

0

Therefore:

0

Sample Input 1

6 4
25 5 40 10 30 20
Sample Output 1

4
Explanation 1

Sorted scores:

5 10 20 25 30 40

Original indices:

1 3 5 0 4 2

Position 4 contains 30.

The original index of 30 is 4.

Sample Input 2

8 4
50 20 20 80 20 10 50 30
Sample Output 2

7
Explanation 2

After sorting, including original indices:

Score: 10 20 20 20 30 50 50 80 Index: 5 1 2 4 7 0 6 3

Position 4 contains 30.

The original index of 30 is 7.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> scores(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> scores[i].first;
        scores[i].second = i;
    }
    
    sort(scores.begin(), scores.end());

    cout << scores[k].second << "\n";

    return 0;
}