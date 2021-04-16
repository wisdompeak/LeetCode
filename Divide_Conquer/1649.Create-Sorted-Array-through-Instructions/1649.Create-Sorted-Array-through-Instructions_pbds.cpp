#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;

typedef pair<int,int> PII;

typedef tree<
PII ,
null_type,
less<PII>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;


class Solution {
public:
    int createSortedArray(vector<int>& instructions) 
    {
        ordered_set Set;    
        unordered_map<int,int>count;
        long cost = 0;
        long M = 1e9+7;
        for (auto x: instructions)
        {
            int k1 = Set.order_of_key({x, 1});
            int k2 = Set.size() - k1 - count[x];
            cost += min(k1, k2);
            cost %= M; 
            count[x]++;
            Set.insert({x, count[x]});
        }
        return cost;
        
    }
};
