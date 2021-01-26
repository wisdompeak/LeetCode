### 645.Set-Mismatch

此题其实就是```442.Find-All-Duplicates-in-an-Array```和```448.Find-All-Numbers-Disappeared-in-an-Array```的拼接。最后遍历到```nums[i]!=i```的位置时，说明nums[i]是duplicated number，而i就是missing number.

[Leetcode Link](https://leetcode.com/problems/set-mismatch)
