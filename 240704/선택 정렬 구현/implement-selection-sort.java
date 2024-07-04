import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // n개의 원소
        int n = Integer.parseInt(br.readLine());
        // 원소 값
        int[] arr = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0;i<n;i++)
            arr[i] = Integer.parseInt(st.nextToken());
        for(int i=0;i<n-1;i++) {
            int min = i;
            for(int j=i+1;j<n;j++)
                min = arr[j]<arr[min]?j:min;
            if(min!=i) {
                int tmp = arr[i];
                arr[i] = arr[min];
                arr[min] = tmp;
            }
        }
        for(int i=0;i<n;i++)
            System.out.print(arr[i]+" ");
    }
}