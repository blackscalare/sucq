#include <stddef.h>
#include <stdlib.h>

#ifndef QUEUE_H
#define QUEUE_H

typedef enum
{
    QUEUE_IS_FULL,
    QUEUE_IS_EMPTY,
    MALLOC_FAILED,
    SUCCESS
} queue_message_e;

struct item
{
    void* data; // can be any type
    struct item* next;
};

struct queue
{
    struct item* head, *tail;
    size_t size, max_size;
};


struct queue* create_queue(size_t max_size);
queue_message_e add_q(struct queue* q, void* data);
void* pop_q(struct queue* q);
queue_message_e free_q(struct queue* q);

#endif