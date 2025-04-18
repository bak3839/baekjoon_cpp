import java.util.*;

class Solution {
    public int solution(String[] friends, String[] gifts) {
        int len = friends.length, ans = 0;
        int[] count = new int[len]; // 선물지수
        int[][] giftLog = new int[len][len]; // 서로 주고 받은 선물 내역
        HashMap<String, Integer> names = new HashMap<>();
        
        for(int i = 0; i < len; i++) {
            names.put(friends[i], i);
        }
        
        for(String gift : gifts) {
            StringTokenizer parse = new StringTokenizer(gift);
            String from = parse.nextToken(), to = parse.nextToken();
            int fromIdx = names.get(from), toIdx = names.get(to);
            
            count[fromIdx]++;
            count[toIdx]--;
            giftLog[fromIdx][toIdx]++;
        }
        
        for(int i = 0; i < len; i++) {
            int res = 0;
            
            for(int j = 0; j < len; j++){
                if(i == j) continue;
                
                if(giftLog[i][j] > giftLog[j][i]) res++;
                else if(giftLog[i][j] == giftLog[j][i]) {
                    if(count[i] > count[j]) res++;
                }
            }
            
            ans = Math.max(ans, res);
        }
        
        return ans;
    }
}