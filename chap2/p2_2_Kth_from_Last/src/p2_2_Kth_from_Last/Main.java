/* Christopher Feener
 * 6/16/2019
 * Return Kth element from tail.
 * Note: Returns zero for values below 1, and returns 
 * 		first element for values greater than total list length.
 */

package p2_2_Kth_from_Last;

public class Main {

	public static void main(String[] args) {
		//Test values: -42, 0, 4, 42
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
