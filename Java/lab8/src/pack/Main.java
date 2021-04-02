package pack;
import java.util.Scanner;
import java.util.regex.*;

public class Main {

    public static void main(String[] args)
    {
        Pattern pattern = Pattern.compile("([A-Z]+\\w+[a-z]+\\w+[0-9]+)");

        System.out.print("Password: ");
        Scanner scan = new Scanner(System.in);
	    String password = scan.nextLine();

        Matcher matcher = pattern.matcher(password);
        if (password.length() >= 10 && matcher.matches())
            System.out.println("Strong");
        else
            System.out.println("Weak");
    }
}
