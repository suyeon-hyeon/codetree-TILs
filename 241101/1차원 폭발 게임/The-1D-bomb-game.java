import java.io.*;
import java.util.*;

public class Main {
    // 변수 선언
    public static int n;
    public static int m;
    public static int[] arr;

    // m개 이상 연속으로 나오면 터진 후 가라앉는 함수
    public static void arrBomb() {
        // 연속으로 나오면 터짐
        boolean isBomb = false;
        int cnt = 1;
        int length = n;
        for(int i=1;i<n;i++) {
            if(arr[i]==arr[i-1]) {
                cnt++;
            } else {
                if(cnt>=m) {
                    for(int j=1;j<=cnt;j++) {
                        arr[i-j]=0;
                    }
                    length=n-cnt;
                    isBomb=true;
                }
                cnt = 1;
            }
        }
        if(cnt>=m) {
            for(int i=1;i<=cnt;i++) {
                arr[n-i]=0;
            }
            length=n-cnt;
            isBomb=true;
        }

        if(!isBomb)
            return;

        // 가라앉기
        int[] temp = new int[length];
        int idx = 0;
        for(int i=0;i<n;i++) {
            if(arr[i]==0)
                continue;
            temp[idx++] = arr[i];
        }
        arr=temp;
        n=length;

        arrBomb();
    }

    public static void main(String[] args) throws IOException {
        // 입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        arr = new int[n];

        for(int i=0;i<n;i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        // 로직

        arrBomb();

        System.out.println(n);
        for(int i=0;i<n;i++) {
            System.out.println(arr[i]+" ");
        }

    }
}