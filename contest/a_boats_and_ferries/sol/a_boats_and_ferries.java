import java.util.Scanner;

public class cb1 {

    public static void main(String[] args) {

        // read and store the input numbers as integers
        Scanner sc = new Scanner(System.in);
        int p = sc.nextInt();
        int b = sc.nextInt();
        int f = sc.nextInt();

        // compute the number of peple who won't fit in the boats or ferries
        int r = p - (4 * b + 500 * f);

        // if this number is negative, make it 0 instead
        if (r < 0){
            r = 0;
        }

        // then print the result
        System.out.println(r);

    }

}
