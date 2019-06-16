/* Christopher Feener
 * 12 June 2019
 * Removes duplicates in a linked list.
 */

package p2_1_removeDups;

import java.util.LinkedList;	//For the resulting linked list only.

public class Main {

	public static void main(String[] args) {
		System.out.println("Before: ");
		
		RemoveDups list = new RemoveDups(1,1,1,1,1/*8, 1, 0, 2, 9, 1,
				0, 0, 2, 3, 0, 6*/);	//Specialized LinkedList for this exercise.

		int i = 0, j = 0;
		for (Integer a : list) {
			for (Integer b : list) {
				if (i == j)
					continue;
				if (a == b)
					list.markAsDup(j);
				j++;
			}
			j = 0;
			i++;
		}
		
		/* Solution 1: New list*/
		LinkedList <Integer> result = new LinkedList <Integer>();
		
		System.out.println("After: ");
		
		i = 0;
		for (Integer a : list) {
			if (list.is_dup[i] == false) {
				result.add(a);
				System.out.println("" + a);
			}
			i++;
		}

	}

}
