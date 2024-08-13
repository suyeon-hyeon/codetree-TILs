import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        // Queue
        Deque<Integer> deque = new ArrayDeque<>();
        for(int i=0;i<n;i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String cmd = st.nextToken();
            if (cmd.equals("push_front")) {
                deque.addFirst(Integer.parseInt(st.nextToken()));
            } else if (cmd.equals("push_back")) {
                deque.addLast(Integer.parseInt(st.nextToken()));
            } else if (cmd.equals("pop_front")) {
                System.out.println(deque.pollFirst());
            } else if (cmd.equals("pop_back")) {
                System.out.println(deque.pollLast());
            } else if (cmd.equals("size")) {
                System.out.println(deque.size());
            } else if (cmd.equals("empty")) {
                System.out.println(deque.isEmpty()?1:0);
            } else if (cmd.equals("front")) {
                System.out.println(deque.peekFirst());
            } else if (cmd.equals("back")) {
                System.out.println(deque.peekLast());
            }
        }
    }
}