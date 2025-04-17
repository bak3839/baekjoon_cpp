import java.util.*;

class Pair {
    int x, y, cnt;
    Pair(int x, int y, int cnt) {
        this.x = x;
        this.y = y;
        this.cnt = cnt;
    }
}

class Solution {
    int mv[][] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    public int BFS(int[][] maps) {
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(0, 0, 1));
        maps[0][0] = 0;
        
        int ex = maps.length, ey = maps[0].length;
        
        while(!q.isEmpty()) {
            int x = q.peek().x;
            int y = q.peek().y;
            int cnt = q.peek().cnt;
            q.remove();
            
            if(x == ex - 1 && y == ey - 1) return cnt;
            
            for(int i = 0; i < 4; i++) {
                int nx = x + mv[i][0];
                int ny = y + mv[i][1];
                
                if(nx < 0 || ny < 0 || nx >= ex || ny >= ey) continue;
                if(maps[nx][ny] == 0) continue;
                
                maps[nx][ny] = 0;
                q.add(new Pair(nx, ny, cnt + 1));
            }
        }
        
        return -1;
    }
    
    public int solution(int[][] maps) {
        return BFS(maps);
    }
}