import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Random;

public class Challenge {

	public static void main(String[] args) {
		ArrayList<Integer> rand1 = new ArrayList<Integer>();
		ArrayList<Integer> rand2 = new ArrayList<Integer>();
		Random rdm = new Random(System.currentTimeMillis());
		
		for (int i = 0; i < 10; i++) {
			rand1.add(rdm.nextInt(10));
			rand2.add(rdm.nextInt(10));
		}
		
		int min1 = -1000, max1 = -1000, min2 = -1000, max2 = -1000;
		for (int i = 0; i < rand1.size(); i++) {
			System.out.println("ARR 1: " + rand1.get(i) + " - ARR 2: " + rand2.get(i));
			// set the minimums and compare to the next.
			if (min1 == -1000) {
				min1 = rand1.get(i);
			} else if (max1 == -1000) {
				max1 = rand1.get(i);
			}
			
			if (min2 == -1000) {
				min2 = rand2.get(i);
			} else if (max2 == -1000) {
				max2 = rand2.get(i);
			}
			if (min1 != -1000 && min2 != -1000 && max1 != -1000 && max2 != -1000)
			{
				// le compare.
				if (min1 > rand1.get(i)) {
					min1 = rand1.get(i);
				} else if (max1 < rand1.get(i)) {
					max1 = rand1.get(i);
				}
				
				if (min2 > rand2.get(i)) {
					min2 = rand2.get(i);
				} else if (max2 < rand2.get(i)) {
					max2 = rand2.get(i);
				}
			}
		}
		System.out.println("ARR 1: Min: " + min1 + " Max: " + max1);
		System.out.println("ARR 2: Min: " + min2 + " Max: " + max2);
		
		// compare the two and compress them(?)
		int min = 0, max = 0;
		if (min1 < min2) {
			min = min1;
		} else if (min1 > min2) {
			min = min2;
		}
		
		if (max2 > max1) {
			max = max2;
		} else if (max2 < max1) {
			max = max1;
		}
		
		System.out.println("MAX: " + max + " MIN: " + min);
		
		// Put them in stacked order!
		Collections.sort(rand1);
		Collections.sort(rand2);
		
		for (int i = 0; i < rand1.size(); i++) {
			System.out.println("ONE: " + rand1.get(i));
		}
		
		for (int i = 0; i < rand2.size(); i++) {
			System.out.println("TWO: " + rand2.get(i));
		}
	}
}
