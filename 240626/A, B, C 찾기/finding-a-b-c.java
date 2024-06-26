import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = 7;
        int[] arr = new int[n];
        int a = Integer.MAX_VALUE, b = -1, abc = 0;
        for(int i=0;i<n;i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            b = a;
            a = Math.min(a,arr[i]);
            abc = Math.max(abc,arr[i]);
        }
        int c = abc-a-b;
        System.out.print(a+" "+b+" "+c);
    }
}