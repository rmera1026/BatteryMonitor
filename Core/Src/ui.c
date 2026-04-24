#include "ui.h"
#include "ssd1306.h"
#include "ssd1306_fonts.h"
#include <stdio.h>

void UI_ShowIntro(void)
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString("Voltage/Current", Font_7x10, White);
    ssd1306_SetCursor(0, 12);
    ssd1306_WriteString("Monitor", Font_7x10, White);
    ssd1306_SetCursor(0, 32);
    ssd1306_WriteString("Press button to", Font_7x10, White);
    ssd1306_SetCursor(0, 44);
    ssd1306_WriteString("show measurements.", Font_7x10, White);
    ssd1306_UpdateScreen();
}

void UI_ShowVoltage(uint32_t vin_cV)
{
    char buf[32];
    snprintf(buf, sizeof(buf), "Vin: ~%lu.%02luV", vin_cV / 100, vin_cV % 100);
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString(buf, Font_7x10, White);
    ssd1306_UpdateScreen();
}

void UI_ShowLowBattery(uint32_t vin_cV)
{
    char buf[32];
    snprintf(buf, sizeof(buf), "%lu.%02luV", vin_cV / 100, vin_cV % 100);
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString("! LOW BATTERY !", Font_7x10, White);
    ssd1306_SetCursor(0, 20);
    ssd1306_WriteString(buf, Font_7x10, White);
    ssd1306_UpdateScreen();
}
