import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
    static String[] nums;
    static int N, maxAnswer = Integer.MIN_VALUE, minAnswer = Integer.MAX_VALUE;
    static int[] operationCounts = new int[4];
    static char[] choiceOperation;
    static char[] operation = {'+', '-', '*', '/'};

    public static void calculate() {
        Stack<Integer> numStack = new Stack<>();
        Stack<Character> operStack = new Stack<>();
        numStack.push(Integer.parseInt(nums[0]));

        for(int i = 0; i < N - 1; i++) {
            int n1 = numStack.peek();
            int n2 = Integer.parseInt(nums[i + 1]);

            if(choiceOperation[i] == '*') {
                numStack.pop();
                numStack.push(n1 * n2);
            } else if(choiceOperation[i] == '/') {
                numStack.pop();
                numStack.push(n1 / n2);
            } else {
                if(!operStack.isEmpty()) {
                    char oper = operStack.pop();
                    int pop1 = numStack.pop();
                    int pop2 = numStack.pop();

                    if(oper == '+') {
                        numStack.push(pop1 + pop2);
                    } else if(oper == '-') {
                        numStack.push(pop2 - pop1);
                    }
                }

                numStack.push(n2);
                operStack.push(choiceOperation[i]);
            }
        }

        while(!operStack.isEmpty()) {
            char oper = operStack.pop();
            int n1 = numStack.pop();
            int n2 = numStack.pop();

            if(oper == '+') {
                numStack.push(n1 + n2);
            } else if(oper == '-') {
                numStack.push(n2 - n1);
            }
        }

        maxAnswer = Math.max(maxAnswer, numStack.peek());
        minAnswer = Math.min(minAnswer, numStack.peek());
    }

    public static void search(int idx) {
        if(idx == N - 1) {
            calculate();
            return;
        }

        for(int i = 0; i < 4; i++) {
            if(operationCounts[i] == 0) continue;

            operationCounts[i]--;
            choiceOperation[idx] = operation[i];
            search(idx + 1);
            operationCounts[i]++;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        nums = new String[N];
        choiceOperation = new char[N - 1];

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) {
            nums[i] = st.nextToken();
        }

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < 4; i++) {
            operationCounts[i] = Integer.parseInt(st.nextToken());
        }

        search(0);
        System.out.println(maxAnswer + "\n" + minAnswer);
    }
}
