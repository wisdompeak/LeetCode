class NumArray {
    vector<int>tree;
    vector<int>Nums;
    
public:
    NumArray(vector<int> nums) 
    {
        Nums=vector<int>(nums.size()+1);
        tree=vector<int>(nums.size()+1);
        for (int i=0; i<nums.size(); i++)
        {
            update(i,nums[i]);
        }
    }
    
    void update(int i, int val) 
    {
        int diff = val-Nums[i+1];
        for (int j=i+1; j<Nums.size(); j+=(j&-j))
            tree[j]+=diff;
        Nums[i+1]+=diff;
    }
    
    int sumRange(int i, int j) 
    {
        return getSum(j+1)-getSum(i);
    }
    
    int getSum(int i)
    {
        int res = 0;
        for (int j = i; j > 0; j -= (j&-j)) 
        {
            res += tree[j];
        }
        return res;        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
