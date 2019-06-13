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
	
	public RemoveDups(int ...a) {	//Constructor!
		super();
		for (int i : a) {
			this.add(i);
			System.out.println("" + i);
		}
	}

	public boolean markAsDup(int x) {
		if (this.get(x) == null)
			return false;
		this.set(x, -1);	//Mark as duplicate; will not copy into new array.
		return true;
	}
}
