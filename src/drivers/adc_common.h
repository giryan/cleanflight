#pragma once

typedef enum {
    ADC_BATTERY = 0,
    ADC_EXTERNAL1 = 1,
    ADC_EXTERNAL2 = 2,
    ADC_CHANNEL_MAX = ADC_EXTERNAL2
} AdcChannel;

#define ADC_CHANNEL_COUNT (ADC_CHANNEL_MAX + 1)

typedef struct adc_config_t {
    uint8_t adcChannel;         // ADC1_INxx channel number
    uint8_t dmaIndex;           // index into DMA buffer in case of sparse channels
} adc_config_t;

typedef struct drv_adc_config_t {
    uint8_t powerAdcChannel;     // which channel used for current monitor, allowed PA1, PB1 (ADC_Channel_1, ADC_Channel_9)
} drv_adc_config_t;

void adcInit(drv_adc_config_t *init);
uint16_t adcGetChannel(uint8_t channel);