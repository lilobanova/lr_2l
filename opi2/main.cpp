#include <stdio.h>;
#include <iostream>;
#include <windows.h>;

using namespace std

struct comp {
	int Data;
	comp *next;
};

void s_push(comp **top, int D) {
	comp *q;
	q = new comp();
	q->Data = D;
	if (top == NULL) {
		*top = q;
	}
	else
	{
		q->next = *top;
		*top = q;
	}
}
