import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {

    public static boolean confirm(String input) {
        Stack<Character> stack = new Stack<>();

        for (char ch : input.toCharArray()) {
            if(ch == '(' || ch == '{' || ch == '[') {
                stack.push(ch);
            }
            else if (ch == ')' || ch == '}' || ch == ']') {
                if(stack.isEmpty()) { return false; }

                if(ch == ')' && stack.peek() != '(') { return false; }
                if(ch == '}' && stack.peek() != '{') { return false; }
                if(ch == ']' && stack.peek() != '[') { return false; }

                stack.pop();
            }
        }

        return stack.isEmpty();
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while(true) {
            String input = br.readLine();

            if(input.equals("#")) break;

            if(confirm(input)) {
                System.out.println("Legal");
            } else {
                System.out.println("Illegal");
            }
        }
    }
}
