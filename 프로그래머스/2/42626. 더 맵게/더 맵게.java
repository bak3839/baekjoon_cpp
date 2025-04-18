import java.util.*;

class Solution {
    public int solution(int[] scoville, int K) {
        boolean pass = false;
        int answer = 0;
        PriorityQueue<Long> pq = new PriorityQueue<>();
        Arrays.stream(scoville).forEach(v -> pq.add(Long.valueOf(v)));
        
        while(!pq.isEmpty()) {
            if(pq.peek() >= K) {
                pass = true;
                break;
            }

            Long s1 = pq.poll();
            Long s2 = pq.poll();
            
            if(s2 == null) break;

            pq.add(s1 + s2 * 2);
            
            answer++;
        }
        
        if(!pass) answer = -1; 
        return answer;
    }
}