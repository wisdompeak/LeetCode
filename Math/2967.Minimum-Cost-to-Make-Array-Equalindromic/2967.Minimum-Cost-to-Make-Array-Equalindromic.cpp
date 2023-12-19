class Solution {
public:
    long long minimumCost(vector<int>& nums) 
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int m;
        if (n%2==1)
            m = nums[n/2];
        else
            m = (nums[n/2] + nums[n/2-1])/2;
        
        string a = nextSmallerOrEqual(to_string(m));
        string b = nextGreaterOrEqual(to_string(m));

        long long ret = LLONG_MAX;
        ret = min(ret, check(nums, stoll(a)));
        ret = min(ret, check(nums, stoll(b)));
        return ret;        
    }

    long long check(vector<int>& nums, long long p)
    {
        long long sum = 0;
        for (int i=0; i<nums.size(); i++)
            sum += abs(nums[i] - p);
        return sum;
    }

    string nextSmallerOrEqual(string n)
    {
        int m = n.size();
        string s = n;
        for (int i=0, j=m-1; i<=j; )
            s[j--] = s[i++];
        if (s <= n) return s;

        int carry = 1;
        for (int i=(m-1)/2; i>=0; i--)
        {
            int d = s[i] - '0' - carry;
            if (d>=0)
            {
                s[i] = '0' + d;
                carry = 0;
            }
            else
            {
                s[i] = '9';
                carry = 1;
            }
            s[m-1-i] = s[i];
        }

        if (s[0] == '0' && m>1)
            return string(m-1, '9');
        else
            return s;
    }

    string nextGreaterOrEqual(string n)
    {
        int m = n.size();
        string s = n;
        for (int i=0, j=m-1; i<=j; )
            s[j--] = s[i++];
        if (s >= n) return s;

        int carry = 1;
        for (int i=(m-1)/2; i>=0; i--)
        {
            int d = s[i] - '0' + carry;
            if (d<=9)
            {
                s[i] = '0' + d;
                carry = 0;
            }
            else
            {
                s[i] = '0';
                carry = 1;
            }
            s[m-1-i] = s[i];
        }

        if (carry == 1)
        {
            s = string(m+1, '0');
            s[0] = s.back() = '1';
            return s;
        }            
        else
            return s;
    }
};
