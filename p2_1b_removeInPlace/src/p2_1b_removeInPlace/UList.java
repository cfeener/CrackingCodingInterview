package p2_1b_removeInPlace;

public class UList {
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

}
