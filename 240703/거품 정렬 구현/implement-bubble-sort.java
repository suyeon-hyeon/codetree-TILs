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
        boolean sorted;
        for(int i=0;i<n-1;i++){
            sorted = true;
            for(int j=0;j<n-1;j++) {
                if(arr[j]>arr[j+1]) {
                    int tmp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = tmp;
                    sorted = false;
                }
            }
            if(sorted)
                break;
        }
        for(int i=0;i<n;i++)
            System.out.print(arr[i]+" ");
    }
}