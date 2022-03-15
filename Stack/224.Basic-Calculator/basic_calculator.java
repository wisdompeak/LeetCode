class Solution {
    public int calculate(String s) {
        
        StringBuilder sb = new StringBuilder();
        sb.append("+");
        for(char c: s.toCharArray()){
            if(c == ' ') continue;
            sb.append(c);
            if(c == '('){
                sb.append("+");
            }
        }
        Deque<Integer> nums = new ArrayDeque<>();
        Deque<Integer> signs = new ArrayDeque<>();
        int sum = 0;
        int sign = 0;
        
        for(int i = 0; i < sb.length(); i++){
            if(sb.charAt(i) == '+' || sb.charAt(i) == '-'  ){
                sign = sb.charAt(i) == '+' ? 1 : -1;
            }else if(Character.isDigit(sb.charAt(i))){
                int cur = 0;
                int j = i;
                while(j < sb.length() && Character.isDigit(sb.charAt(j))){
                    cur = cur * 10 + (sb.charAt(j) - '0');
                
                    j+=1;
                }
                i = j-1;
                sum += cur * sign;
            }else if(sb.charAt(i) == '('){
                nums.addFirst(sum);
                signs.addFirst(sign);
                sum = 0;
            }else if(sb.charAt(i) == ')'){
                sum =  nums.pollFirst() + signs.pollFirst() * sum;
                
            }
        }
    
        return sum;
    }
}
