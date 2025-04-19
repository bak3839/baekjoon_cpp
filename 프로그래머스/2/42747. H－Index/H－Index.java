import java.util.*;

class Solution {
    public int solution(int[] citations) {
        int len = citations.length, ans = len;
        Arrays.sort(citations);
        
        for(int i = 0; i < len; i++) {
            int c = citations[i];
            
            if(c >= ans) break;
            ans--;
        }
        
        return ans;
    }
}