import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        LinkedList<Integer> list = new LinkedList<>();
        int n = Integer.parseInt(br.readLine());
        for(int i=0;i<n;i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String order = st.nextToken();
            switch (order) {
                case "push_front":
                    list.addFirst(Integer.parseInt(st.nextToken()));
                    break;
                case "push_back":
                    list.addLast(Integer.parseInt(st.nextToken()));
                    break;
                case "pop_front":
                    System.out.println(list.pollFirst());
                    break;
                case "pop_back":
                    System.out.println(list.pollLast());
                    break;
                case "size":
                    System.out.println(list.size());
                    break;
                case "empty":
                    System.out.println(list.isEmpty()?1:0);
                    break;
                case "front":
                    System.out.println(list.getFirst());
                    break;
                case "back":
                    System.out.println(list.getLast());
                    break;
            }
        }
    }
}