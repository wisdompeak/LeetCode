class Solution(object):
    def circularArrayLoop(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        def getNext(pos,nums,dir):
            if (dir*nums[pos]<0): return -1
            x = pos+nums[pos]
            if (x>=len(nums)): x-=len(nums)
            elif (x<0): x+=len(nums)
            if (x==pos): return -1
            else: return x
                
        def getNextTwo(pos,nums,dir):
            x = getNext(pos,nums,dir)                  
            if (x==-1 or dir*nums[x]<0): return -1
            x = getNext(x,nums,dir)
            return x
        
        for i in range(len(nums)):
            if (nums[i]==0): continue;
            fast, slow = i,i
            if (nums[i]>0): dir = 1
            else: dir = -1;
            while (getNextTwo(fast,nums,dir)!=-1 and getNext(slow,nums,dir)!=-1):
                fast,slow = getNextTwo(fast,nums,dir),getNext(slow,nums,dir)
                if (fast==slow): break
            if (getNext(slow,nums,dir)!=-1 and getNextTwo(slow,nums,dir)!=-1):
                return True
            slow = i
            while (getNext(slow,nums,dir)!=-1): 
                nums[slow]=0
                slow = getNext(slow,nums,dir)                 
        return False
            
                
