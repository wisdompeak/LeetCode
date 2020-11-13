#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;

typedef tree<
pair<long,int> ,
null_type,
less<pair<long,int>>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;


class Solution {
public:
    int reversePairs(vector<int>& nums) 
    {
        int ret = 0;
        ordered_set Set;
        for (int j=0; j<nums.size(); j++)        
        {
            int k = Set.order_of_key({(long)nums[j]*2+1,0});
            ret += j - k;
            Set.insert({nums[j],j});
        }
        return ret;

    }
};
