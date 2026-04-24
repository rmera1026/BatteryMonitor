#ifndef UI_H
#define UI_H

#include <stdint.h>

void UI_ShowIntro(void);
void UI_ShowVoltage(uint32_t vin_cV);
void UI_ShowLowBattery(uint32_t vin_cV);

#endif /* UI_H */
