// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (C) 2013 Davidlohr Bueso <davidlohr.bueso@hp.com>
 *
 *  Based on the shift-and-subtract algorithm for computing integer
 *  square root from Guy L. Steele.
 */

#include <linux/kernel.h>
#include <linux/export.h>
#include <linux/bitops.h>

/**
 * int_sqrt - rough approximation to sqrt
 * @x: integer of which to calculate the sqrt
 *
 * A very rough approximation to the sqrt() function.
 */
inline unsigned long int_sqrt(unsigned long x)
{
	register unsigned long tmp;
	register unsigned long place;
	register unsigned long root = 0;

	if (x <= 1)
		return x;

	place = 1UL << (BITS_PER_LONG - 2);

<<<<<<< HEAD
	do{
		place >>= 2;
	}while(place > x);
=======
	do {
		place >>= 2;
	} while(place > x);
>>>>>>> ed7c901e0150 (lib: int_sqrt: Improve 3x faster integer sqrt.)

	do {
		tmp = root + place;
		root >>= 1;

<<<<<<< HEAD
		if (x >= tmp)
		{
=======
		if (x >= tmp) {
>>>>>>> ed7c901e0150 (lib: int_sqrt: Improve 3x faster integer sqrt.)
			x -= tmp;
			root += place;
		}
		place >>= 2;
<<<<<<< HEAD
	}while (place != 0);
=======
	} while (place != 0);
>>>>>>> ed7c901e0150 (lib: int_sqrt: Improve 3x faster integer sqrt.)

	return root;
}
EXPORT_SYMBOL(int_sqrt);
