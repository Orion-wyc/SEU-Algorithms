#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

const int MAXN = 1005;
//不想额外开空间，但是总觉得这个写法不完美qwq
void partition(int nums[], int reg[], int left, int right, int depth){
    if(left < right){
        int mid = left + (right-left)/2;
        partition(nums, reg, left, mid, depth+1);
        partition(nums, reg, mid+1, right, depth+1);

        if(depth>=2) {
            int l=left,r=mid+1,k=left;
            while(l<=mid && r<=right){
                reg[k++] = nums[l] > nums[r] ? nums[r++] : nums[l++];
            }
            while(l<=mid){
                reg[k++] = nums[l++];
            }
            while(r<=right){
                reg[k++] = nums[r++];
            }
            for(int i=left;i<=right;i++){
                nums[i] = reg[i];
            }
        }
    }   
}



void mergesort(int nums[], int left, int right,int d){
    int reg[MAXN];
    partition(nums,reg,left,right,d);
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
        mergesort(nums,0,n-1,0);
        printnums(nums,n);
    }
    // system("pause");
    return 0;
}
