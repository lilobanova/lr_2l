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

void s_print(comp *top) { //принимает указатель на вершину стека
	comp *q = top; //устанавливаем q на вершину
	while (q) { //пока q не пустой (while(q) эквивалентно while(q != NULL))
		printf_s("%i", q->Data);//выводим на экран данные ячейки стека
		q = q->next;//после того как вывели передвигаем q на следующий элемент(ячейку)
	}
}
int main() {
	comp *top = NULL; //в начале программы у нас нет очереди, соответственно вершины нет, даем ей значение NULL
	//Дальше начинаем добавлять цифры от 1 до 5 в наш стек
		s_push(&top, 54);
		s_push(&top, 53);
		s_push(&top, 3);
		s_push(&top, 4);
		s_push(&top, 5);
	//после выполнения функций в стеке у нас будет 54321
	s_print(top);//выводим
	s_delete_key(&top, 4); //Затем удаляем 4, в стеке получается 5321
	printf_s("\n");//переводим на новую строку
	s_print(top);//выводим
	system("pause");//ставим на паузу
}
