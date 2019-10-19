import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class MainShaker {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System. in);
		String M = scanner.nextLine();
		String MSorted = sort(M);
		int N = scanner.nextInt();
		scanner.nextLine();
		List<String> dictionnaireSortie = new ArrayList<>();
		
		for(int i = 0; i < N; i++) {
			String m = scanner.nextLine();
			if(m.charAt(0) == M.charAt(0) && m.charAt(m.length() - 1) == M.charAt(M.length() - 1)) {
				String mSorted = sort(m);
				if(mSorted.equals(MSorted))
					dictionnaireSortie.add(m);
			}
		}

		dictionnaireSortie.sort((String o1, String o2) -> {
				return o1.compareTo(o2);
		});
		
		for(String s : dictionnaireSortie) {
			System.out.println(s);
		}
		
		scanner.close();
	}
	
	private static String sort(String toSort) {
		char[] stringAsArray = toSort.toCharArray();
		Arrays.sort(stringAsArray);
		return new String(stringAsArray);
	}
}
