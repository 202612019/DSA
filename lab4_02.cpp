/*
A monitoring system records N readings. After sorting the readings in increasing order, the system considers two neighboring readings to be an "unstable pair" if their difference is greater than K.

Find the index of the first unstable pair in the sorted sequence.

If no such pair exists, print -1.

The index refers to the position of the first value of the pair in the sorted array, using 0-based indexing.

Note that the original readings are not necessarily sorted.

Input Format

The first line contains two space-separated integers N and K.

The second line contains N space-separated integers representing the readings.

Constraints

2 ≤ N ≤ 100000 0 ≤ K ≤ 10^9 0 ≤ reading[i] ≤ 10^9

Output Format

Print the 0-based index of the first unstable pair after sorting the readings.

If every neighboring pair has a difference less than or equal to K, print -1.

Sample Input 0

6 5
10 14 17 21 24 27
Sample Output 0

-1
Explanation 0

The array is already sorted:

10 14 17 21 24 27

The neighboring differences are:

4 3 4 3 3

None is greater than 5, so there is no unstable pair.

Therefore, the answer is -1.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    
    int n, k;
    cin >> n >> k;

    vector<int> readings(n);
    for (int i = 0; i < n; ++i) {
        cin >> readings[i];
    }

    sort(readings.begin(), readings.end());

    for (int i = 0; i < n - 1; ++i) {
        if (readings[i + 1] - readings[i] > k) {
            cout << i << "\n";
            return 0;
        }
    }

    cout << -1 << "\n";

    return 0;
}