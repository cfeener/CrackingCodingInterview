package p2_2_Kth_from_Last;

public class Main {

	public static void main(String[] args) {
		int k = 4;
		int [] a = {8, 1, 0, 2, 9, 1,
		0, 0, 2, 3, 0, 6};

		KList list = new KList();
		
		for (int x : a)
			list.insert(x);
		
		list.print();
		
		if (list.head != null)
			System.out.println("Result: " + list.accessFromTail(k - 1));
	}

}
