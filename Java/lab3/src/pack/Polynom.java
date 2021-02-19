package pack;

import java.util.*;

public class Polynom
{
    private Rational[] coefs;

    public Polynom(Rational[] coefs)
    {
        Collections.reverse(Arrays.asList(coefs));
        this.coefs = coefs.clone();
    }

    public static Polynom sum(Polynom a, Polynom b)
    {
        Rational coefs[];

        if (a.coefs.length >= b.coefs.length)
        {
            coefs = a.coefs.clone();
            for (int i = 0; i < b.coefs.length; i++)
            {
                coefs[i] = Rational.sum(coefs[i], b.coefs[i]);
            }
        }
        else
        {
            coefs = b.coefs.clone();
            for (int i = 0; i < a.coefs.length; i++)
            {
                coefs[i] = Rational.sum(coefs[i], a.coefs[i]);
            }
        }

        Collections.reverse(Arrays.asList(coefs));
        return new Polynom(coefs);
    }

    public static Polynom sub(Polynom a, Polynom b)
    {
        Rational coefs[];

        if (a.coefs.length >= b.coefs.length)
        {
            coefs = a.coefs.clone();
            for (int i = 0; i < b.coefs.length; i++)
            {
                coefs[i] = Rational.sub(coefs[i], b.coefs[i]);
            }
        }
        else
        {
            coefs = b.coefs.clone();
            for (int i = 0; i < a.coefs.length; i++)
            {
                coefs[i] = Rational.sub(coefs[i], a.coefs[i]);
            }
        }

        Collections.reverse(Arrays.asList(coefs));
        return new Polynom(coefs);
    }

    public static Polynom mult(Polynom a, Polynom b)
    {
        Rational coefs[] = new Rational[a.coefs.length + b.coefs.length - 1];
        for (int i = 0; i < coefs.length; i++)
        {
            coefs[i] = new Rational(0,1);
        }

        for (int i = 0; i < b.coefs.length; i++)
        {
            for (int j = 0; j < a.coefs.length; j++)
            {
                coefs[i+j] = Rational.sum(coefs[i+j], Rational.mult(b.coefs[i], a.coefs[j]));
            }
        }

        Collections.reverse(Arrays.asList(coefs));
        return new Polynom(coefs);
    }

    public static boolean eq(Polynom a, Polynom b)
    {
        if (a.coefs.length != b.coefs.length)
        {
            return false;
        }

        for (int i = 0; i < a.coefs.length; i++)
        {
            if (!Rational.eq(a.coefs[i],b.coefs[i]))
            {
                return false;
            }
        }

        return true;
    }

    public Polynom dif()
    {
        Rational coefs[] = new Rational[this.coefs.length-1];

        for (int i = 0; i < coefs.length; i++)
        {
            coefs[i] = Rational.mult(new Rational(i + 1, 1), this.coefs[i+1]);
        }

        Collections.reverse(Arrays.asList(coefs));
        return new Polynom(coefs);
    }

    public String toString()
    {
        String pol = "";

        for (int i = coefs.length - 1; i > 0; i--)
        {
            pol += coefs[i].toString() == "0" ? "" : coefs[i] + "*" + "x^" + i + "+";
        }
        pol += coefs[0];

        return pol;
    }
}
