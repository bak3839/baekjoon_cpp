import java.util.*;

class Solution {
    int[] ans;
    int baseTime, basePrice, unitTime, unitPrice;
    HashMap<String, Integer> times = new HashMap<>();
    HashMap<String, Integer> parking = new HashMap<>();
    
    public int[] solution(int[] fees, String[] records) {
        baseTime = fees[0]; basePrice = fees[1];
        unitTime = fees[2]; unitPrice = fees[3];
        
        for(String record : records) {
            StringTokenizer st = new StringTokenizer(record);
            String time = st.nextToken();
            String num = st.nextToken();
            String type = st.nextToken();
            
            st = new StringTokenizer(time, ":");
            int h = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int nowTime = (h * 60) + m;
            
            if(type.equals("IN")) {
                parking.put(num, nowTime);
            } else {
                int inTime = parking.get(num);
                int total = times.getOrDefault(num, 0);
                times.put(num, total + (nowTime - inTime));
                parking.remove(num);
            }
        }
        
        parking.forEach((num, inTime) -> {
            int nowTime = (23 * 60) + 59;
            int total = times.getOrDefault(num, 0);
            times.put(num, total + (nowTime - inTime));
        });
        
        int[] ans = new int[times.size()];
        List<String> keys = new ArrayList<>(times.keySet());
        Collections.sort(keys);
        
        for(int i = 0; i < keys.size(); i++) {
            int total = times.get(keys.get(i));
            
            ans[i] = basePrice;
            
            if(total > baseTime) {
                ans[i] += Math.ceil((double)(total - baseTime) / unitTime) * unitPrice;
            }
        }
        
        return ans;
    }
}