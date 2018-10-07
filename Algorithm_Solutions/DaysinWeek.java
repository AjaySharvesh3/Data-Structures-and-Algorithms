import java.util.Hashtable;

public class DaysinWeek {
	public static void main(String args[]) {
		Hashtable days = new Hashtable(); // Creating Hash Table
		days.put(1, "Sunday");
		days.put(2, "Monday");
		days.put(3, "Tuesday");
		days.put(4, "Wednesday");
		days.put(5, "Thursday");
		days.put(6, "Friday");
		days.put(7, "Saturday");
		System.out.println("Keys: "+days.keys());  //Returns Key 
		System.out.println("Hash Code: "+days.hashCode()); // Returns Hash Code
		System.out.println("Size: "+days.size()); // Returns Size of table
		System.out.println("Get(3): "+days.get(3)); // Returns value for key
		System.out.println("Get(Tuesday): "+days.get("Tuesday")); // This won't work as value is passed
		System.out.println("Contains(3): "+days.contains(3)); // Returns True if value is contained in table
		System.out.println("ContainsKey(3): "+days.containsKey(3)); // Returns True if key is contained in the hash table
		System.out.println("ContainsValue(Tuesday): "+days.containsValue("Tuesday")); // Returns Ture if value is contained in the table
		System.out.println("Is Empty: "+days.isEmpty()); // Returns True if table is empty
		System.out.println("Values: "+days.values()); // Returns the value of table
	}
}

