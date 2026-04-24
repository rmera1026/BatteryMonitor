#ifndef BUTTON_H
#define BUTTON_H

#include <stdint.h>

/* Call once per loop iteration */
void Button_Update(void);

/* Returns 1 once per press, then clears automatically */
uint8_t Button_WasPressed(void);

#endif /* BUTTON_H */
