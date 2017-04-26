class TwoSum {
    
private:
    unordered_map<int,int>Map;

public:

    // Add the number to an internal data structure.
	void add(int number) 
	{
	    Map[number]++;   
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) 
	{
	    for (auto a:Map)
	    {
	        if (value-a.first!=a.first)
	        {
	           if (Map.find(value-a.first)!=Map.end())
	                return true;;
	        }
	        else if (value-a.first==a.first)
	        {
	            if (a.second>1)
	                return true;
	        }
	    }
	    
	    return false;
	}
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);
