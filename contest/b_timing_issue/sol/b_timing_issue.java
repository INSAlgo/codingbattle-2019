import java.util.Scanner;

public class MainShaker {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System. in);
		
		int localH, localM, ETMinsInEarthMin, ETMinsInETHour, resMins, resHours;
		
		String tmp = scanner.nextLine();
		String[] inputs = tmp.split(":");
		localH = Integer.parseInt(inputs[0]);
		localM = Integer.parseInt(inputs[1]);
		ETMinsInEarthMin = scanner.nextInt();
		ETMinsInETHour = scanner.nextInt();
		
		resMins = ((localH * ETMinsInETHour) + localM) / ETMinsInEarthMin;

		resHours = (resMins / 60) % 24;
		resMins = resMins % 60;
		
		System.out.println(resHours + ":" + resMins);

		scanner.close();
	}
}
