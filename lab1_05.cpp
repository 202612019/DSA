#include <iostream>
#include <vector>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

string multiplyPrimarySchool(string a, string b) {
    if (a == "0" || b == "0") return "0";

    int n = a.size();
    int m = b.size();
    vector<int> result(n + m, 0);

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int mul = (a[i] - '0') * (b[j] - '0');
            int sum = mul + result[i + j + 1];

            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    string finalResult = "";
    bool skipLeadingZeros = true;
    for (int num : result) {
        if (num != 0) skipLeadingZeros = false;
        if (!skipLeadingZeros) finalResult += to_string(num);
    }

    return finalResult.empty() ? "0" : finalResult;
}

string addStrings(string num1, string num2) {
    string res = "";
    int carry = 0;
    int i = num1.length() - 1;
    int j = num2.length() - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';
        res = to_string(sum % 10) + res;
        carry = sum / 10;
    }
    return res;
}

string subtractStrings(string num1, string num2) {
    string res = "";
    int borrow = 0;
    int i = num1.length() - 1;
    int j = num2.length() - 1;

    while (i >= 0) {
        int diff = (num1[i] - '0') - borrow;
        if (j >= 0) diff -= (num2[j--] - '0');
        
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        res = to_string(diff) + res;
        i--;
    }

    res.erase(0, res.find_first_not_of('0'));
    return res.empty() ? "0" : res;
}

string multiplyKaratsuba(string a, string b) {
    if (a.length() < 4 || b.length() < 4) {
        return multiplyPrimarySchool(a, b);
    }

    int n = max(a.length(), b.length());
    while (a.length() < n) a = "0" + a;
    while (b.length() < n) b = "0" + b;

    int half = n / 2;

    string a_left = a.substr(0, n - half);
    string a_right = a.substr(n - half);
    string b_left = b.substr(0, n - half);
    string b_right = b.substr(n - half);

    string P1 = multiplyKaratsuba(a_left, b_left);
    string P2 = multiplyKaratsuba(a_right, b_right);
    string P3 = multiplyKaratsuba(addStrings(a_left, a_right), addStrings(b_left, b_right));

    string middleTerm = subtractStrings(subtractStrings(P3, P1), P2);

    string P1_shifted = P1;
    for (int i = 0; i < 2 * half; i++) P1_shifted += "0";

    string middleTerm_shifted = middleTerm;
    for (int i = 0; i < half; i++) middleTerm_shifted += "0";

    string finalResult = addStrings(addStrings(P1_shifted, middleTerm_shifted), P2);
    
    finalResult.erase(0, finalResult.find_first_not_of('0'));
    return finalResult.empty() ? "0" : finalResult;
}

int main() {
    string num1 = "123456789";
    string num2 = "987654321";

    cout << "Input 1: " << num1 << "\n";
    cout << "Input 2: " << num2 << "\n\n";

    auto start1 = high_resolution_clock::now();
    string res1 = multiplyPrimarySchool(num1, num2);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);

    cout << "Output (Primary School Method): \n" << res1 << "\n";
    cout << "Time taken: " << duration1.count() << " microseconds\n\n";

    auto start2 = high_resolution_clock::now();
    string res2 = multiplyKaratsuba(num1, num2);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);

    cout << "Output (Karatsuba Method): \n" << res2 << "\n";
    cout << "Time taken: " << duration2.count() << " microseconds\n";

    return 0;
}