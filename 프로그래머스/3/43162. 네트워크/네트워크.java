import java.util.*;

class Solution {
    boolean[] visited;
    List<List<Integer>> graph;
    
    public void DFS(int x) {
        visited[x] = true;
        
        for(Integer next : graph.get(x)) {
            if(visited[next]) continue;
            DFS(next);
        }
    }
    
    public int solution(int n, int[][] computers) {
        int ans = 0;
        graph = new ArrayList<>();
        visited = new boolean[n];
        
        for(int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(computers[i][j] == 0) continue;
                
                graph.get(i).add(j);
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(visited[i]) continue;
            
            ans++;
            DFS(i);
        }
        
        return ans;
    }
}