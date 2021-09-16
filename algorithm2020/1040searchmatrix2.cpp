#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0 || matrix[0].size()==0)return false;
        int row=matrix.size()-1, col=0;
        while(row>=0 && col < matrix[0].size()){
            if(matrix[row][col]==target){
                return true;
            }else if(matrix[row][col] < target){
                col += 1;
            }else{
                row -= 1;
            }
        }
        return false;
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> matrix;
        Solution solve;
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
        cout<< (solve.searchMatrix(matrix, target) ? "true" : "false") <<endl;
    }
    
    // system("pause");
    return 0;
}