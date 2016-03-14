#include <breezystm32.h>

#include "board.h"

extern serialPort_t * Serial1;

void board_checkReboot(bool pendReboot)
{
    if (pendReboot)
        systemReset(false); // noreturn
}

void board_reboot(void)
{
    systemReset(true);      // reboot to bootloader
}

uint16_t board_getI2cErrorCounter(void)
{
    return i2cGetErrorCounter();
}


uint32_t board_getMicros()
{
    return micros();
}

bool board_serialAvailable(void)
{
    return serialTotalBytesWaiting(Serial1) > 0;
}

uint8_t board_serialRead(void)
{
    return serialRead(Serial1);
}

void board_serialWrite(uint8_t c)
{
    serialWrite(Serial1, c);
}

void board_writeMotor(uint8_t index, uint16_t value)
{
    pwmWriteMotor(index, value);
}