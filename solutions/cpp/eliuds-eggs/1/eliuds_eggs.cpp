#include "eliuds_eggs.h"


/*
    Iteration 1: 
        num = 89    1 0 1 1 0 0 1 
        num-1 = 88  1 0 1 1 0 0 0 

        num = 89 & 88 = 88 → 1 0 1 1 0 0 0 (removed rightmost 1) 
        count = 1


    Iteration 2: 
        num = 88    1 0 1 1 0 0 0 
        num-1 = 87  1 0 1 0 1 1 1 

        num = 88 & 87 = 80 → 1 0 1 0 0 0 0 (removed next 1)
        count = 2

    Iteration 3: 
        num = 80    1 0 1 0 0 0 0 
        num-1 = 79  1 0 0 1 1 1 1 

        num = 80 & 79 = 64 → 1 0 0 0 0 0 0 (removed next 1) 
        count = 3

    Iteration 4: 
        num = 64    1 0 0 0 0 0 0 
        num-1 = 63  0 1 1 1 1 1 1 

        num = 64 & 63 = 0 → 0 0 0 0 0 0 0 (removed last 1) 
        count = 4
*/

namespace chicken_coop {

	int positions_to_quantity(int num) {

        int count = 0;

        while (num != 0)
        {
            num = num & (num - 1);   // The magic line
            count++;
        }
        return count;
	}

}  // namespace chicken_coop
