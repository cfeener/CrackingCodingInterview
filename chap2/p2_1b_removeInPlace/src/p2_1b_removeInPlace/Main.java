/* Christopher Feener
 * 6/15/2019
 * Remove duplicates in own Linked List in place.
 */

package p2_1b_removeInPlace;

public class Main {

	public static void main(String[] args) {
		UList list = new UList();

		//Test input:
		int a[] = {1,1,1,1,1,1/*8, 1, 0, 2, 9, 1,
			0, 0, 2, 3, 0, 6*/};
		
		for (int i : a) {
			list.insert(i);
		}
		
		list.print();
		
		list.checkForDups();
		if (list.removals())	//If not empty
			System.out.println("AFTER: ");
		
		list.print();
	}

}
