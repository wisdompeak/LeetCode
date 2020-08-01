class NumArray {
public:
    vector<int>bitArr;

    NumArray(vector<int>& nums) {
        int n = nums.size();        
        bitArr.resize(n+1);
        nums.insert(nums.begin(),0);
        for (int i=1; i<=n; i++)
            my_update(i+1, nums[i]);
        cout<<"init done"<<endl;
    }

    // increase nums[i] by delta (1-index)
    void my_update(int i, int delta) {
        while (idx<bitArr.size())
        {
            bitArr[idx]+=delta;
            idx+=idx&(-idx);
        }
    }
    
    // sum of range [1:idx] (1-index)
    int my_query(int idx){        
        int result = 0;
        while (idx){
            result += bitArr[idx];
            idx-=idx&(-idx);
        }
        return result;
    }

    // sum of range [i:j] (1-index)
    int sumRange(int i, int j) {
        return my_query(j)-my_query(i-1);
    }
};
