/* Ring Buffer - Cirkulär FIFO-buffert
 * Jens L, 2026
 * Källa: https://www.embedded.com/ring-buffer-basics/ &
 * med stöd av tredjepartstänkaren Ai som bollplank.
 *
 * Varför ring buffer och inte vanlig array?
 * En vanlig array kräver att alla element flyttas vid varje läsning = O(n).
 * Ring buffer använder bara två pekare (head/tail) som rör sig framåt = O(1).
 * Ingen dynamic memory allocation
 *
 * Tänkt användning: buffera sensordata från UART-interrupt på ESP32
 * innan main loop hinner processa det.
 */



#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdint.h>
#include <stdbool.h>
#define BUFFER_SIZE 8   

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
