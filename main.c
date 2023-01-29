#include <stdio.h>
#include <pico/stdlib.h>
#include "hardware/gpio.h"
#include "hardware/adc.h"

int main()
{
    stdio_init_all();

    adc_init();

    // Ensure GPIO is high-impedance, with no pull-ups.
    adc_gpio_init(28);
    // Selecty ADC input 2
    adc_select_input(2);

    while (1)
    {
        // 12-bit conversion, assume max value == ADC_VREF == 3.3 V
        //const float conversion_factor = 3.3f / (1 << 12);
        uint16_t result = adc_read();
        //printf("Raw value: %d, voltage: %f V\n", result, result * conversion_factor);
        printf("%d\n", result);
        sleep_ms(20);
    }
    return 0;
}
