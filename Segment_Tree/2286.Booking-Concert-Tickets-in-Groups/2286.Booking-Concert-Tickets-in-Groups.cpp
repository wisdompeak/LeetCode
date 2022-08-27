using LL = long long;

class SegTreeNode
{
    public:
    SegTreeNode* left = NULL;
    SegTreeNode* right = NULL;
    int start, end;
    int info;  // the max height of the range
    bool tag; 
        
    SegTreeNode(int a, int b, int val)  // init for range [a,b]
    {                 
        tag = 0;
        start = a, end = b;
        if (a==b)
        {
            info = val;
            return;
        }        
        int mid = (a+b)/2;
        if (left==NULL)
        {
            left = new SegTreeNode(a, mid, val);
            right = new SegTreeNode(mid+1, b, val);            
            info = max(left->info, right->info);  // write your own logic
        }        
    }    
    
    void pushDown()
    {
        if (tag==1 && left)
        {
            left->info = info;
            right->info = info;
            left->tag = 1;
            right->tag = 1;
            tag = 0;
        }        
    } 
    
    void updateRange(int a, int b, int val)
    {        
        if (b < start || a > end ) // no intersection
            return;
        
        if (a <= start && end <=b)
        {
            info = val;
            tag = 1;
            return;
        }

        if (left)
        {
            pushDown();        
            left->updateRange(a, b, val);
            right->updateRange(a, b, val);
            info = max(left->info, right->info);  // write your own logic            
        }        
    }
    
    int queryRange(int a, int b)
    {
        if (b < start || a > end )
        {
            return INT_MIN;  // write your own logic
        }
        if (a <= start && end <=b)
        {
            return info;  // write your own logic
        }          
        
        if (left)
        {
            pushDown();     
            int ret = max(left->queryRange(a, b), right->queryRange(a, b));        
            info = max(left->info, right->info);
            return ret;
        }
        
        return info;          
    }  

};


class SegTreeNode2
{
    public:
    SegTreeNode2* left = NULL;
    SegTreeNode2* right = NULL;
    int start, end;
    LL info;  // the sum value over the range
    bool lazy_tag; 
    LL lazy_val;
        
    SegTreeNode2(int a, int b, int val)  // init for range [a,b] with val
    {                 
        lazy_tag = 0;
        lazy_val = 0;
        start = a, end = b;
        if (a==b)
        {
            info = val;
            return;
        }        
        int mid = (a+b)/2;
        if (left==NULL)
        {
            left = new SegTreeNode2(a, mid, val);
            right = new SegTreeNode2(mid+1, b, val);            
            info = left->info + right->info;  // check with your own logic
        }        
    }    
    
    void pushDown()
    {
        if (lazy_tag==1 && left)
        {
            left->info = lazy_val * (left->end - left->start + 1);
            right->info = lazy_val * (right->end - right->start + 1);
            left->lazy_tag = 1; left->lazy_val = lazy_val;
            right->lazy_tag = 1; right->lazy_val = lazy_val;
            lazy_tag = 0;  lazy_val = 0;
        }        
    } 
    
    void updateRange(int a, int b, int val)     // set range [a,b] with val
    {        
        if (b < start || a > end ) // not covered by [a,b] at all
            return;        
        if (a <= start && end <=b)  // completely covered within [a,b]
        {
            info = val * (end-start+1);
            lazy_tag = 1;
            lazy_val = val;
            return;
        }

        if (left)
        {
            pushDown();        
            left->updateRange(a, b, val);
            right->updateRange(a, b, val);
            info = left->info + right->info;  // write your own logic            
        }        
    }
    
    LL queryRange(int a, int b)     // query the sum over range [a,b]
    {
        if (b < start || a > end )
        {
            return 0;  // check with your own logic
        }
        if (a <= start && end <=b)
        {
            return info;  // check with your own logic
        }          
        
        if (left)
        {
            pushDown();     
            LL ret = left->queryRange(a, b) + right->queryRange(a, b);        
            info = left->info + right->info;    // check with your own logic
            return ret;
        }
        
        return info;   // should not reach here
    }  
};

class BookMyShow {
    int n,m;
    vector<int>seats;
    int p = 0;
    SegTreeNode* root;
    SegTreeNode2* root2;


public:
    BookMyShow(int n, int m) {
        this->n = n;
        this->m = m;
        seats.resize(n);        
        for (int i=0; i<n; i++)
        {
            seats[i] = m;
        }

        root = new SegTreeNode(0, n-1, m);        
        root2 = new SegTreeNode2(0, n-1, m);        
    }
    
    vector<int> gather(int k, int maxRow) 
    {                        
        int l = 0, r = maxRow;
        while (l<r)
        {
            int mid = l+(r-l)/2;
            if (root->queryRange(0, mid) >= k )
                r = mid;
            else
                l = mid+1;            
        }
        
        if (root->queryRange(0, l) < k )
            return {};
        
        seats[l] -= k;
        root->updateRange(l, l, seats[l]);
        root2->updateRange(l, l, seats[l]);
        
        return {l,m-(seats[l]+k)};
    }
    
    bool scatter(int k, int maxRow) 
    {
        if (root2->queryRange(0, maxRow) < k)
            return false;
        
        while (k>0)
        {
            int t = min(k, seats[p]);
            seats[p] -= t;            
            root->updateRange(p, p, seats[p]);
            root2->updateRange(p, p, seats[p]);
            k -= t;
            if (seats[p]==0) p++;
        }
        
        return true;
    }
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */
