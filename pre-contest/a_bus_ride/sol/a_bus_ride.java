import java.util.Scanner;

public class MainShaker {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System. in);
        int nbPerson = Integer.parseInt(scanner.nextLine());
        int nbSeat = Integer.parseInt(scanner.nextLine());
        
        System.out.println((int)Math.ceil(nbPerson / (double)nbSeat));
        
        scanner.close();
    }
}
