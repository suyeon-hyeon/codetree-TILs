import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // n개의 원소
        int n = Integer.parseInt(br.readLine());
        // 원소 값과 최대값의 자릿수
        int[] arr = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        int max = 0;
        for(int i=0;i<n;i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            max = Math.max(max, arr[i]);
        }
        int max_digit = 0;
        while(max>0) {
            max/=10;
            max_digit++;
        }
        // 기수 정렬
        for(int pos=max_digit;pos>=0;pos--) {
            int[][] arr_new = new int[10][n+1];
            for(int i=0;i<n;i++) {
                int digit = arr[i];
                for(int j=0;j<max_digit-pos;j++){
                    digit/=10;
                }
                digit%=10;
                arr_new[digit][0]++;
                arr_new[digit][arr_new[digit][0]] = arr[i];
            }

            int[] store_arr = new int[n];
            int cnt = 0;
            for(int i=0;i<10;i++){
                for(int j=1; j<=arr_new[i][0];j++) {
                    store_arr[cnt++]=arr_new[i][j];
                }
            }

            arr = store_arr;
        }
        for(int i=0;i<n;i++)
            System.out.print(arr[i]+" ");
    }
}