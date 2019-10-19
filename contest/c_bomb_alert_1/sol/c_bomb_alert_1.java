import java.util.ArrayList;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;

public class MainShaker {

	static public double distance(double x1, double y1, double x2, double y2){
		return Math.sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	}
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System. in);
		scanner.useLocale(Locale.US);

		double Xb = scanner.nextDouble();
		double Yb = scanner.nextDouble();

		int N = scanner.nextInt();
		int T = scanner.nextInt();
		int vitesseMax = 100;
		List<String> coupables = new ArrayList<String>();
		double lastX = 0;
		double lastY = 0;

		for(int i = 0; i < N; i++){
			String suspect = scanner.next();
			boolean criminel = false;
			for(int j = 0; j < T; j++){
				double X = scanner.nextDouble();
				double Y = scanner.nextDouble();

				if(j > 0 && distance(lastX, lastY, Xb, Yb) + distance(Xb, Yb, X, Y) <= vitesseMax)
					criminel = true;
				lastX = X;
				lastY = Y;
			}
			if(criminel)
				coupables.add(suspect);
		}

		System.out.println((String.join(" ", coupables)));

		scanner.close();
	}
}
