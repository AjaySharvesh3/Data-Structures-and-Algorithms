import java.util.scanner;
class ebconsumer
{
	int consumer_number;
	String consumer_name;
	int previous_month_reading;
	int current_month_reading;
	int units_consumed;
	boolean isDomestic=false;
	double bill_amount;
	public void display Domesticfares()
{
	System.out.println("Domestic fare details");
	System.out.println("*****************");
	System.out.println("First 100 units - Rs.1 per unit"); 
	System.out.println("101-200 units - Rs2.5 per unit");
	System.out.println("201-500 units-Rs4 per unit");
	System.out.println(">501 units - Rs 6 per unit");
}
public void display Commercialfare()
{
	System.out.println("commercial fare details");
	System.out.println("First 100 units - Rs2 per unit");
	System.out.println("101-200 units - Rs4.50per unit");
	System.out.println("201-500 units - Rs6per unit");
	System.out.println(">501 units - Rs7 per unit");
}
public void getdetails()
{
	Scanner inputs=new Scanner(System.in);
	System.out.println("Welcome to Eb calculator");
	System.out.println("Please enter your name");
	this.consumer_name=inputs.next();
	System.out.println("Please enter your consumer number");
	this.consumer_number=inputs.nextInt();
	System.out.println("Please enter your previous month reading");
	this.previous_month_reading=inputs.nextInt();
	System.out.println("Please enter your current month reading");
	this.current_month_reading=inputs.nextInt();
	System.out.println("Is this domestic connection (yes/no)");
	if(inputs.next().equals("yes"))
		this.Isdomestic=true;
}
public void generatebill()
{
	int number_of_units_consumed=this.current_month_reading-this.previous_month_reading;
	this.units_consumed=number_of_units_consumed;
	double sum=0;
	if(isDomestic==true)
{
	for(int i=0;i<=number_of_units_consumed;i++);
	{
	if(i<=100)
	sum=sum+1;
	else if(i>100&&i<=200)
	sum=sum+2.5;
	else if(i>200&&i<=500)
	sum=sum+4;
	else
	sum=sum+6;

}
}
else
{
	for(int i=0;i<=number_of_units_consumed;i++)
{
	if(i<=100)
	sum=sum+2;
	else if(i>100&&i<=200)
	sum=sum+6;
	else
	sum=sum+7;
}
}
this.bill_amount=sum;
}
public void display()
{
	generate bill();
	System.out.println("The EB details");
	System.out.println("************");
	System.out.println("Consumer number:"+this_consumer_number);
	System.out.println("Consumer name:"+this_consumer_name);
	System.out.println("Consumer units consumed:"+this.units_consumed);
	if(this.isDomestic==true)
	System.out.println("You are a Domestic consumer\nFare Details");
	else
	System.out.println("You are a Commercial consumer\nFare details");
	
System.out.println("\nAmount payable is \u20B9:"+this.bill_amount);
}}

public class main{
public static void main(String args[])
{
	ebconsumer consumer=new ebconsumer();
	consumer.getdetails();
	consumer.displaybill();
}
}