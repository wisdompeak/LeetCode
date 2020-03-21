### 302.Smallest-Rectangle-Enclosing-Black-Pixels

立足所给的点(x,y)，划分整个区域为上半部分、下半部分、左半部分、右半部分。

对于上半部分，从第0行到第x行进行二分搜索，找到第一个出现1的行 (该行的所有列中至少有一个1)。注意，因为right的初始值x已知是含有1的，所以需要选择搜索机制保证收敛时必为含有1的行。
```cpp
    int UPPER(vector<vector<char>>& image,int RowMin, int RowMax, int ColMin, int ColMax)
    {
        int left = RowMin;
        int right = RowMax;
        int mid;
        while (left<right)
        {
            mid = left+(right-left)/2;
            int flag = 0;
            for (int i=ColMin; i<=ColMax; i++)
            {
                if (image[mid][i]=='1')
                {
                    flag = 1;
                    break;
                }
            }
            if (flag==0)
                left = mid+1; //将不合格的行排除的搜索范围之外（没有1）
            else
                right = mid; // 保持右界始终是合格的行（含有1）
        }
        return left;  // 这样最终收敛的结果必定是合格的行，不必复查
   }
```
同理，对于下半部分，从第x行到第M-1行进行二分搜索，找到最后一个出现1的行。

对于左半部分，从第0列到第y列进行二分搜索，找到第一个出现1的列。

对于右半部分，从第y列到第N-1列进行二分搜索，找到最后一个出现1的列。

整个时间复杂度 o(4*N*logN)

对比：宽度遍历完整的1矩阵，o(N*N)


[Leetcode Link](https://leetcode.com/problems/smallest-rectangle-enclosing-black-pixels)