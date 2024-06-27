import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = 15;
        int[] num = new int[n];
        for(int i=0;i<n;i++)
            num[i] = Integer.parseInt(st.nextToken());
        Arrays.sort(num);
        int a, b, c, d;
        a = num[0];
        b = num[1];
        c = num[2];
        d = num[n-1]-a-b-c;
        System.out.println(a+" "+b+" "+c+" "+d);
    }
}