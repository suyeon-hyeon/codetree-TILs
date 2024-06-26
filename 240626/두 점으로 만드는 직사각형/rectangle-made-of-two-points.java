import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = 4;
        int[] rect1 = new int[n];
        int[] rect2 = new int[n];
        for(int i=0;i<n;i++)
            rect1[i] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for(int i=0;i<n;i++)
            rect2[i] = Integer.parseInt(st.nextToken());
        int x = Math.max(rect1[2],rect2[2])-Math.min(rect1[0],rect2[0]);
        int y = Math.max(rect1[3],rect2[3])-Math.min(rect1[1],rect2[1]);
        System.out.println(x*y);
    }
}