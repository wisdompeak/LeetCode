#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;

typedef tree<
pair<int, string> ,
null_type,
less<pair<int, string>>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

class SORTracker {
    ordered_set Set;
    int i = 0;
public:
    SORTracker() 
    {
    }
    
    void add(string name, int score) 
    {
        Set.insert({-score, name});
    }
    
    string get() 
    {
        i++;
        return Set.find_by_order(i-1)->second;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */
