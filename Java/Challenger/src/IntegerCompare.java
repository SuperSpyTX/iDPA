import java.util.Comparator;

public class IntegerCompare<T> implements Comparator {

	@Override
	public int compare(Object o1, Object o2) {
		return ((Integer) o1) - ((Integer) o2);
	}

}