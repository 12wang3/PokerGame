#include "checkString.h"

int main(void)
{
	pokerStringType pst;
	pst.addPoker("DIAMONDS",9);
	pst.addPoker("CLUBS",2);
	pst.addPoker("HEARTS",10);
	pst.addPoker("DIAMONDS",13);
	pst.addPoker("SPADES",7);
	pst.addPoker("DIAMONDS",8);
	pst.display();
	printf ("%d\n",pst.calcValue());
	return 0;
}