import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        // Queue
        Queue<Integer> queue = new LinkedList<>();
        for(int i=0;i<n;i++)
            queue.add(i+1);
        int[] ans = new int[n];
        int idx = 0;
        while(!queue.isEmpty()) {
            for(int i=1;i<k;i++) {
                queue.add(queue.peek());
                queue.poll();
            }
            ans[idx++] = queue.poll();
        }
        for(int i=0;i<n;i++) {
            System.out.print(ans[i]+" ");
        }
    }
}