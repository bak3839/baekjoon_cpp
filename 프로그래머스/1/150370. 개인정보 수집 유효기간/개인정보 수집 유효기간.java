import java.util.*;

class Solution {
    public static int changeDate(String date, String expire) {
        String[] parse = date.split("\\.");
        int ans = 0;
        int term = Integer.parseInt(expire);
        int year = Integer.parseInt(parse[0]);
        int month = Integer.parseInt(parse[1]);
        int day = Integer.parseInt(parse[2]);
        
        year += ((month + term) / 12);
        month = (month + term) % 12;
        
//         if(day == 0) {
//             day = 28;
//             month--;
//             if(month == 0) year--;
//         }
        ans = (year * 10000) + (month * 100) + day;
        System.out.println(ans);
        return ans;
    }
    
    public int[] solution(String today, String[] terms, String[] privacies) {
        // 유효기간 지나면 파기 -> 오늘 날짜에 파기해야 할 개인정보 번호 반환
        int todayNum = changeDate(today, "0");
        ArrayList<Integer> res = new ArrayList<>();
        HashMap<String, String> map = new HashMap<>();
        
        for(String s : terms) {
            String[] parse = s.split(" ");
            map.put(parse[0], parse[1]);
        }
        
        int num = 1;
        for(String privacy : privacies) {
            String[] parse = privacy.split(" ");
            int expiredDate = changeDate(parse[0], map.get(parse[1]));
            
            if(expiredDate <= todayNum) {
                res.add(num);
            }
            num++;
        }
        
        return res.stream().mapToInt(n -> n).toArray();
    }
}