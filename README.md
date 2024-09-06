# Multi-Sensor 4CH LM35 Temperature Display with LCD

## Description

This project reads analog values from four sensors and displays the calculated temperature values (T1, T2, T3, and T4) on a 16x2 LCD screen. The temperature data is updated periodically and shown in two rows on the LCD. This setup is suitable for monitoring multiple temperature sources in a compact, visual way.

## Components

- Arduino Uno
- 16x2 LCD Display
- 4 Analog Sensors (e.g., temperature sensors)
- Jumper wires
- Breadboard

## Libraries Required

- **LiquidCrystal.h**: For handling the 16x2 LCD display.

## Wiring Diagram

| Component         | Arduino Pin |
| ----------------- | ----------- |
| LCD RS            | 2           |
| LCD Enable        | 3           |
| LCD D4            | 4           |
| LCD D5            | 5           |
| LCD D6            | 6           |
| LCD D7            | 7           |
| Sensor 1 (Analog) | A0          |
| Sensor 2 (Analog) | A1          |
| Sensor 3 (Analog) | A2          |
| Sensor 4 (Analog) | A3          |

## Code

```cpp
#include <LiquidCrystal.h>

// Initialize the LCD (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

int adc, T1, T2, T3, T4;

void setup() {
  lcd.begin(16, 2);  // Set up the LCD's number of columns and rows
  delay(1000);       // Initial delay for stabilization
}

void loop() {
  // Read analog values from each sensor and convert to temperature
  adc = analogRead(0);
  T1 = (adc * 5) / 10;
  delay(100);

  adc = analogRead(1);
  T2 = (adc * 5) / 10;
  delay(100);

  adc = analogRead(2);
  T3 = (adc * 5) / 10;
  delay(100);

  adc = analogRead(3);
  T4 = (adc * 5) / 10;
  delay(100);

  // Display the temperature values on the LCD
  lcd.setCursor(0, 0);
  lcd.print("T1=");
  lcd.print(T1);
  lcd.print(" T2=");
  lcd.print(T2);

  lcd.setCursor(0, 1);
  lcd.print("T3=");
  lcd.print(T3);
  lcd.print(" T4=");
  lcd.print(T4);

  delay(1000); // Delay before updating values
}
```

## How It Works

1. Sensor Input: The Arduino reads analog signals from four analog input pins (A0 to A3), where each is connected to a sensor.
2. Temperature Calculation: The raw analog values are converted into approximate temperature readings using a simple formula (T = (adc \* 5) / 10).
3. LCD Display: The temperature values are printed on a 16x2 LCD display. T1 and T2 are shown on the first row, while T3 and T4 are displayed on the second row.
4. Periodic Update: The readings are refreshed every second to provide real-time monitoring.

## Usage

1. Connect the components according to the wiring diagram.
2. Upload the code to your Arduino.
3. The temperature readings will be displayed on the LCD for each sensor connected.

## Applications

- Monitoring temperature in multiple zones (e.g., in a room, machinery, or outdoor conditions).
- Educational projects involving temperature sensors and LCD output.
