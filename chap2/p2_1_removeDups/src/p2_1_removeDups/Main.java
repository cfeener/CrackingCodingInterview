/* Christopher Feener
 * 12 June 2019
 * Removes duplicates in a linked list.
 */

package p2_1_removeDups;

import java.util.LinkedList;	//For the resulting linked list only.

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("Before: ");
		
		RemoveDups list = new RemoveDups(8, 1, 0, 2, 9, 1,
				0, 0, 2, 3, 0, 6);	//Specialized LinkedList for this exercise.

		int i = 0, j = 0;
		for (Integer a : list) {
			if (list.get(i) == -1)
				continue;
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
		
		LinkedList <Integer> result = new LinkedList <Integer>();
		
		System.out.println("After: ");
		
		for (Integer a : list) {
			if (a != -1) {
				result.add(a);
				System.out.println("" + a);
			}
		}
	}

}
