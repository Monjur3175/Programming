import java.util.Scanner;

public class yy{
public static void main(String[] args) {
    Scanner scanner=new Scanner (System.in);
    System.out.println("Enter number one:");
    int number1=scanner.nextInt();
    System.out.println("Enter number 2");
    int number2=scanner.nextInt();
    int sum=number1+number2;
    scanner.close();
}   
}