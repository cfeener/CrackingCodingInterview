/* Christopher Feener
 * 6/16/2019
 * Return Kth element from tail.
 * Note: Returns zero for values below 1, and returns 
 * 		first element for values greater than total list length.
 */

package p2_2_Kth_from_Last;

public class KList {
	Node head;
	
	void insert(int x) {
		if (head == null)
			head = new Node(x);
		else {
			Node temp = new Node(x);
			temp.next = head;
			head = temp;
		}
	}
	
	void print() {
		Node temp = head;
		while (temp != null) {
			System.out.println("" + temp.data);
			temp = temp.next;
		}
	}
	
	void deleteTail(int index) {	//To be used with queue
		Node temp = head;
		int i = 0;
		while (i < index - 1) {	//Traverse just before tail
			if (temp == null) break;
			temp = temp.next;
			i++;
		}
		temp.next = null;	//Release tail
	}
	
	int accessFromTail(int index) {
		if (index <= 0) return 0;
		int i = 0;
		KList queue = new KList();
		Node temp = head;
		while (temp != null) {
			if (i > index) 
				queue.deleteTail(index);
			queue.insert(temp.data);
			temp = temp.next;
			i++;
		}
		temp = queue.head;	//Most recent element; also is the list's tail.
		while (temp.next != null)	//Traverse to end of queue
			temp = temp.next;
		return temp.data;	//Kth element from end of list.
	}
}
