#ifndef LAPS_H
#define LAPS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * struct car - singly-linked list
 * @id: ID of car
 * @laps: laps car has completed 
 * @next: next car
 */
typedef struct car
{
	int id;
	size_t laps;
	struct car *next;
} car_t;

car_t *check_id(car_t *head, int id);
car_t *insert_car(car_t **head, int id);
void free_list(car_t *head);
void print_cars(car_t *list);
void race_state(int *id, size_t size);

#endif /*LAPS_H*/
