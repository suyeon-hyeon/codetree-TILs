import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = 7;
        int[] arr = new int[n];
        arr[0] = Integer.parseInt(st.nextToken());
        int a = arr[0], b = arr[0], abc = arr[0];
        for(int i=1;i<n;i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            if(a>arr[i]) {
                b = a;
                a = arr[i];
            } else {
                b = Math.min(b,arr[i]);
            }
            abc = Math.max(abc,arr[i]);
        }
        int c = abc-a-b;
        System.out.print(a+" "+b+" "+c);
    }
}