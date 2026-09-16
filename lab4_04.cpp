/*
A data center stores N records, and each record has an integer value.

Before an audit begins, the records are arranged in non-decreasing order of their values. If two records have the same value, the one that appeared earlier in the original input is placed first.

For a record with value x, another record with value y is called its valid partner if:

L ≤ y - x ≤ R

A record can only be paired with a record that appears after it in the sorted order.

For each record, count how many valid partners it has.

Your task is to find the first record in the sorted order whose number of valid partners is exactly P.

Print the original 0-based index of that record.

If no such record exists, print -1.

Important

A record cannot be its own partner.

If multiple records have the same value, they are still considered different records.

Input Format

The first line contains four space-separated integers:

N L R P

The second line contains N space-separated integers representing the values of the records in their original order.

Constraints

2 ≤ N ≤ 200000 0 ≤ L ≤ R ≤ 10^9 0 ≤ values[i] ≤ 10^9 0 ≤ P ≤ N

Output Format

Print a single integer:

the original 0-based index of the first qualifying record, or -1 if no record has exactly P valid partners.

Sample Input 0

7 2 5 2
9 2 7 4 10 6 15
Sample Output 0

5
Explanation 0

After sorting:

2 4 6 7 9 10 15

The number of valid later partners for each value is:

2 → 3 4 → 3 6 → 2 7 → 2 9 → 1 10 → 0 15 → 0

The first record with exactly 2 valid partners is 6.

The value 6 originally appeared at index 5.

Therefore, the answer is 5.

Sample Input 1

5 1 2 1
5 1 3 6 8
Sample Output 1

1
Explanation 1

After sorting:

1 3 5 6 8

with original indices:

1 2 0 3 4

For the record 1, the only valid partner is 3 because:

1 ≤ 3 - 1 ≤ 2

So it has exactly 1 valid partner.

Its original index is 1.

Therefore:

1
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    int n, p;
    long long L, R; 
    
    cin >> n >> L >> R >> p;

    vector<pair<long long, int>> records(n);
    for (int i = 0; i < n; ++i) {
        cin >> records[i].first;
        records[i].second = i;
    }

    sort(records.begin(), records.end());

    vector<long long> vals(n);
    for (int i = 0; i < n; ++i) {
        vals[i] = records[i].first;
    }

    for (int i = 0; i < n; ++i) {
        long long current_val = vals[i];
        long long target_min = current_val + L;
        long long target_max = current_val + R;

        auto it_min = lower_bound(vals.begin() + i + 1, vals.end(), target_min);
        auto it_max = upper_bound(vals.begin() + i + 1, vals.end(), target_max);

        int valid_partners = distance(it_min, it_max);

        if (valid_partners == p) {
            cout << records[i].second << "\n";
            return 0;
        }
    }

    cout << -1 << "\n";

    return 0;
}