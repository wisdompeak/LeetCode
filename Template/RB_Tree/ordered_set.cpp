#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;

typedef tree<
int ,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

// find_by_order(k) returns an iterator to the k-th largest element (counting from zero), 
// order_of_key(x) returns the number of items in a set that are strictly smaller than x; or equivlently, the index of the first item greater or equal to x
    
    
int main() {
    ordered_set Set;    
    vector<int>nums({1,3,2,2,4,4,8,6,7,3});
    for (int i=0; i<nums.size(); i++)
    {
        Set.insert(nums[i]);
        cout<<nums[i]<<":"<<Set.order_of_key(nums[i])<<endl;
    }    
}
// If you want to make it like a multiset, you may design the base type of the ordered_set as pair<int,int>
