package pack;

import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        Polynom a = new Polynom(new Rational[]{
           new Rational(1,2), new Rational(2,3), new Rational(1,3),
                new Rational(5,2), new Rational(2,7), new Rational(1,5)
        });

        Polynom b = new Polynom(new Rational[]{
           new Rational(3,2), new Rational(4,3), new Rational(7,3),
                new Rational(3,2), new Rational(1,5)
        });

        System.out.println((new Rational(-3,2)) + " - " + (new Rational(3,-2)) + " = " + Rational.sub(new Rational(-3,2), new Rational(3,-2)));

        System.out.println("(" + a + ")' = " + a.dif());
        System.out.println(a + " + " + b + " = " + Polynom.sum(a, b));
        System.out.println(a + " - " + b + " = " + Polynom.sub(a, b));
        System.out.println(a + " * " + b + " = " + Polynom.mult(a, b));


        Random rand = new Random();
        Polynom polynoms[] = new Polynom[rand.nextInt(10) + 10];
        for (int i = 0; i < polynoms.length; i++)
        {
            Rational coefs[] = new Rational[rand.nextInt(10) + 3];
            for (int j = 0; j < coefs.length; j++)
            {
                int den = rand.nextInt(10)-5;
                coefs[j] = new Rational(rand.nextInt(10)-5, den == 0 ? den+1 : den);
            }
            polynoms[i] = new Polynom(coefs);
        }

        System.out.println();
        Polynom sum = polynoms[0];
        for (int i = 1; i < polynoms.length; i++)
        {
            sum = Polynom.sum(sum, polynoms[i]);
            System.out.println("\t" + polynoms[i-1]);
            System.out.println("+");
        }
        System.out.println("\t" + polynoms[polynoms.length-1]);
        System.out.println("=");
        System.out.println("\t" + sum);
    }
}
