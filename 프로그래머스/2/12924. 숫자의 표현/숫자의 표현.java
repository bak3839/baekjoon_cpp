class Solution {
    public int solution(int n) {
        int answer = 0, L = 1, R = 1, sum = 1;
        
        while(L <= R && R <= n) {
            if(sum == n) {
                answer++;
                sum -= L++;
                sum += ++R;
            } else if(sum < n) {
                sum += ++R;
            } else {
                sum -= L++;
            }
        }
        
        return answer;
    }
}