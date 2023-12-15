import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int A = Integer.parseInt(st.nextToken());
		int B = Integer.parseInt(st.nextToken());
		int x = Integer.parseInt(st.nextToken());
		int y = Integer.parseInt(st.nextToken());
		int dis1 = Math.abs(B-A);
		int dis2 = Math.abs(B-y)+Math.abs(A-x);
		int dis3 = Math.abs(A-y)+Math.abs(B-x);
		int min = Math.min(dis1, Math.min(dis2, dis3));
		System.out.println(min);
	}
}