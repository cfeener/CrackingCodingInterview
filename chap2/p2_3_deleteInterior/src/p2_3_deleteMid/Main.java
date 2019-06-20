/* Christopher Feener
 * 6/17/2019
 * Delete interior node in a linked list.
 * Note: Tail is currently deletable. 
 */

package p2_3_deleteMid;

public class Main {

	public static void main(String[] args) {
		//Test values:
		int [] a = {8, 1, 0, 2, 9, 1,
                0, 0, 2, 3, 0, 6};
		
		DList list = new DList(a);
		System.out.println("Before: ");
		list.printList();
		
		System.out.println("After: ");
		list.deleteInterior(12);
		list.printList();
	}

}