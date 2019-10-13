import java.io.*;
import java.util.*;

public class arraylist
{
public static void main(String[] args)
{

int n=6;
ArrayList<Integer> al=new ArrayList<Integer>(n);
for(int i=0;i<=n;i++)
{
 al.add(i);
}
System.out.println(al);
}
}