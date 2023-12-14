import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		// 사람 수 , 메세지 정보의 수, 확인할 메세지 번호
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int p = Integer.parseInt(st.nextToken());

		// 메세지 정보 (사람, 읽지않은 사람 수)
		char[] c = new char[m];
		int[] u = new int[m];
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			c[i] = st.nextToken().charAt(0);
			u[i] = Integer.parseInt(st.nextToken());
		}

		boolean[] isRead = new boolean[n];
		for (int i = p - 1; i < n; i++) {
			isRead[c[i] - 'A'] = true;
		}

		StringBuilder ans = new StringBuilder();
		if (u[p - 1] != 0) {
			for (int i = 0; i < n; i++) {
				if (!isRead[i])
					ans.append((char) (i + 'A')).append(" ");
			}
		}
		System.out.println(ans);
	}
}