#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    string s;
    cin>>s;
    
    bool a = true;
    int streak=0;
    
    for(int i = 0; i < n; i++){
        char cur = s[i];
        
        if(cur!='a' && cur!='e' && cur!='i' && cur!='o' && cur!='u'){
            streak++;
            if(streak==3){
                a = false;
                break;
            }
        }
        else{
            streak=0;
        }
    }
    
    if(a){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    
    return 0;
}