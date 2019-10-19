import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class MainShaker {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System. in);
		int N = scanner.nextInt();
		List<Integer> tab = new ArrayList<>();
		
		for(int i = 0; i < N; i++) {
			tab.add(scanner.nextInt());
		}
		
		Collections.sort(tab);
		
		int a = 0, b = 0, c = 0, mini = -1;
		boolean first = true;
		
		for(int i = 0; i < N - 2; i++) {
			if(first || tab.get(i + 2) - tab.get(i) < mini) {
				first = false;
				a = tab.get(i);
				b = tab.get(i + 1);
				c = tab.get(i + 2);
				mini = tab.get(i + 2) - tab.get(i);
			}
		}
		
		System.out.println(a + " " + b + " " + c);
		
		scanner.close();
	}
}
