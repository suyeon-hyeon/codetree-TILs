import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        // 음수 양수 갯수 및 음수 양수 값
        int minus = 0, plus = 0;
        int minusVal[] = new int[n];
        int plusVal[] = new int[n];
        // 입력
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            int num = Integer.parseInt(st.nextToken());
            if (num < 0) {
                minusVal[minus] = num;
                minus++;
            } else {
                plusVal[plus] = num;
                plus++;
            }
        }

        int ans = 1;
        // 3개일때
        if (n == 3) {
            for (int i = 0; i < minus; i++)
                ans *= minusVal[i];
            for (int i = 0; i < plus; i++)
                ans *= plusVal[i];
        }
        // 4개 이상일 경우
        else {
            // 음수가 1개 이하일 경우
            if (minus <= 1) {
                // 양수 1,2,3순위 곱
                int first = 0;
                int second = 0;
                int third = 0;
                for (int i = 0; i < plus; i++) {
                    if (first <= plusVal[i]) {
                        third = second;
                        second = first;
                        first = plusVal[i];
                    } else if (second <= plusVal[i]) {
                        third = second;
                        second = plusVal[i];
                    } else if (third < plusVal[i]) {
                        third = plusVal[i];
                    }
                }
                ans = first * second * third;
            }
            // 음수가 2개 이상 & 양수가 0개일 경우
            else if (plus == 0) {
                // 음수 1,2,3순위 곱
                int first = Integer.MIN_VALUE;
                int second = Integer.MIN_VALUE;
                int third = Integer.MIN_VALUE;
                for (int i = 0; i < minus; i++) {
                    if (first <= minusVal[i]) {
                        third = second;
                        second = first;
                        first = minusVal[i];
                    } else if (second <= minusVal[i]) {
                        third = second;
                        second = minusVal[i];
                    } else if (third < minusVal[i]) {
                        third = minusVal[i];
                    }
                }
                ans = first * second * third;
            }
            // 음수가 2개 이상 & 양수가 2개 이하
            else if (plus < 3) {
                // 양수 1순위 큰 수 * (음수 작은 1,2순위)
                int plus_first = 0;
                int minus_first = 0;
                int minus_second = 0;
                for (int i = 0; i < plus; i++) {
                    plus_first = Math.max(plus_first, plusVal[i]);
                }
                for (int i = 0; i < minus; i++) {
                    if (minus_first >= minusVal[i]) {
                        minus_second = minus_first;
                        minus_first = minusVal[i];
                    } else if (minus_second > minusVal[i]) {
                        minus_second = minusVal[i];
                    }
                }
                ans = plus_first * minus_first * minus_second;
            }
            // 음수가 2개 이상 & 양수가 3개 이상일 경우
            else {
                // 양수 1순위 큰 수 * (양수 2,3순위 곱 OR 음수 작은 1,2순위)
                int plus_first = 0;
                int plus_second = 0;
                int plus_third = 0;
                int minus_first = 0;
                int minus_second = 0;
                for (int i = 0; i < plus; i++) {
                    if (plus_first <= plusVal[i]) {
                        plus_third = plus_second;
                        plus_second = plus_first;
                        plus_first = plusVal[i];
                    } else if (plus_second <= plusVal[i]) {
                        plus_third = plus_second;
                        plus_second = plusVal[i];
                    } else if (plus_third < plusVal[i]) {
                        plus_third = plusVal[i];
                    }
                }
                for (int i = 0; i < minus; i++) {
                    if (minus_first >= minusVal[i]) {
                        minus_second = minus_first;
                        minus_first = minusVal[i];
                    } else if (minus_second > minusVal[i]) {
                        minus_second = minusVal[i];
                    }
                }
                int max = Math.max(plus_second * plus_third, minus_first * minus_second);
                ans = plus_first * max;
            }
        }
        System.out.println(ans);
    }
}