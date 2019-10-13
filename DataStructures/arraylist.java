import java.io.*;
import java.util.*;
class array
{
public static void main(String args[]) throws IOException
{
int n=4;
ArrayList<Integer> arr=new ArrayList<Integer>(n);
for(int i=1;i<=n;i++)
arr.add(i);
System.out.println(arr);
arr.remove(1);
System.out.println(arr);
for(int i=0;i<arr.size();i++)
System.out.println(arr.get(i)+" ");
}
}

