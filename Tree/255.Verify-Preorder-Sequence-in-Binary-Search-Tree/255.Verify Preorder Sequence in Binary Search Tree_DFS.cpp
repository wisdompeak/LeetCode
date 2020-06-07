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
        int i = start+1;
        while (i<=end && preorder[i]<root) i++;
                
        for (int j=i; j<=end; j++)        
        {
            if (preorder[j]<=root) return false;
        }
        return DFS(preorder,start+1,i-1)&&DFS(preorder,i,end);
    }
};
