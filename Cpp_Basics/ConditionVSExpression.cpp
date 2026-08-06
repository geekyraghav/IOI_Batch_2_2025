#include<iostream>
#include<climits>
using namespace std;
int main(){
    int brr[5]; // garbage values
    int n = sizeof(brr)/sizeof(brr[0]);
    for(int i=0;i<n;i++){
        cin>>brr[i];
    }
    // int arr[] = {5,8,1,2,9};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // cout<<n<<endl;
    // for(int i=0;i<=4;i++){
    //     cout<<arr[i]<<" ";
    // }


}