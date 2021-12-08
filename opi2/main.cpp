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
				q->Data = NULL;  //или числа  "-2738568384" или других, в зависимости от компилятора.
				q->next = NULL;
			}
			else//если элемент последний или находится между двумя другими элементами
			{
				prev->next = q->next;//Проводим связь от предыдущего элемента к следующему
				free(q);//очищаем ячейку
				q->Data = NULL;//обнуляем переменные
				q->next = NULL;
			}
		}// если Data элемента НЕ равна числу, которое нам нужно удалить
		prev = q; //запоминаем текущую ячейку как предыдущую
		q = q->next;//перемещаем указатель q на следующий элемент
	}

}
