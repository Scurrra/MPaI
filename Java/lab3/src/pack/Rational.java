package pack;

import java.lang.Math;

public class Rational
{
    private int numerator, denominator, sign = 1;

    public Rational(int num, int den)
    {
        numerator = num;

        try
        {
            if (den != 0)
            {
                denominator = den;
            }
            else
            {
                throw new ArithmeticException();
            }
        }
        catch (ArithmeticException e)
        {
            System.err.println(e);
        }

        normalize();
    }

    private static int gcd(int a, int b)
    {
        return b != 0 ? gcd(b, a % b) : a;
    }

    private void normalize()
    {
        if (numerator != 0 && denominator != 0)
        {
            sign = numerator/Math.abs(numerator) * denominator/Math.abs(denominator);
            int common = gcd(Math.abs(numerator), Math.abs(denominator));
            numerator = Math.abs(numerator) / common * sign;
            denominator = Math.abs(denominator) / common;
        }

        if (numerator == 0) denominator = 1;
    }

    public static Rational sum(Rational a, Rational b)
    {
        return new Rational(a.numerator*b.denominator + b.numerator*a.denominator, a.denominator*b.denominator);
    }

    public static Rational sub(Rational a, Rational b)
    {
        return new Rational(a.numerator*b.denominator - b.numerator*a.denominator, a.denominator*b.denominator);
    }

    public static Rational mult(Rational a, Rational b)
    {
        return new Rational(a.numerator*b.numerator, a.denominator*b.denominator);
    }

    public static Rational div(Rational a, Rational b)
    {
        return new Rational(a.numerator*b.denominator, b.numerator*a.denominator);
    }

    public static boolean eq(Rational a, Rational b)
    {
        return a.numerator == b.numerator && a.denominator == b.denominator;
    }

    public static boolean gr(Rational a, Rational b)
    {
        return a.numerator*b.denominator > b.numerator*a.denominator;
    }

    public static boolean ls(Rational a, Rational b)
    {
        return a.numerator*b.denominator < b.numerator*a.denominator;
    }

    public String toString()
    {
        return numerator == 0 ? "0" : sign == 1 ? numerator + "/" + denominator : "(" + numerator + "/" + denominator + ")";
    }
}

