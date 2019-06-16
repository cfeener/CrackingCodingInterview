/* Christopher Feener
 * 12 June 2019
 */

package p2_1_removeDups;

import java.util.LinkedList;

public class RemoveDups extends LinkedList<Integer>{
	/** Added on 6/12/2019
	 *  Requested by Eclipse.
	 */
	private static final long serialVersionUID = 1435215341850384229L;
	static int dups = 0;
	static int n = 0;
	boolean is_dup[];
	
	public RemoveDups(int ...a) {	//Constructor!
		super();
		for (int i : a) {
			this.add(i);
			n++;
			System.out.println("" + i);	//Debug
		}
		is_dup = new boolean [n];
	}

	public boolean markAsDup(int x) {	//Pass index x.
		if (this.get(x) == null)
			return false;
		is_dup[x] = true;	//Mark as duplicate; will not copy into new array.
		dups++;
		return true;
	}
}
