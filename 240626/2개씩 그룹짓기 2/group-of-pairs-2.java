import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[2*n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0;i<2*n;i++)
            arr[i]=Integer.parseInt(st.nextToken());
        Arrays.sort(arr);
        int min = Integer.MAX_VALUE;
        for(int i=0;i<n;i++)
            min = Math.min(arr[n + i] - arr[i], min);
        System.out.println(min);
    }
}