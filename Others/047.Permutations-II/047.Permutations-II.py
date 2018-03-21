class Solution:
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums)==0: return []
        results = [[nums[0]]]
        
        for n in nums[1:]:
            
            new_results = []            
            for seq in results:                
                for i in range(0,len(seq)):                    
                    new_results.append(seq[0:i]+[n]+seq[i:])                
                    if n==seq[i]: break
                    if (i==len(seq)-1):                
                        new_results.append(seq+[n])
            results = new_results
            print(results)
            
        return results;
        
        
