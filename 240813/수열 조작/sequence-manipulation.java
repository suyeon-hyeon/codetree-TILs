import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        // Deque
        Deque<Integer> deque = new ArrayDeque<>();
        for(int i=0;i<n;i++)
            deque.addLast(i+1);
        while(deque.size() != 1) {
            deque.pollFirst();
            deque.addLast(deque.peekFirst());
            deque.pollFirst();
        }
        System.out.println(deque.pollFirst());
    }
}