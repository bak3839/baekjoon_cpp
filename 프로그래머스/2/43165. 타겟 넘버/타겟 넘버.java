class Solution {
    static int ans = 0;
    
    public void DFS(int sum, int index, int target, int[] numbers) {
        if(index == numbers.length) {
            if(sum == target) ans++;
            return;
        }
        
        DFS(sum + numbers[index], index + 1, target, numbers);
        DFS(sum - numbers[index], index + 1, target, numbers);
    }
    
    public int solution(int[] numbers, int target) {
        DFS(0, 0, target, numbers);
        return ans;
    }
}