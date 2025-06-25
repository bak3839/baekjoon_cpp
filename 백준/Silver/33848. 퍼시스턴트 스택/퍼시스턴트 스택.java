import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
    static int Q;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        Stack<Integer> stack = new Stack<>();
        Stack<Integer> temp = new Stack<>();
        Stack<Integer> command = new Stack<>();
        Q = Integer.parseInt(br.readLine());

        while(Q-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            int i = Integer.parseInt(st.nextToken()), j;

            if(i == 1) {
                j = Integer.parseInt(st.nextToken());
                stack.push(j);
                command.push(i);
            } else if(i == 2) {
                temp.push(stack.pop());
                command.push(i);
            } else if(i == 3) {
                j = Integer.parseInt(st.nextToken());

                while(j-- > 0) {
                    Integer c = command.pop();

                    if(c == 1) {
                        stack.pop();
                    } else {
                        stack.push(temp.pop());
                    }
                }
            } else if(i == 4) {
                System.out.println(stack.size());
            } else {
                System.out.println(stack.isEmpty() ? "-1" : stack.peek());
            }
        }
    }
}
