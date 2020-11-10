#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

bool binarySearch(vector<vector<int>>& matrix, int row, int col, int target){
    int next_row, next_col;
    int l = 0, r = row;
    while(l < r){ //[0,r)
        int mid = l + (r - l) / 2;
        if(matrix[mid][col] >= target){
            r = mid;
        }else { 
            l = mid + 1;
        }
    }
    
    if(l < row && matrix[l][col]==target) return true;//判断row方向的下界数字是否是target
    next_row = l; // 求lower_bound
    if(next_row == 0) return false; // 判断row是否越界，即row方向数组为空

    l = col, r = matrix[0].size();
    while(l < r){
        int mid = l + (r - l) / 2;
        if(matrix[next_row-1][mid]>=target){
            r = mid;
        }else{
            l = mid+1;
        }
    }
    if(l == matrix[0].size()) return false; //判断col是否越界,即col方向数组为空
    next_col = l;
    
    return binarySearch(matrix, next_row, next_col,target);//左下角顶点坐标至右上角顶点
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(matrix.size()==0 || matrix[0].size()==0) return false;
    return binarySearch(matrix, matrix.size(), 0, target);  
}


int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> matrix;
        int m,n,target;
        cin>>m>>n>>target;
        for(int i=0;i<m;i++){
            vector<int> tmp;
            for(int j=0;j<n;j++){
                int x;
                cin>>x;
                tmp.push_back(x);
            }
            matrix.push_back(tmp);
        }
        cout<< (searchMatrix(matrix, target) ? "true" : "false") <<endl;
    }
    
    // system("pause");
    return 0;
}