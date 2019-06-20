/* Christopher Feener
 * 6/17/2019
 * Delete middle node in a linked list.
 */

package p2_3_deleteMid;

public class DList {
	Node head;
	
	DList(int ...a) {
		for (int x : a)
			this.insert(x);
	}
	
	void printList() {
		if (head == null) {
			System.out.println("Empty list!");
		}
		Node temp = head;
		while (temp != null) {
			System.out.println("" + temp.data);
			temp = temp.next;
		}
	}
	
	void insert(int x) {
		if (head == null)
			head = new Node(x);
		else {
			Node in = new Node(x);
			in.next = head;
			head = in;
		}
	}
	
	void deleteInterior(int k) {	//Deletes an interior node
		k = k - 1;
		if (k < 1) {
			System.out.println("Nothing deleted.");
			return;
		}
		if (head == null || head.next == null) 
			return;
		int i = 1;	//First node is ignored. (K is unaltered, therefore 1-indexed.)  
		Node prev = head;
		Node temp = head.next;
		while (temp != null) {
			if (i < k) {
				prev = prev.next;
				temp = temp.next;
				i++;
			} else break;
		}
		if (prev.next == null) {
			System.out.println("Nothing deleted");
			return;
		}
		else
			prev.next = temp.next;
	}
}
