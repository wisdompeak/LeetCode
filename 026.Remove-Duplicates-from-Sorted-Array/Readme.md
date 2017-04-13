### 26. Remove Duplicates from Sorted Array
注意去除重复元素后仍然要求保持原始顺序，必须in-place实现，故考虑快慢双指针。  
用快指针略过所有重复元素，并将每段重复元素的第一个赋给慢指针即可。
