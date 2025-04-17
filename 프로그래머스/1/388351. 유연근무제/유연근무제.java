class Solution {
    public int solution(int[] schedules, int[][] timelogs, int startday) {
        int answer = 0;
        int cnt[] = new int[schedules.length];

        for(int i = 0; i < schedules.length; i++) {
            int time = schedules[i];
            int H = time / 100, M = time % 100 + 10;

            if(M >= 60) {
                H++;
                M = M % 60;
            }

            schedules[i] = H * 100 + M;
        }

        for(int i = 0; i < timelogs.length; i++) {
            boolean pass = true;
            int day = startday;
            
            for(int d = 0; d < 7; d++) {
                if(day <= 5) {
                    if(timelogs[i][d] > schedules[i]) {
                        pass = false;
                        break;
                    }
                }
                
                day = day % 7 + 1;
            }        
            
            if(pass) answer++;
        }

        
        return answer;
    }
}