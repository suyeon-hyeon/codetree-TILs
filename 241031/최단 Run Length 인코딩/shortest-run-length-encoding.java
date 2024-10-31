import java.io.*;
import java.util.*;

public class Main {
    // 변수 선언
    public static char[] alpha;

    // 오른쪽 shift 하는 함수
    public static void shiftRight() {
        int length = alpha.length;
        char temp = alpha[length-1];
        for(int i=length-1;i>=1;i--)
            alpha[i]=alpha[i-1];
        alpha[0]=temp;
    }

    // Run Length 엔코딩 길이 함수
    public static int runLengthEncodingLength() {
        int totalCnt = 2;
        int cnt = 1;
        int length = alpha.length;
        for(int i=1;i<length;i++) {
            if(alpha[i]!=alpha[i-1]) {
                totalCnt+=2;
                while(cnt/10!=0) {
                    totalCnt++;
                    cnt/=10;
                }
                cnt=1;
            } else {
                cnt++;
            }
        }
        while(cnt/10!=0) {
            totalCnt++;
            cnt /= 10;
        }
        return totalCnt;
    }

    // 최단 Run Length 인코딩 함수
    public static int runLengthEncodingMin() {
        int min = runLengthEncodingLength();

        for(int i=0;i<alpha.length-1;i++) {
            shiftRight();
            min = Math.min(min,runLengthEncodingLength());
        }
        return min;
    }

    public static void main(String[] args) throws IOException {
        // 입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        alpha = br.readLine().toCharArray();

        // 로직
        int ans = runLengthEncodingMin();
        System.out.println(ans);
    }
}