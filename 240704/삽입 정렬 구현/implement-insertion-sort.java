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
        for(int i=1;i<n;i++) {
            int j = i - 1;
            int key = arr[i];
            while(j>=0 && arr[j]>key) {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1]=key;
        }
        for(int i=0;i<n;i++)
            System.out.print(arr[i]+" ");
    }
}