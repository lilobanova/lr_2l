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
				q->Data = NULL;  //��� �����  "-2738568384" ��� ������, � ����������� �� �����������.
				q->next = NULL;
			}
			else//���� ������� ��������� ��� ��������� ����� ����� ������� ����������
			{
				prev->next = q->next;//�������� ����� �� ����������� �������� � ����������
				free(q);//������� ������
				q->Data = NULL;//�������� ����������
				q->next = NULL;
			}
		}// ���� Data �������� �� ����� �����, ������� ��� ����� �������
		prev = q; //���������� ������� ������ ��� ����������
		q = q->next;//���������� ��������� q �� ��������� �������
	}

}

void s_print(comp *top) { //��������� ��������� �� ������� �����
	comp *q = top; //������������� q �� �������
	while (q) { //���� q �� ������ (while(q) ������������ while(q != NULL))
		printf_s("%i", q->Data);//������� �� ����� ������ ������ �����
		q = q->next;//����� ���� ��� ������ ����������� q �� ��������� �������(������)
	}
}
int main() {
	comp *top = NULL; //� ������ ��������� � ��� ��� �������, �������������� ������� ���, ���� �� �������� NULL
	//������ �������� ��������� ����� �� 1 �� 5 � ��� ����
		s_push(&top, 54);
		s_push(&top, 53);
		s_push(&top, 3);
		s_push(&top, 4);
		s_push(&top, 5);
	//����� ���������� ������� � ����� � ��� ����� 54321
	s_print(top);//�������
	s_delete_key(&top, 4); //����� ������� 4, � ����� ���������� 5321
	printf_s("\n");//��������� �� ����� ������
	s_print(top);//�������
	system("pause");//������ �� �����
}
