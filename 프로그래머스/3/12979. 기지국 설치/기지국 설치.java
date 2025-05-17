import java.util.*;

class Solution {
    public int solution(int n, int[] stations, int w) {
        int ans = 0;
        double res;
        
        int prev = 0;
        for(int station : stations) {
            int a = (station - w - 1) - prev;
            res = (double) a / (double) (w * 2 + 1);
            prev = station + w;
            ans += Math.ceil(res);
        }
        res = (double) (n - prev) / (double)(w * 2 + 1);
        ans += Math.ceil(res);
        
        return ans;
    }
}