import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // 식빵 개수 n과 레시피 암호문 개수 m
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        // 식빵 알파벳
        String[] alpha = br.readLine().split("");
        LinkedList<String> list = new LinkedList<>(Arrays.asList(alpha).subList(0, n));
        // 레시피
        ListIterator<String> it = list.listIterator(list.size());
        for(int i=0;i<m;i++) {
            st = new StringTokenizer(br.readLine());
            char recipe = st.nextToken().charAt(0);
            switch (recipe) {
                case 'L':
                    if(it.hasPrevious())
                        it.previous();
                    break;
                case 'R':
                    if(it.hasNext())
                        it.next();
                    break;
                case 'D':
                    if(it.hasNext()){
                        it.next();
                        it.remove();
                    }
                    break;
                case 'P':
                    it.add(st.nextToken());
            }
        }
        // 출력
        while(!list.isEmpty()) {
            System.out.print(list.pollFirst());
        }
    }
}