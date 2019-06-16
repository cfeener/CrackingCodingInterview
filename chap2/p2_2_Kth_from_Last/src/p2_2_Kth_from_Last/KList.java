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
	
	void deleteTail(int index) {
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
		int i = 0;
		KList helper_list = new KList();
		Node temp = head;
		while (temp != null) {
			if (i > index) 
				helper_list.deleteTail(index);
			helper_list.insert(temp.data);
			temp = temp.next;
			i++;
		}
		temp = helper_list.head;
		while (temp.next != null)
			temp = temp.next;
		return temp.data;
	}
}
