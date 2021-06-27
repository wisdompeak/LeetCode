class MovieRentingSystem {
    unordered_map<int, set<array<int,2>>>left;  // movie -> {price, shop}
    set<array<int,3>>rented; // {price, shop, movie}
    unordered_map<int, unordered_map<int,int>> prices; // prices[shop][movie]
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) 
    {
        for (auto entry: entries)
        {            
            int shop, movie, price;
            shop = entry[0], movie=entry[1], price=entry[2];
            left[movie].insert({price, shop});
            prices[shop][movie] = price;
        }
    }
    
    vector<int> search(int movie) 
    {
        vector<int>ret;
        auto iter = left[movie].begin();
        for (int i=0; i<5; i++)
        {
            if (iter == left[movie].end())
                break;
            ret.push_back((*iter)[1]);
            iter = next(iter,1);
        }
        return ret;
    }
    
    void rent(int shop, int movie) 
    {
        rented.insert({prices[shop][movie], shop, movie});
        left[movie].erase({prices[shop][movie], shop});
    }
    
    void drop(int shop, int movie) 
    {
        rented.erase({prices[shop][movie], shop, movie});
        left[movie].insert({prices[shop][movie], shop});
    }
    
    vector<vector<int>> report() 
    {
        vector<vector<int>>ret;
        auto iter = rented.begin();
        for (int i=0; i<5; i++)
        {
            if (iter==rented.end()) break;
            ret.push_back({(*iter)[1], (*iter)[2]});
            iter = next(iter);
        }
        return ret;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
