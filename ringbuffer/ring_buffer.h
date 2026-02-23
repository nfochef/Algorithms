#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdint.h>
#include <stdbool.h>
#define BUFFER_SIZE 8       // 2-potens

// head=nästa läsposition tail= nästa skriv position count=antal element just nu

typedef struct{
    uint8_t data[BUFFER_SIZE];
    uint8_t head;
    uint8_t tail;
    uint8_t count;
}RingBuffer;

void rb_init (RingBuffer *rb);
bool rb_write (RingBuffer *rb, uint8_t byte);
bool rb_read (RingBuffer *rb, uint8_t *byte);
bool rb_is_empty(RingBuffer *rb);
bool rb_is_full (RingBuffer *rb);

uint8_t rb_count (RingBuffer *rb);

#endif
