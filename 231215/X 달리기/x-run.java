import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int x = Integer.parseInt(br.readLine());
		int speed = 1;
		int time = 0;
		while (x!=0) {
			if (x <= speed*2) {
				if(x<=speed)
					time++;
				else
					time+=2;
				x=0;
			} else {
				x -= speed * 2;
				time += 2;
				speed++;
			}
		}
		System.out.println(time);
	}
}