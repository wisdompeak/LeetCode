from sortedcontainers import SortedList
class Solution:
    def resultArray(self, nums: List[int]) -> List[int]:
        s1 = SortedList([nums[0]])
        s2 = SortedList([nums[1]])
        arr1 = [nums[0]]
        arr2 = [nums[1]]
        
        for i in range(2, len(nums)):            
            x = len(s1)-s1.bisect_right(nums[i])
            y = len(s2)-s2.bisect_right(nums[i])
            if (x>y) or (x==y and len(arr1)<=len(arr2)):
                arr1.append(nums[i])
                s1.add(nums[i])
            else:
                arr2.append(nums[i])
                s2.add(nums[i])
                
        return arr1+arr2
        
        
