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

void s_delete_key(comp **top, int N) {
	comp *q = *top;
	comp *prev = NULL;
	while (q != NULL) {
		if (q->Data == N) {
			if (q == *top) {
				*top = q->next;
				free(q);
				q->Data = NULL;  //или числа  "-2738568384" или других, в зависимости от компил€тора.
				q->next = NULL;
			}
			else//если элемент последний или находитс€ между двум€ другими элементами
			{
				prev->next = q->next;//ѕроводим св€зь от предыдущего элемента к следующему
				free(q);//очищаем €чейку
				q->Data = NULL;//обнул€ем переменные
				q->next = NULL;
			}
		}// если Data элемента Ќ≈ равна числу, которое нам нужно удалить
		prev = q; //запоминаем текущую €чейку как предыдущую
		q = q->next;//перемещаем указатель q на следующий элемент
	}

}

void s_print(comp *top) { //принимает указатель на вершину стека
	comp *q = top; //устанавливаем q на вершину
	while (q) { //пока q не пустой (while(q) эквивалентно while(q != NULL))
		printf_s("%i", q->Data);//выводим на экран данные €чейки стека
		q = q->next;//после того как вывели передвигаем q на следующий элемент(€чейку)
	}
}
