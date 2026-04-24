#include "button.h"
#include "main.h"

static GPIO_PinState prev_state = GPIO_PIN_SET;
static uint8_t pressed_flag = 0;

void Button_Update(void)
{
    GPIO_PinState now = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13);

    if ((prev_state == GPIO_PIN_SET) && (now == GPIO_PIN_RESET)) {
        HAL_Delay(30);  /* debounce */
        if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_RESET) {
            pressed_flag = 1;
            /* wait for release so one press = one toggle */
            while (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_RESET) {
                HAL_Delay(10);
            }
        }
    }

    prev_state = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13);
}

uint8_t Button_WasPressed(void)
{
    if (pressed_flag) {
        pressed_flag = 0;
        return 1;
    }
    return 0;
}
