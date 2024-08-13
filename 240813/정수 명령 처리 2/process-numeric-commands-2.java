import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // n개의 원소
        int n = Integer.parseInt(br.readLine());
        // Queue
        Queue<Integer> queue = new LinkedList<>();
        for(int i=0; i<n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String cmd = st.nextToken();
            if (cmd.equals("push")) {
                queue.add(Integer.parseInt(st.nextToken()));
            } else if (cmd.equals("pop")) {
                System.out.println(queue.poll());
            } else if (cmd.equals("size")) {
                System.out.println(queue.size());
            } else if (cmd.equals("empty")) {
                System.out.println(queue.isEmpty()?1:0);
            } else if (cmd.equals("front")) {
                System.out.println(queue.peek());
            }
        }
    }
}