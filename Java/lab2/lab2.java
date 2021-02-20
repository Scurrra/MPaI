import java.lang.Integer;
import java.util.Scanner;
import java.util.Random;

public class lab2 
{
    public static void main(String[] args) 
    {
        int n = 0;
        Scanner scan = new Scanner(System.in);
        Random rand = new Random(); 

        if (args.length == 1) 
        {
            n = Integer.parseInt(args[0]);
        } 
        else 
        {
            n = scan.nextInt();
        }    

        int matrix[][] = new int[n][n];

        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                matrix[i][j] = rand.nextInt(2 * n) - n;
                System.out.printf("%5d", matrix[i][j]);
            }    

            System.out.println();
        }

        System.out.println();
        System.out.print("Введите номер строки: ");
        int k = scan.nextInt();
        System.out.println();
        
        // int ind[] = sortLine(matrix, k);
        int ind[] = sortRow(matrix[k]);
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                System.out.printf("%5d", matrix[i][ind[j]]);
            }    

            System.out.println();
        }

        System.out.println();
        System.out.print("Введите номер столбца: ");
        k = scan.nextInt();
        System.out.println();
        
        ind = sortCol(matrix, k);
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                System.out.printf("%5d", matrix[ind[i]][j]);
            }    

            System.out.println();
        }
    }    

    public static int[] sortRow (int[][] matrix, int k)
    {
        int ind[] = new int[matrix.length];
        for (int i = 0; i < ind.length; i++) 
        {
            ind[i] = i;
        }

        boolean swapped;

        for (int i = 0; i < ind.length - 1; i++) 
        {
            swapped = false;
            for (int j = 0; j < ind.length - i - 1; j++) 
            {
                if (matrix[k][ind[j]] > matrix[k][ind[j+1]]) 
                {
                    int buffer = ind[j];
                    ind[j] = ind[j+1];
                    ind[j+1] = buffer;
                    swapped = true;
                }
            }

            if (!swapped) 
            {
                break;    
            }
        }

        return ind;
    }

    public static int[] sortRow (int[] line)
    {
        int ind[] = new int[line.length];
        for (int i = 0; i < ind.length; i++) 
        {
            ind[i] = i;
        }

        boolean swapped;

        for (int i = 0; i < ind.length - 1; i++) 
        {
            swapped = false;
            for (int j = 0; j < ind.length - i - 1; j++) 
            {
                if (line[ind[j]] > line[ind[j+1]]) 
                {
                    int buffer = ind[j];
                    ind[j] = ind[j+1];
                    ind[j+1] = buffer;
                    swapped = true;
                }
            }

            if (!swapped) 
            {
                break;    
            }
        }

        return ind;
    }

    public static int[] sortCol (int[][] matrix, int k)
    {
        int ind[] = new int[matrix.length];
        for (int i = 0; i < ind.length; i++) 
        {
            ind[i] = i;
        }

        boolean swapped;

        for (int i = 0; i < ind.length - 1; i++) 
        {
            swapped = false;
            for (int j = 0; j < ind.length - i - 1; j++) 
            {
                if (matrix[ind[j]][k] > matrix[ind[j+1]][k]) 
                {
                    int buffer = ind[j];
                    ind[j] = ind[j+1];
                    ind[j+1] = buffer;
                    swapped = true;
                }
            }

            if (!swapped) 
            {
                break;    
            }
        }

        return ind;
    }
}
