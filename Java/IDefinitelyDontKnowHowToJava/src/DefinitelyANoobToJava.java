import java.util.Scanner;

public class DefinitelyANoobToJava {
	
	static String hi = "Hello World!";
	public static void main(String[] args) {
		JVMHack.hackJava();
		boolean g = false;
		if (g) {
			System.out.println("What? Why you seeing this?");
		}
		Double i = new Double(3);
		System.out.println(hi);
		
		B someName = new B();
		int hits = someName.getHitCount();
		System.out.println(hits);
		
		Scanner input = new Scanner(System.in);
		try {
			int x = input.nextInt();
			System.out.println("Wat is " + x);
			input.close();
		} catch (Exception e) {
			System.out.println("Invalid Input.");
		}
	}
}
