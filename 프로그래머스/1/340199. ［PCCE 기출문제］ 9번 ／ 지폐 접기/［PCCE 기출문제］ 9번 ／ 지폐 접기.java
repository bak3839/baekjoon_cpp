class Solution {
    public int solution(int[] wallet, int[] bill) {
        int answer = 0;
        int maxLen = Math.max(wallet[0], wallet[1]), maxBill = Math.max(bill[0], bill[1]);
        int minLen = Math.min(wallet[0], wallet[1]), minBill = Math.min(bill[0], bill[1]);
        
        while(maxLen < maxBill || minLen < minBill) {
            if(bill[0] > bill[1]) {
                bill[0] /= 2;
            } else {
                bill[1] /= 2;
            }
            maxBill = Math.max(bill[0], bill[1]);
            minBill = Math.min(bill[0], bill[1]);
            answer++;
        }
        
        return answer;
    }
}