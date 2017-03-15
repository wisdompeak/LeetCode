class Solution {
private:
    struct cmp
    {
        bool operator()(pair<int,int>a,pair<int,int>b)
        {
            return (a.first>b.first);
        }
    };
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int M=nums1.size();
        int N=nums2.size();
        
        if ((M+N)%2==0)
            return (helper(nums1,nums2,(M+N)/2)+helper(nums1,nums2,(M+N)/2+1))/2;
        else
            return helper(nums1,nums2,(M+N)/2+1);
    }
    
    double helper(vector<int>& nums1, vector<int>& nums2, int k)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>q;
        int i=0, j=0;
        int M=nums1.size();
        int N=nums2.size();
        int count=0;
        
        if (i!=M) q.push({nums1[i],1});
        if (j!=N) q.push({nums2[j],2});
        
        while (!q.empty())
        {
            int val = q.top().first;
            int label = q.top().second;
            count++;
            q.pop();
            
            //cout<<val<<endl;
            
            if (count==k) return (double)val;
            
            if (label==1)
            {
                if (i==M-1) 
                    continue;
                else
                {
                    i++;
                    q.push({nums1[i],1});
                }
            }
            if (label==2)
            {
                if (j==N-1) 
                    continue;
                else
                {
                    j++;
                    q.push({nums2[j],2});
                }
            }            
        }        
        
        return -1;
    }
};
