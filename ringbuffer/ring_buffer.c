
Ring Buffer implementation
 * 2026
 * Lärt mig av: https://www.embedded.com/ring-buffer-basics/ &
 * med stöd av tredjepartstänkaren Ai som bollplank
 * för att buffera sensordata från UART
 

 *head pekar på nästa läsposition
 * tail pekar på nästa skrivposition
 * count håller koll på hur många element som faktiskt finns där.
 */

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
/* Returnerar false istället för att tysta skriva över gammal data.
 * I ett UART-scenario är det bättre att droppa ny data än att
 * korruptera gammal kallas "drop on full" policy */

bool rb_write(RingBuffer *rb, uint8_t byte){
    if(rb_is_full(rb)) return false;
    rb->data[rb->tail] = byte;
    rb->tail = (rb->tail + 1) % BUFFER_SIZE;
    rb->count++;
    return true;
}

/* Läser ut äldsta värdet (FIFO ordningen)
 * head avancerar frammåt, och "wrappas" med samma modulus trick som write */

bool rb_read(RingBuffer *rb, uint8_t *byte){
    if(rb_is_empty(rb)) return false;
    *byte = rb->data[rb->head];
    rb->head = (rb->head + 1) % BUFFER_SIZE;
    rb->count--;
    return true;
}
