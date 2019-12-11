#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
	int data; // тут тримаєш двоцифрове число
	struct _Node *next; // вказівник на наступний елемент
	struct _Node *prev; // вказівник на попередній елемент
}Node;

typedef struct _DbLinkedList
{
	int size;  // розмір списку
	Node *head; // вказівник на початок списку
	Node *tail; // вказівник на кінець списку
}DbLinkedList;

DbLinkedList * createDbLinkedList(); // прототип функції для створення списку
void deleteDbLinkedList(DbLinkedList **list); // прототип для видалення списку
void pushFront(DbLinkedList *list, int data); // додавання елементу в список на початок
void printDbLinkedList(DbLinkedList *list); // видрук елементу


int main()
{
	DbLinkedList *list = createDbLinkedList(); //оголосили список
	int a, b, c, d;

	scanf("%d %d %d %d", &a, &b, &c, &d);

	pushFront(list, a);
	pushFront(list, b);
	pushFront(list, c);
	pushFront(list, d);
	puts(" ");
	printDbLinkedList(list);
	deleteDbLinkedList(&list);
	system("pause");
	return 0;
}

DbLinkedList * createDbLinkedList(DbLinkedList **list)
{
	DbLinkedList *tmp = (DbLinkedList*)malloc(sizeof(DbLinkedList));
	tmp->size = 0;
	tmp->head = tmp->tail = NULL;
	return tmp;
}

void deleteDbLinkedList(DbLinkedList **list)
{
	Node *tmp = (*list)->head;
	Node *next = NULL;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(*list);
	(*list) = NULL;
}

void pushFront(DbLinkedList *list, int val)
{
	Node *tmp = (Node*)malloc(sizeof(Node));
	if (tmp == NULL)
	{
		exit(1);
	}
	tmp->data = val;
	tmp->next = list->head;
	tmp->prev = NULL;
	if (list->head)
	{
		list->head->prev = tmp;
	}
	list->head = tmp;
	if (list->tail == NULL)
	{
		list->tail = tmp;
	}
	list->size++;
}

void printDbLinkedList(DbLinkedList *list)
{
	Node *tmp = list->head;
	while (tmp)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}