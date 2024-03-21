class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     int r,c,s,e;
     r=matrix.size();
     c=matrix[0].size();
     s=0;
     e=r*c-1;
     int mid=s+(e-s)/2;
     while(s<=e)
     {
         if(matrix[mid/c][mid%c]==target)
         {
             return true;
         }
         else if(matrix[mid/c][mid%c]<target)
         {
             s=mid+1;
         }
         else
         {
             e=mid-1;
         }
         mid=s+(e-s)/2;
     }
     return false;
    }
};
