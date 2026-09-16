/*
A machine stores N different integer readings in an arbitrary order.

Before the readings are analyzed, they are arranged in increasing order.

The middle position is defined as:

(N - 1) / 2

using 0-based indexing.

For a given integer K, we are interested in the reading that is exactly K positions to the right of the middle position.

However, the reading at that position may not exist.

Your task is to print the original 0-based index of that reading.

If the requested position is outside the sorted array, print -1.

Important All readings are distinct. Sorting is performed only for determining the requested position. The answer must be the index of that reading in the original unsorted array.

Input Format

The first line contains two space-separated integers:

N K

The second line contains N space-separated integers representing the readings.

Constraints

1 ≤ N ≤ 100000 0 ≤ K ≤ 100000 -10^9 ≤ reading[i] ≤ 10^9

Output Format

Print a single integer representing the 0-based index of the selected reading in the original input array.

If the requested position does not exist in the sorted array, print -1.

Sample Input 0

7 2
40 10 70 20 50 30 60
Sample Output 0

6
Explanation 0

The readings after sorting are:

10 20 30 40 50 60 70

There are 7 readings, so the middle position is:

(7 - 1) / 2 = 3

The middle reading is:

40

We need K = 2 positions to the right:

position 3 + 2 = 5

The reading at position 5 is:

60

In the original input, 60 was at index 6.

Therefore, the answer is:

6

Sample Input 1

6 1
25 5 40 10 30 20
Sample Output 1

0
Explanation 1

After sorting:

5 10 20 25 30 40

The middle position is:

(6 - 1) / 2 = 2

So the middle reading is 20.

One position to the right is:

position 3 → 25

25 originally occurred at index 0.

Sample Input 2

5 3
18 2 11 7 30
Sample Output 2

-1
Explanation 2

After sorting:

2 7 11 18 30

Middle position:

(5 - 1) / 2 = 2

Requested position:

2 + 3 = 5

But the last valid position is 4.

Therefore, the requested reading does not exist.

Output:

-1
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> readings(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> readings[i].first;
        readings[i].second = i;
    }

    sort(readings.begin(), readings.end());

    int mid = (n - 1) / 2;
    int target = mid + k;

    if (target < n) {
        cout << readings[target].second << "\n";
    } else {
        cout << -1 << "\n";
    }

    return 0;
}