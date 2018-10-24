
import java.util.ArrayList;
import java.util.Scanner;


/**
 *
 * @author Amrutha
 */
public class ArrayList_Java {
    static Scanner scan = new Scanner(System.in);
    public static void main(String[] args){
        
        System.out.println("Enter the number of elements in ArrayList");
        int size = scan.nextInt();
        
        ArrayList<Integer> arr = new ArrayList<Integer>(size);      // Can also use int, char, double, long, String and Double(Wrapper class for double)
        /*
        The difference between array and arraylist is that array has fixed length, ArrayList can resize.
        */
        
        int n;
        for(int i=0;i<size;i++){
            System.out.println("Enter an integer :");
            n = scan.nextInt();
            arr.add(n); // Adds element to the arraylist            
        }
        System.out.println(arr);
        
        // Adding more elements exceeds the array list size declared, but it is possible
        arr.add(1);
        arr.add(2);
        System.out.println(arr);
        
        System.out.println("Enter the index of the element to be removed :");
        n = scan.nextInt();
        arr.remove(n);
        System.out.println(arr);
        
        // We can also set the index to be inserted
        arr.add(0, 6);  //Adds element 6 to 0th index
        System.out.println(arr);
        
        for(int i=0;i<arr.size();i++)
        {
            System.out.println("Item "+i+" "+arr.get(i)+"\n");     // Gets the item at the index i
        }
        arr.clear();    //Clears the arraylist
        System.out.println(arr);
    }
    
}
