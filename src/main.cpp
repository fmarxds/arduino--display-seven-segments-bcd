#include <Arduino.h>

#define BCD_A 12
#define BCD_B 9
#define BCD_C 10
#define BCD_D 11

const uint8_t binaries[10][4] = {
        {LOW,  LOW,  LOW,  LOW},
        {LOW,  LOW,  LOW,  HIGH},
        {LOW,  LOW,  HIGH, LOW},
        {LOW,  LOW,  HIGH, HIGH},
        {LOW,  HIGH, LOW,  LOW},
        {LOW,  HIGH, LOW,  HIGH},
        {LOW,  HIGH, HIGH, LOW},
        {LOW,  HIGH, HIGH, HIGH},
        {HIGH, LOW,  LOW,  LOW},
        {HIGH, LOW,  LOW,  HIGH}
};

void setup() {
    Serial.begin(9600);
    pinMode(BCD_A, OUTPUT);
    pinMode(BCD_B, OUTPUT);
    pinMode(BCD_C, OUTPUT);
    pinMode(BCD_D, OUTPUT);
}

void display(int num) {
    digitalWrite(BCD_A, binaries[num][3]);
    digitalWrite(BCD_B, binaries[num][2]);
    digitalWrite(BCD_C, binaries[num][1]);
    digitalWrite(BCD_D, binaries[num][0]);
}

void loop() {
    if (Serial.available()) {
        int number = Serial.read() - 48;
        if (number >= 0 && number <= 9) {
            display(number);
        } else {
            Serial.println("Only integers between 0 and 9!");
        }
    }
}