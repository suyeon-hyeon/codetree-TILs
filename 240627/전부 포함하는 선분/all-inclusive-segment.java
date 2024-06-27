import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] left = new int[n];
        int[] right = new int[n];
        for(int i=0;i<n;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            left[i] = Integer.parseInt(st.nextToken());
            right[i] = Integer.parseInt(st.nextToken());
        }
        int length = Integer.MAX_VALUE;
        for(int i=0;i<n;i++){
            int min = Integer.MAX_VALUE, max = 0;
            for(int j=0;j<n;j++){
                if(i==j)
                    continue;
                min = Math.min(min, left[j]);
                max = Math.max(max, right[j]);
            }
            length = Math.min(length, max-min);
        }
        System.out.println(length);
    }
}