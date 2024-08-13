import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // n개의 원소
        int n = Integer.parseInt(br.readLine());
        Stack<Integer> stack = new Stack<>();
        for(int i=0;i<n;i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String cmd = st.nextToken();
            if (cmd.equals("push")) {
                stack.push(Integer.parseInt(st.nextToken()));
            } else if (cmd.equals("pop")) {
                System.out.println(stack.pop());
            } else if (cmd.equals("size")) {
                System.out.println(stack.size());
            } else if (cmd.equals("empty")) {
                System.out.println(stack.isEmpty()?1:0);
            } else if (cmd.equals("top")) {
                System.out.println(stack.peek());
            }
        }
    }
}