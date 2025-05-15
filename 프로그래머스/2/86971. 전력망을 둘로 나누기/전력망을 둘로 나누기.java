import java.util.*;

class Solution {
    int start, end, ans;
    boolean[] visited;
    List<List<Integer>> graph = new ArrayList<>();
    
    public int dfs(int now, int v1, int v2) {
        int cnt = 1;
        visited[now] = true;
        
        for(int i = 0; i < graph.get(now).size(); i++) {
            int next = graph.get(now).get(i);
            if(visited[next]) continue;
            if((now == v1 && next == v2) || (now == v2 && next == v1)) continue;
            
            cnt += dfs(next, v1, v2);
        }
        
        return cnt;
    }
    
    public int solution(int n, int[][] wires) {
        ans = n;
        visited = new boolean[n + 1];
        
        for(int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }
        
        for(int i = 0; i < n - 1; i++) {
            int v1 = wires[i][0];
            int v2 = wires[i][1];
            
            graph.get(v1).add(v2);
            graph.get(v2).add(v1);
        }
        
        for(int i = 0; i < n - 1; i++) {
            Arrays.fill(visited, false);
            int cnt = dfs(1, wires[i][0], wires[i][1]);
            ans = Math.min(ans, Math.abs((cnt - (n - cnt))));
        }
        
        return ans;
    }
}