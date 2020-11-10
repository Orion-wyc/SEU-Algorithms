#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1005;

//方法一 堆排序求 top-k ,时间按复杂度 o(nlogk)
// 下标 0 开始
void adjustDown(int heap[], int s, int m){ //s - 需调整的非叶子结点, m - 最后一个叶子结点
    int tmp = heap[s];
    for(int i=2*s + 1;i<=m;i=2*i+1){
        if(i<m && heap[i] < heap[i+1]) i++;
        if(tmp < heap[i]){
            heap[s] = heap[i];
            s = i;
        }
    }
    heap[s] = tmp;
}

int findTop_k(int nums[], int len, int k){
    int* heap_k = new int[k]; 
    for(int i=0;i<k;i++){
        heap_k[i] = nums[i];
    }
    // 初始 k 个元素建立大顶堆
    for(int s=len/2-1; s>=0;s--){
        adjustDown(heap_k, s, k-1);
    }
    //寻找 top-k
    for(int i=k;i<len;i++){
        if(nums[i] < heap_k[0]){// 当前元素小于堆顶元素
            heap_k[0] = nums[i];
            adjustDown(heap_k, 0, k-1);
        }
    }

    int res = heap_k[0];
    delete[] heap_k;
    return res;
}

//方法二 快排思想


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
        cout<< findTop_k(nums, n, 2) <<endl;
    }
    // system("pause");
    return 0;
}