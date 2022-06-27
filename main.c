#include "queue.h"
#include <stdio.h>

static struct random
{
    int value;
    char* string;
} random_t;

int main()
{
    struct random s0 = {.value = 1337, .string = "a"};
    struct random s1 = {.value = 2674, .string = "bad"};
    struct random s2 = {.value = 5348, .string = "test"};

    struct queue* q = create_queue(3);
    add_q(q, &s0);
    add_q(q, &s1);
    add_q(q, &s2);

    for(int i = 0; i < 3; ++i) {
        struct random* ss = (struct random*)pop_q(q);
        printf("item %i\n", i);
        printf("%i %s\n", (int)(ss->value), (char*)(ss->string));
        printf("Queue size: %lu", q->size);
        printf("\n\n");
    }



    return 0;
}