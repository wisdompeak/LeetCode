using LL = long long;
class Solution {
public:
    LL reverseBits(LL x) {
        LL r = 0;
        while (x>0) {
            r = r*2+(x&1);
            x>>=1;            
        }
        return r;        
    }
    
    LL build(LL half, int L) {
        int h = (L+1)/2;
        int k = L-h;        
        if (L%2==0) {
            return (half<<k) | reverseBits(half);
        } else {
            return (half<<k) | reverseBits(half>>1);
        }
    }
    
    int countBinaryPalindromes(long long n) {
        if (n==0) return 1;
        int maxLen = floor(log2(n)) + 1;

        LL ret = 1;
        for (int L=1; L<maxLen; L++) {
            int h = (L+1)/2;
            long long mn = 1LL<<(h-1);
            long long mx = (1LL<<h)-1;
            ret += mx-mn+1;         
        }
        
        {
            int L = maxLen;
            int h = (L+1)/2;            
            long long mn = 1LL<<(h-1);
            long long mx = (1LL<<h)-1;
            LL lo = mn, hi = mx;
            while (lo < hi) {
                LL mid = hi-(hi-lo)/2;
                LL pal = build(mid, L);
                if (pal <= n) {
                    lo = mid;
                } else {
                    hi = mid-1;
                }
            }
            LL pal = build(hi, L);
            if (pal <= n) 
                ret += (LL)(hi-mn+1);            
        }

        return ret;
    }
};
