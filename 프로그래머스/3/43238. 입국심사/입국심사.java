import java.util.*;

class Solution {
    public long solution(int n, int[] times) {
        long ans = (long) Arrays.stream(times).max().getAsInt() * n + 1;
        long L = 1, R = ans;
        
        while(L <= R) {
            long cnt = 0;
            long mid = (L + R) / 2;
            
            for(int t : times) {
                cnt += mid / t;
            }
            
            if(cnt >= n) {
                ans = Math.min(ans, mid);
                R = mid - 1;
            } else L = mid + 1;
        }
        
        return ans;
    }
}