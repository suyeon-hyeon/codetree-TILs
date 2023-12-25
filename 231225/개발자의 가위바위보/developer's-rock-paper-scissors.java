import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int rsp[][] = new int[4][4];

		for (int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int user1 = Integer.parseInt(st.nextToken());
			int user2 = Integer.parseInt(st.nextToken());
			rsp[user1][user2]++;
		}
		
		int case1 = rsp[1][2]+rsp[2][3]+rsp[3][1];
		int case2 = rsp[1][3]+rsp[2][1]+rsp[3][2];
		int ans = Math.max(case1, case2);
		System.out.println(ans);
	}
}