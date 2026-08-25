#include <iostream>
#include <string>
using namespace std;


int main() {
    
    int n;
    cin >> n;
    
    string s;
    cin>>s;
    
    bool is_true = true;
    int streak=0;
    
    for(int i = 0; i < n; i++){
        if (s[i]=='1'){
            if(i == 0 || s[i - 1] == '0'){
                streak++;
            }
            
            if(streak>1){
                is_true = false;
                break;
            }
        }
    }
    
    if(is_true){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    
    return 0;
}