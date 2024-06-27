import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<Integer> list = new ArrayList<>();
        int n = Integer.parseInt(br.readLine());
        for(int i=0;i<n;i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String order = st.nextToken();
            if(order.equals("push_back")) {
                list.add(Integer.parseInt(st.nextToken()));
            } else if (order.equals("pop_back")) {
                list.remove(list.size()-1);
            } else if (order.equals("size")) {
                System.out.println(list.size());
            } else if (order.equals("get")) {
                System.out.println(list.get(Integer.parseInt(st.nextToken())-1));
            }
        }
    }
}