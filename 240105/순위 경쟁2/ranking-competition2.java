import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int A = 0, B = 0; // A, B 점수
        int pre = 0, cur = 0; // A,B : 0 / A : -1 / B : 1
        int cnt = 0; // 바뀐 횟수
        for (int i = 0; i < n; i++) {
            // 누가 점수를 얻었는지 입력
            StringTokenizer st = new StringTokenizer(br.readLine());
            char who = st.nextToken().charAt(0);
            int score = Integer.parseInt(st.nextToken());
            // 입력에 따른 점수 갱신
            if (who == 'A')
                A += score;
            else
                B += score;
            // 상태 갱신
            if (A == B)
                cur = 0;
            else if (A > B)
                cur = -1;
            else
                cur = 1;
            // 상태 변경 시 카운트
            if (pre != cur) {
                cnt++;
                pre = cur;
            }
        }
        System.out.println(cnt);
    }
}