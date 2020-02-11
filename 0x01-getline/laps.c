#include "laps.h"

/**
 * check_id - checks if id is in list
 * @head: head of list of cars
 * @id: id to search for
 * Return: pointer to node with id otherwise NULL
 */
car_t *check_id(car_t *head, int id)
{
	while (head != NULL)
	{
		if (head->id == id)
			return (head);
		head = head->next;
	}
	return (NULL);
}

/**
 * free_list - frees a linked-list
 * @head: head of list
 * Return: void
 */
void free_list(car_t *head)
{
	car_t *next;

	if (head == NULL)
		return;

	next = head;
	while (next != NULL)
	{
		next = next->next;
		free(head);
		head = next;
	}
}

/**
 * insert_car - inserts a car node into the list of cars
 * @head: pointer to pointer of head of list
 * @id: id of new car
 * Return: new list
 */
car_t *insert_car(car_t **head, int id)
{
	car_t *current = NULL;
	car_t *new = NULL;

	if (!head)
		return (NULL);

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->id = id;
	new->laps = 0;
	new->next = NULL;
	printf("Car %d joined the race\n", new->id);

	if (!*head)
		return (new);

	current = (*head);
	if (id < current->id)
	{
		new->next = *head;
		*head = new;
	}
	else
	{
		while (current->next && current->next->id < id)
			current = current->next;

		new->next = current->next;
		current->next = new;
	}
	return (*head);
}

/**
 * print_cars - prints list of cars in race
 * @list: list of cars
 * Return: void
 */
void print_cars(car_t *list)
{
	car_t *current;

	current = list;

	while (current != NULL)
	{
		printf("Car %d [%lu laps]\n", current->id, current->laps);
		current = current->next;
	}
}

/**
 * race_state - keeps track of the number of laps made by several
 * cars in a race
 * @id: array of int representing the "identifier" of each car
 * @size: size of array
 * Return: void
 */
void race_state(int *id, size_t size)
{
	static car_t *car;
	car_t *check;
	size_t i = 0;

	if (size == 0)
	{
		free_list(car);
		return;
	}

	if (car == NULL)
	{
		car = insert_car(&car, id[0]);
		car->laps--;
	}
	for (i = 0; i < size; i++)
	{
		check = check_id(car, id[i]);
		if (!check)
			insert_car(&car, id[i]);
		else
			check->laps++;
	}

	printf("Race state:\n");
	print_cars(car);
}
