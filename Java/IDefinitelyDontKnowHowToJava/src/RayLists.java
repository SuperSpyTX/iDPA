import java.util.ArrayList;
import java.util.Scanner;

public class RayLists {

	public static ArrayList<String> garbageList = new ArrayList<String>();
	
	public static void main(String[] args) {
		g();
		Scanner input = new Scanner(System.in);
		
		while(true) {
			garbageList.add(input.nextLine());
		}
	}
	
	public static void g() {
		g();
	}
}
