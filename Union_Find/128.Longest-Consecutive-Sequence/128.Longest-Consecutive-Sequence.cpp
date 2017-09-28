class Solution {
	unordered_map<int,int>Father;
public:
    int longestConsecutive(vector<int>& nums) 
	{
        if (nums.size()==0) return 0;

		for (int i=0; i<nums.size(); i++)
		{
			Father[nums[i]]=nums[i];
			if (Father.find(nums[i]-1)!=Father.end() && FindSet(nums[i]-1)!=FindSet(nums[i]))			
				Union(nums[i]-1,nums[i]);						
			if (Father.find(nums[i]+1)!=Father.end() && FindSet(nums[i]+1)!=FindSet(nums[i]))
				Union(nums[i]+1,nums[i]);			
		}
        
   		for (int i=0; i<nums.size(); i++)
        {
            Father[nums[i]]=FindSet(nums[i]);
        }
        
		unordered_map<int,unordered_set<int>>Map;
		for (auto a:Father)
			Map[a.second].insert(a.first);
		
		int result=0;
		for (auto a:Map)
		{
			int n=a.second.size();
            result=max(result,n);
		}
		return result;
    }

	int FindSet(int x)
	{
		if (Father[x]!=x)
			Father[x]=FindSet(Father[x]);
		return Father[x];
	}

	void Union(int x, int y)
	{
		x=Father[x];
		y=Father[y];
		if (x<=y)
			Father[y]=x;
		else
			Father[x]=y;
	}

};
