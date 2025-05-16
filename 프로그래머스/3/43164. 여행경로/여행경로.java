import java.util.*;

class Solution {
    int N, size;
    String[] ans;
    boolean finish;
    int[][] visited;
    List<Integer> route = new ArrayList<>();
    List<List<String>> graph = new ArrayList<>();
    HashMap<String, Integer> nums = new HashMap<>();
    HashMap<Integer, String> names = new HashMap<>();
    
    public void dfs(int x, int cnt) {
        if(cnt == size + 1) {
            for(int i = 0; i < route.size(); i++) {
                int num = route.get(i);
                String name = names.get(num);
                ans[i] = name;
            }
            finish = true;
            return;
        }
        
        for(int i = 0; i < graph.get(x).size(); i++) {
            String name = graph.get(x).get(i);
            int next = nums.get(name);
            if(visited[x][next] <= 0) continue;
            
            route.add(next);
            visited[x][next]--;
            dfs(next, cnt + 1);
            route.remove(route.size() - 1);
            visited[x][next]++;
            
            if(finish) return;
        }
    }
    
    public String[] solution(String[][] tickets) {
        String[] answer = {};
        int index = 0;
        
        for(String[] ticket : tickets) {
            String t1 = ticket[0];
            String t2 = ticket[1];
            
            if(!nums.containsKey(t1)) {
                names.put(index, t1);
                nums.put(t1, index++);
            }
            if(!nums.containsKey(t2)) {
                names.put(index, t2);
                nums.put(t2, index++);
            }
        }
        
        N = nums.size();
        size = tickets.length;
        ans = new String[size + 1];
        visited = new int[N][N];
        
        for(int i = 0; i < N; i++) {
            graph.add(new ArrayList<>());
        }
        
        for(String[] ticket : tickets) {
            String t1 = ticket[0];
            String t2 = ticket[1];
            
            int num1 = nums.get(t1);
            int num2 = nums.get(t2);
            visited[num1][num2]++;
            graph.get(num1).add(t2);
        }
        
        int idx = 0;
        for(List<String> list: graph) {
            Collections.sort(list);
        }
        
        int start = nums.get("ICN");
        route.add(start);
        dfs(start, 1);
        
        return ans;
    }
}