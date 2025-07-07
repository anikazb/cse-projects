package    BankAccount_project;

public class BankAccount 
{
    private String name;
    private double balance;
    //constructor
    public BankAccount(String name,double balance)
    {
        this.name=name;
        this.balance=balance;
    }
    //method for check your current balance 
    public void checkBalance()
    {
        System.out.println("Your current Balance is"+balance+"Taka"); 
    }
  //METHOD FOR deposit(double amount)
  public void deposit(double amount)
  {
    if(amount>0)
  {
     balance=balance+amount;
     System.out.println("Money deposited "+amount +". Total Money "+balance+"Taka");
  }
  else
  {
    System.out.println("No money deposited");
  }
}
//METHOD FOR withdraw(double amount)
public void withdraw(double amount)
{
  if(amount>0 && balance>amount)
{
   balance=balance-amount;
   System.out.println("Money withdraw "+amount +". Total Money "+balance+"Taka");
}
else
{
  System.out.println("No money withdraw");
}
}
//display
public String toString()
{
    return "Account holder name:" +name +". \nCurrent:"+balance ;
}

}

