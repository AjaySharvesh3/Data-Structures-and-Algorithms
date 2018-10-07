# Hash Tabel in Java

Hello World!

Hash Table is like a dictionary. It has **key value pairs**. That is when the key is called, its relevant value will be returned. For example, we have a requirement that we need to display the *day* in a week for a given number. That is if the number is *3*, the value should be *Tuesday*.

- 1 - Sunday
- 2 - Monday
- 3 - Tuesday
- 4 - Wednesday
- 5 - Thursday
- 6 - Friday
- 7 - Saturday

To create this key value pair in java, just do the following:

```java
		Hashtable days = new Hashtable();
		days.put(1, "Sunday");
		days.put(2, "Monday");
		days.put(3, "Tuesday");
		days.put(4, "Wednesday");
		days.put(5, "Thursday");
		days.put(6, "Friday");
		days.put(7, "Saturday");

```

This will create the hash table for days in a week.

The complete program is:

```java
		import java.util.Hashtable;
		public class DaysinWeek {
		public static void main(String args[]) {
				Hashtable days = new Hashtable();
				days.put(1, "Sunday");
				days.put(2, "Monday");
				days.put(3, "Tuesday");
				days.put(4, "Wednesday");
				days.put(5, "Thursday");
				days.put(6, "Friday");
				days.put(7, "Saturday");
				System.out.println("Keys: "+days.keys());
				System.out.println("Hash Code: "+days.hashCode());
				System.out.println("Size: "+days.size());
				System.out.println("Get(3): "+days.get(3));
				System.out.println("Get(Tuesday): "+days.get("Tuesday"));
				System.out.println("Contains(3): "+days.contains(3));
				System.out.println("ContainsKey(3): "+days.containsKey(3));
				System.out.println("ContainsValue(Tuesday): "+days.containsValue("Tuesday"));
				System.out.println("Is Empty: "+days.isEmpty());
				System.out.println("Values: "+days.values());
			}
		}
```

Get the file [here](https://github.com/sriram23/Data-Structures-and-Algorithms./blob/master/Algorithm_Solutions/DaysinWeek.java)

### Output:

![Output](https://github.com/sriram23/Data-Structures-and-Algorithms./blob/master/Algorithm_Solutions/Image/Screenshot%20from%202018-10-07%2008-45-15.png)
