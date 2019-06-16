package p2_1b_removeInPlace;

public class UList {
	Node head;
	int n = 0;	//Size
	int dups = 0;
	boolean [] is_dup;

	void insert(int x) {
		if (head == null) 
			head = new Node(x);
		else {
			Node temp = new Node(x);
			temp.next = head;
			head = temp;
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
	
	void checkForDups() {	//Tested!
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

	void removals() {	//TODO: Leaves out number 3 in test.
		int i = 1;	//Index of temp node
		Node prev = head;
		Node temp = head.next;
		boolean is_found = false;
		while (temp != null) {
			while (is_dup[i] == true && temp != null) {
				is_found = true;
				temp = temp.next;
				i++;
			}
			if (is_found)
				prev.next = temp;	//Skip over duplicates
			temp = temp.next;
			is_found = false;
			i++;
		}
	}
}
