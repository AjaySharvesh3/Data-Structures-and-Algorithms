import java.util.HashMap;
import java.util.Scanner;


/**
 *
 * @author Amrutha
 */
public class HashMap_Java {

    /**
     * @param args the command line arguments
     */
    static Scanner scan = new Scanner(System.in);
    
    public static void main(String[] args) {
        HashMap <String, Integer> map = new HashMap<>();    //Creating object for hashmap. It maps a String to Integer. Key=String Value=Int
        
        insert_map(map);    
        print_map(map);     // Non-empty hashmap
        map.clear();
        System.out.println("HashMap cleared");        //Clears the hashmap
        print_map(map);     //Empty now
        
        
        insert_map(map);
        check_key(map);
    }
    public static void insert_map(HashMap map)
    {
        
        System.out.println("Enter the number of entries in HashMap");
        int n = scan.nextInt();
        while(n>0)
        {
            System.out.println("Enter string and integer");
            String str = scan.next();
            int i = scan.nextInt();
            map.put(str, i);    // Inserts the key-value pair into the hash map
            n--;
        }
    }
    public static void print_map(HashMap map)
    {
        if(map.isEmpty())
            System.out.println("HashMap empty");
        else{
            map.forEach((k,v) -> System.out.println("Key="+k+" Value="+v));
        }
    }
    public static void check_key(HashMap map)
    {
        System.out.println("Check if the key is present and return it's value");
        String key_check=scan.next();
        if(map.containsKey(key_check))
        {
            int value = (int) map.get(key_check);     // Retrieve the value from hashmap
            System.out.println("Key "+key_check+" found\nValue = "+value);
        }
    }
}
