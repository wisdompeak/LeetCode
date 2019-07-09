class NumArray {
public:
    vector<int>bitArr;
    vector<int>nums;

    NumArray(vector<int>& nums) {
        this->nums = nums;
        bitArr.resize(nums.size()+1);
        for (int i=0; i<nums.size(); i++)
            my_update(i, nums[i]);
        cout<<"init done"<<endl;
    }

    void update(int i, int val){
        my_update(i, val-nums[i]);
        nums[i] = val;
    }

    void my_update(int i, int delta) {
        int idx = i+1;
        while (idx<bitArr.size())
        {
            bitArr[idx]+=delta;
            idx+=idx&(-idx);
        }
    }

    int my_query(int idx){
        idx+=1;
        int result = 0;
        while (idx){
            result += bitArr[idx];
            idx-=idx&(-idx);
        }
        return result;
    }

    int sumRange(int i, int j) {
        return my_query(j)-my_query(i-1);
    }
};
