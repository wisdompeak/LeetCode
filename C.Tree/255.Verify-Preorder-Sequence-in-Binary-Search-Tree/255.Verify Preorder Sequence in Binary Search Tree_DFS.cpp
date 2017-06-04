class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) 
    {
        return DFS(preorder,0,preorder.size()-1);
    }
    
    bool DFS(vector<int>& preorder, int start, int end)
    {
        if (end-start<=1) return true;
        
        int root=preorder[start];
        int i=start;
        while (preorder[i+1]<root && i+1<=end) i++;
        int mid=i+1;
        i=mid;
        while (i<=end)
        {
            if (preorder[i]<=root)
                return false;
            i++;    
        }
        return DFS(preorder,start+1,mid-1)&&DFS(preorder,mid,end);
    }
};
