#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    bool flag = true; // true means prime
    for(int i=1;i*i<=n;i++){
        if(n%i == 0){
            cout<<i<<" ";
            if(i!=n/i) cout<<n/i<<" ";
        }
    }
}