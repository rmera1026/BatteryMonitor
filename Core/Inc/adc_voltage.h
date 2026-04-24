#ifndef ADC_VOLTAGE_H
#define ADC_VOLTAGE_H

#include <stdint.h>

/* Returns input voltage in centivolts (e.g. 515 = 5.15 V).
   Returns 0 when no signal detected (below noise floor). */
uint32_t ADC_ReadVoltage_cV(void);

#endif /* ADC_VOLTAGE_H */
