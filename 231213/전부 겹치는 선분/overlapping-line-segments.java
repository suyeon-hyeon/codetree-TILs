import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
//        int[] start = new int[n];
//        int[] end = new int[n];
        int maxStart = 0;
        int minEnd = Integer.MAX_VALUE;
        for(int i=0;i<n;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
//            start[i] = Integer.parseInt(st.nextToken());
            int start = Integer.parseInt(st.nextToken());
//            end[i] = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            maxStart = Math.max(maxStart,start);
            minEnd = Math.min(minEnd,end);
        }
        if(minEnd<maxStart)
            System.out.println("No");
        else
            System.out.println("Yes");
    }
}