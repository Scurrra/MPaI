import java.lang.Integer;
import java.util.Scanner;

public class lab1
{
    public static void main(String[] args) 
    {
        if (args.length > 1) 
        {
            int[] nums = new int[args.length];
            for (int i = 0; i < args.length; i++)
            {
                nums[i] = Integer.parseInt(args[i]);
            }

            for (int i : nums) 
            {
                if (i % 2 == 0) 
                {
                    System.out.printf(i + " ");  
                } 
            }

            System.out.println();

            for (int i : nums) 
            {
                if (i % 2 != 0) 
                {
                    System.out.printf(i + " ");  
                } 
            }

            System.out.println();
        }   
        else
        {
            int n = 0;
            Scanner scan = new Scanner(System.in);
            if (args.length == 1) 
            {
                n = Integer.parseInt(args[0]);
            }
            else
            {
                System.out.print("Введите размер массива: ");
                n = scan.nextInt();
            }
        
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) 
            {
                nums[i] = scan.nextInt();
            }

            for (int i : nums) 
            {
                if (i % 2 == 0) 
                {
                    System.out.printf(i + " ");  
                } 
            }
            System.out.println();

            for (int i : nums) 
            {
                if (i % 2 != 0) 
                {
                    System.out.printf(i + " ");  
                } 
            }
            System.out.println();
        }
    }
}