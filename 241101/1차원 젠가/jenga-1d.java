import java.io.*;
import java.util.*;

public class Main {
    // 변수 선언
    public static int n;
    public static int[] jenga;

    // 제거할 범위에 따라 블럭을 빼주는 함수
    public static void deleteBlock(int s, int e) {
        int length = n-(e-s+1);
        int[] temp = new int[length];
        int idx = 0;
        for(int i=0;i<n;i++) {
            if(s<=i&&i<=e)
                continue;
            temp[idx++]=jenga[i];
        }
        jenga=temp;
        n=length;
    }

    public static void main(String[] args) throws IOException {
        // 입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        jenga = new int[n];

        for(int i=0;i<n;i++)
            jenga[i]=Integer.parseInt(br.readLine());

        // 로직

        for(int i=0;i<2;i++) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            deleteBlock(s-1,e-1);
        }

        System.out.println(n);
        for(int i=0;i<n;i++) {
            System.out.println(jenga[i]);
        }

    }
}