#include <stddef.h>
#include <stdlib.h>

#ifndef QUEUE_H
#define QUEUE_H

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
void add_q(struct queue* q, void* data);
void* pop_q(struct queue* q);
void free_q(struct queue* q);

#endif