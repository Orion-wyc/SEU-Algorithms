#include <iostream>
#include <cstdlib>

using namespace std;

const int MAXN = 1005;

int partition2(int nums[], int left,int right){
    int key = nums[left];
    while(left < right){
        while(left<right && nums[right] >= key) right --;
        nums[left] = nums[right];
        while(left<right && nums[left] <= key) left ++;
        nums[right] = nums[left];
    }
    nums[left] = key;
    return left;
}

int partition(int nums[], int left,int right){
    int key = nums[left];
    int p = left;
    for(int i=left;i<=right;i++){
        if(nums[i] < key){
            p++;
            swap(nums[i],nums[p]);
        }
    }
    nums[left] = nums[p];
    nums[p] = key;
    return p;
}

void quicksort(int nums[], int left, int right, int depth){
    if(left < right){
        int pos = partition(nums,left,right);
        if(depth==1){
            return;
        }
        quicksort(nums, left, pos-1, depth + 1);
        quicksort(nums, pos+1, right, depth + 1);
    }
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
        quicksort(nums,0,n-1,0);
        printnums(nums,n);
    }
    // system("pause");
    return 0;
}