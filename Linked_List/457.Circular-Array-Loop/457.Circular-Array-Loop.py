class Solution(object):
    def circularArrayLoop(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        def getNext(i,nums,direction):
            if ((nums[i]>0)*2-1)!=direction: return -1                            
            j=i+nums[i];
            j=(j+len(nums))%len(nums)
            if (j==i): return -1
            return i
        
        def getNext2(i,nums,direction):            
            j=getNext(i,nums,direction)
            if (j==-1): return -1;
            k=j+nums[j];
            k=(k+len(nums))%len(nums)
            if (k==i): return -1
            return k
        
        for i in range(len(nums)):
            if (nums[i]==0): continue;
            fast,slow = i,i
            direction = (nums[i]>0)*2-1;
            while(getNext(slow,nums,direction)!=-1 and getNext2(fast,nums,direction)!=-1):
                slow,fast = getNext(slow,nums,direction),getNext2(fast,nums,direction)
                if (fast==slow): break;
            if (getNext(slow,nums,direction)!=-1 and getNext2(fast,nums,direction)!=-1):
                return True            
            slow = i;
            while (getNext(slow,nums,direction)!=-1):
                nums[slow]=0
                slow=getNext(slow,nums,direction)                
        return False
                
