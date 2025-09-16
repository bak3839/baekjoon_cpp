import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static class Box {
        int X, T;

        public Box(int X) {
            this.X = X;
        }

        public void setT(int t) {
            T = t;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        List<Box> boxes = new ArrayList<>();

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            int X = Integer.parseInt(st.nextToken());
            boxes.add(new Box(X));
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            int T = Integer.parseInt(st.nextToken());
            boxes.get(i).setT(T);
        }

        boxes.sort((b1, b2) -> b1.X - b2.X);
        int time = Math.max(boxes.get(boxes.size() - 1).T,  boxes.get(boxes.size() - 1).X);

        for (int i = boxes.size() - 2; i >= 0; i--) {
            time = Math.max(time + boxes.get(i + 1).X - boxes.get(i).X, boxes.get(i).T);
        }
        time += boxes.get(0).X;

        System.out.println(time);
    }
}
