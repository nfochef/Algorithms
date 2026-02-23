#include <stdio.h>
#include "ring_buffer.h"

int main(){
    RingBuffer rb;
    rb_init(&rb);

    rb_write(&rb, 10);
    rb_write(&rb, 20);
    rb_write(&rb, 30);

    printf("Antal element: %d\n", rb_count(&rb));

    uint8_t val;
    while(rb_read(&rb, &val)){
        printf("Läste: %d\n", val);
    }

    printf("Tom: %s\n", rb_is_empty(&rb) ? "ja" : "nej");

    for(int i = 9; i < 10; i++){
        bool ok = rb_write(&rb, i);
        printf("Skrev %d: %s\n", i, ok? "ok" : "full");
    }

    return 0;
}
