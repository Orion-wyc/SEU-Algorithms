#include <iostream>
#include <cstdlib>

using namespace std;

const int MAXN = 1005;

void heapsort(int nums[], int len){

}


void printnums(int nums[],int n){
    for(int i=0;i<n;i++){
        cout<<nums[i]<< (i<n-1 ? " ":"\n");
    }
}



int main(){
    int m;
    cin>> m;
    while(m--){
        int n;
        cin>> n;
        int nums[MAXN];
        for(int i=0;i<n;i++){
            int num; 
            cin>> num;
            nums[i] = num;
        }
        heapsort(nums,n);
        printnums(nums,n);
    }
    // system("pause");
    return 0;
}