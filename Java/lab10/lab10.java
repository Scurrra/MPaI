import java.io.*;
import java.util.*;

public class lab10 
{
    public static void main(String[] args) 
    {
        String filename = "generated.txt";
        int n;

        if (args.length == 1) 
        {
            n = Integer.parseInt(args[0]);    
        }
        else if (args.length == 2) 
        {
            filename = args[0];
            n = Integer.parseInt(args[1]);    
        }
        else
        {
            return;
        }

        // generation
        Random rand = new Random();
        try (BufferedWriter gen = new BufferedWriter(new FileWriter(filename)))
        {
            for (int i = 0; i < n; i++) 
            {
                gen.write((rand.nextInt(n) + 1) + "\n");    
            }
        } 
        catch (Exception e) {
            System.out.println(e.getMessage());
        }

        // reading
        ArrayList<Integer> numbers = new ArrayList<>();
        try (BufferedReader gen = new BufferedReader(new FileReader(filename)))
        {
            String buffer;
            while ((buffer = gen.readLine()) != null)
                numbers.add(Integer.parseInt(buffer));

            // проверка
            //for (int i = 0; i < numbers.size(); i++) 
            //    System.out.println(numbers.get(i));
        } 
        catch (Exception e) {
            System.out.println(e.getMessage());
        }


        // sorted
        try (BufferedWriter sorted = new BufferedWriter(new FileWriter("sorted.txt")))
        {
            numbers.sort(new Comparator<Integer>(){
                @Override
                public int compare(Integer left, Integer right) {
                    return left.compareTo(right);
                }   
            });

            for (int i = 0; i < n; i++) 
            {
                sorted.write(numbers.get(i) + "\n");    
            }
        } 
        catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}