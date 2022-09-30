#include "queue.h"
#include <stdio.h>

struct queue* create_queue(size_t max_size)
{
    struct queue* q = malloc(sizeof(struct queue) * max_size);
    q->max_size = max_size;
    q->size = 0;
    q->head = NULL;
    q->tail = NULL;

    return q;
}

queue_message_e add_q(struct queue* q, void* data)
{
    if(q->size >= q->max_size)
    {
        perror("Queue is full\n");
        return QUEUE_IS_FULL;
    }
    
    struct item* i = malloc(sizeof(struct item));

    if(i == NULL)
    {
        perror("malloc created null structure\n");
        return MALLOC_FAILED;
    }

    i->data = data;

    if(q->size == 0)
    {
        i->next = NULL;
        q->head = i;
        q->tail = i;
        q->size++;
        return;
    }

    q->tail->next = i;   
    q->tail = i;
    q->size++;

    return SUCCESS;
}

void* pop_q(struct queue* q)
{
    if(q->size == 0)
    {
        perror("Cannot pop, size is 0\n");
        return NULL;
    }

    void* data = NULL;
    struct item* tmp = NULL;

    data = q->head->data;
    tmp = q->head;
    q->head = q->head->next;
    q->size--;

    free(tmp);

    return data;
}

queue_message_e free_q(struct queue* q)
{
    if(q->size < 0)
    {
        perror("Queue size is 0");
        return QUEUE_IS_EMPTY;
    }

    while(q->head != NULL)
    {
        struct item* tmp = q->head;
        q->head = q->head->next;

        if(tmp->data != NULL)
        {
            free(tmp->data);
        }

        free(tmp);
    }

    if(q->tail != NULL)
        free(q->tail);

    free(q);

    return SUCCESS;
}