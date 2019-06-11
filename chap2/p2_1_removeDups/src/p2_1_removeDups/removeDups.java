package p2_1_removeDups;

import java.util.LinkedList;

public class removeDups {
	LinkedList <Integer> ll = new LinkedList<Integer>();

	public LinkedList<Integer> getLl() {
		return ll;
	}

	public void setLl(LinkedList<Integer> ll) {
		this.ll = ll;
	}
	
	void add(Integer i) {
		this.add(i);
	}
	
	void set(int x) {
		assert(this.ll.get(x) != null);
		this.ll.set(x, -1);	//Mark as duplicate; will not copy into new array.
	}
}
