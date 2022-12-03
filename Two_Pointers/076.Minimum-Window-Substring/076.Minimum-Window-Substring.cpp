class Solution {
    public :
        string minWindow(string s, string t) {
            unordered_map<char, int > mp ; 
            for(auto i : t){
                mp[i]++; 
            }
            int i = 0 ;
            int j = 0 ; 
            int count = mp.size(); 
            int len = INT_MAX ; 
            int ansStart = 0 ; 
            string ans = ""; 
            while ( j <s.size()){
                mp[s[j]]--; 
                if(mp[s[j]]==0){
                    count--; 
                }
                while(count==0){
                    if( len > j -i +1){
                        len = j-i+1; 
                        ansStart = i ;  
                    }
                    mp[s[i]]++; 
                    if ( mp[s[i]]>0){
                        count++; 
                    }
                    i++; 
                }
                j++; 
            }
            if ( len == INT_MAX) return ""; 
            return s.substr(ansStart , len); 
        }
};
