#include "ring_buffer.h"

void rb_init(RingBuffer *rb){
    rb->head  = 0;
    rb->tail  = 0;
    rb->count = 0;
}

bool rb_is_empty(RingBuffer *rb){
    return rb->count == 0;
}

bool rb_is_full(RingBuffer *rb){
    return rb->count == BUFFER_SIZE;
}

uint8_t rb_count(RingBuffer *rb){
    return rb->count;
}

bool rb_write(RingBuffer *rb, uint8_t byte){
    if(rb_is_full(rb)) return false;
    rb->data[rb->tail] = byte;
    rb->tail = (rb->tail + 1) % BUFFER_SIZE;
    rb->count++;
    return true;
}

bool rb_read(RingBuffer *rb, uint8_t *byte){
    if(rb_is_empty(rb)) return false;
    *byte = rb->data[rb->head];
    rb->head = (rb->head + 1) % BUFFER_SIZE;
    rb->count--;
    return true;
}
