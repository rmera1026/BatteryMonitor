#include "adc_voltage.h"
#include "main.h"

extern ADC_HandleTypeDef hadc1;

uint32_t ADC_ReadVoltage_cV(void)
{
    uint32_t sum = 0;
    for (int i = 0; i < 10; i++) {
        HAL_ADC_Start(&hadc1);
        HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
        sum += HAL_ADC_GetValue(&hadc1);
    }
    uint32_t raw = sum / 10;

    if (raw < 15) return 0;  /* noise floor — no signal connected */

    uint32_t adc_cV = (raw * 330UL) / 4095UL;
    uint32_t vin_cV = (adc_cV * 13000UL) / 3000UL;  /* 10k/3k divider */
    return vin_cV;
}
