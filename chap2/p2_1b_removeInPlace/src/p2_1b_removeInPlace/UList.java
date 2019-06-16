package p2_1b_removeInPlace;

public class UList {
	Node head;
	Node tail;	//For insertion optimization
	int n = 0;	//Size
	int dups = 0;
	boolean [] is_dup;

	void insert(int x) {
		if (head == null) {
			head = new Node(x);
			tail = head;
		} else {	//Insert at tail
			tail.next = new Node(x);
			tail = tail.next;
		}
		n++;
	}
	
	void print() {
		Node temp = head;
		while (temp != null) {
			System.out.println("" + temp.data);
			temp = temp.next;
		}
	}
	
	void checkForDups() {	//TODO: First node must be considered unique
		int i = 0, j = 0;
		is_dup = new boolean[n];
		for (Node temp1 = head; temp1 != null; temp1 = temp1.next) {
			int a = temp1.data;
			for (Node temp2 = head; temp2 != null; temp2 = temp2.next) {
				if (i == j) 
					continue;
				int b = temp2.data;
				if (a == b) {
					is_dup[j] = true;
					dups++;
				}
				j++;
			}
			j = 0;
			i++;
		}
	}

	boolean removals() {
		if (n <= 0) {	//For empty list
			System.out.println("empty");
			return false;
		}
		int i = 1;	//Index of temp node. First node is considered unique
		Node prev = head;
		Node temp = head.next;
		while (temp != null) {
			while (is_dup[i] == true && temp != null) {
				temp = temp.next;
				i++;
			}
			prev.next = temp;	//Skip over duplicates
			prev = prev.next;	//Update on 6/16
			temp = temp.next;
			i++;
		}
		return true;
	}
}
