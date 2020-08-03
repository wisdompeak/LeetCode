/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y] 
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     int compareSub(int l, int r, int x, int y);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    int getIndex(ArrayReader &reader) 
    {
        int n = reader.length();
        
        int left = 0, right = n-1;        
        while (right-left+1>=3)
        {
            int k = (right-left+1)/3;
            int ret = reader.compareSub(left, left+k-1, left+k, left+2*k-1);
            if (ret==0)
            {
                left = left+2*k;                
            }
            else if (ret==1)
            {                
                right = left+k-1;
            }
            else
            {
                left = left+k;
                right = left+k*2-1;
            }
            // cout<<left<<" "<<right<<endl;
        }
        
        if (left==right) return left;
        else
        {
            if (reader.compareSub(left,left, right,right)==1)
                return left;
            else
                return right;
        }
        
    }
};
