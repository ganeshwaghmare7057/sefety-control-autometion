#include <lpc214x.h>

void delay(unsigned int time) {
    unsigned int i, j;
    for (i = 0; i < time; i++)
        for (j = 0; j < 3000; j++);
}

void GPIO_Init() {
    PINSEL0 &= ~(3 << 20); // Set P0.10 as GPIO
    IO0DIR &= ~(1 << 10); // Set P0.10 as input
}

int main() {
    GPIO_Init();
    unsigned int object_detected;

    while (1) {
        object_detected = IO0PIN & (1 << 10); // Read the status of P0.10
        if (object_detected) {
            // Object detected
            // Implement the action to be taken on object detection
        } else {
            // No object detected
        }
        delay(1000); // Delay between readings
    }
}
