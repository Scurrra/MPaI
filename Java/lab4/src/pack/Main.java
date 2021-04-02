package pack;

import java.util.Date;
import java.util.Random;

public class Main
{

    public static void main(String[] args)
    {
        Random rand = new Random();

	    Client[] clients = new Client[]{
                new Client("Natasha", "Zhemoityak", new Date(2001, 10, 30), Sex.FEMALE),
                new Client("E-Katya", "Labun", new Date(2002, 3, 12), Sex.FEMALE),
                new Client("Levi", "Taborov", new Date(2001, 10, 30), Sex.MALE),
                new Client("Ilya", "Borovsky", new Date(2002, 8, 2), Sex.MALE),
                new Client("Elya", "Loh", new Date(2002, 9, 26), Sex.MALE)
        };

        for (Client cl: clients)
        {
            for (int i = 0; i < rand.nextInt(5) + 1; ++i)
            {
                cl.newAccount(rand.nextInt(100000) + rand.nextDouble(), Currency.USD);
            }
            System.out.println(cl.getPerson());

            System.out.format("Sum USD: %,.2f\n", cl.wholeSum(Currency.USD));
            System.out.println("USD's:\n\t" + String.join("\n\t", cl.find(Currency.USD)));

            System.out.println("-------------------------------------");
        }

    }
}
