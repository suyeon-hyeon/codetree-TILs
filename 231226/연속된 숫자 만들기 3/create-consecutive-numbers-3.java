import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int pos[] = new int[3];
		pos[0]=Integer.parseInt(st.nextToken());
		pos[1]=Integer.parseInt(st.nextToken());
		pos[2]=Integer.parseInt(st.nextToken());
		Arrays.sort(pos);

		int ans = -1;
		if(pos[1]-pos[0]>pos[2]-pos[1]) {
			ans = pos[1]-pos[0]-1;
		} else {
			ans = pos[2]-pos[1]-1;
		}
		System.out.println(ans);
	}
}