import java.io.*;
import java.util.*;

public class Main {
    // 변수 선언
    public static int n;
    public static int t;

    public static void main(String[] args) throws IOException {
        // 입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        t = Integer.parseInt(st.nextToken());

        int length = 3*n;
        int[] arr = new int[length];

        for(int i=0;i<3;i++) {
            st = new StringTokenizer(br.readLine());
            for(int j=0;j<n;j++){
                arr[i*n+j] = Integer.parseInt(st.nextToken());
            }
        }

        // 로직

        t%=length;
        for(int i=0;i<t;i++) {
            int temp = arr[length-1];
            for(int j=0;j<length-1;j++) {
                arr[length-1-j] = arr[length-2-j];
            }
            arr[0]=temp;
        }

        for(int i=0;i<3;i++) {
            for(int j=0;j<n;j++){
                System.out.print(arr[i*n+j]+" ");
            }
            System.out.println();
        }
    }
}