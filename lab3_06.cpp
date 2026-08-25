#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    
    string s;
    cin >>s;
    
    int n = s.length();
    
    int mid = n/2;
    
    string str1, str2;
    
    if(n%2==0){
         str1 = s.substr(0, mid);
         str2 = s.substr(mid, mid); 
    }
    
    if(n%2!=0){
        str1 = s.substr(0, mid);
        str2 = s.substr(mid+1, mid); 
    }
    
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    
    if (str1==str2){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    
    return 0;
}