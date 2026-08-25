#include <iostream>
#include <string>
using namespace std;

int main() {
    
    string s;
    cin>> s;
 
    int count = 0;
    
    for(int i = 0; i < s.length(); i++){
        if (s[i] == '1'){ 
            for (int j = i; j < s.length(); j++) {
                if (s[j] == '1') {
                    count++;
                }
            }
        }
    }
        
    cout<<count<<endl;
    
    return 0;
    
}