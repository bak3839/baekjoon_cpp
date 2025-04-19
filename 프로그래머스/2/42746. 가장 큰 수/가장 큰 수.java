import java.util.*;

class Solution {
    public String solution(int[] numbers) {
        StringBuilder ans = new StringBuilder();
        
        String[] nums = Arrays.stream(numbers)
            .mapToObj(String::valueOf)
            .toArray(String[]::new);
        
        Arrays.sort(nums, (n1, n2) -> (n2 + n1).compareTo(n1 + n2));
        
        if(nums[0].equals("0")) return "0";
        
        Arrays.stream(nums).forEach(n -> {
            ans.append(n);
        });
        
        return ans.toString();
    }
}