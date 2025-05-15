import java.util.*;

class Solution {
    boolean[] visited;
    HashSet<Integer> primes = new HashSet<>();
    
    public boolean checkPrime(int num) {
        for(int i = 2; i <= (int)Math.sqrt(num); i++) {
            if(num % i == 0) return false;
        }
        
        return true;
    }
    
    public void search(String numbers, int len, int target, StringBuilder sb) {
        if(sb.length() == target) {
            int num = Integer.parseInt(sb.toString());
            if(num > 1 && checkPrime(num)) {
                primes.add(num);
            }
            return;
        }
        
        for(int i = 0; i < len; i++) {
            if(visited[i]) continue;
            
            visited[i] = true;
            sb.append(numbers.charAt(i));
            
            search(numbers, len, target, sb);
            
            visited[i] = false;
            sb.deleteCharAt(sb.length() - 1);
        }
    }
    
    public int solution(String numbers) {
        int answer = 0;
        int len = numbers.length();
        visited = new boolean[len];
        
        for(int i = 1; i <= len; i++) {
            search(numbers, len, i, new StringBuilder());
        }
        return primes.size();
    }
}