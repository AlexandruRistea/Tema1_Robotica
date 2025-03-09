# Tema 1 

# Charging Station Simulation

This Arduino-based project simulates a charging station using buttons, LEDs, and an RGB LED to indicate charging status. The system allows a user to start and stop the charging process using physical buttons.

## Features

Start Charging: Pressing the Start button initiates the charging process.

Stop Charging: Pressing the Stop button immediately halts charging.

LED Indicators:

RGB LED indicates the current state:

🟢 Green: Idle/Charging complete

🔴 Red: Charging in progress

Four sequential LEDs blink to simulate charging.

Debouncing Mechanism: Implements basic debounce handling for button presses.

Components Used

Arduino Board

Push Buttons (2x)

RGB LED (1x)

Single-color LEDs (4x, representing charge levels)

Resistors (as required for LEDs and buttons)

Breadboard and jumper wires

Pin Configuration

| Component       | Pin |
| --------------- | --- |
| Start Button    | 2   |
| Stop Button     | 3   |
| RGB LED - Red   | 6   |
| RGB LED - Green | 5   |
| RGB LED - Blue  | 4   |
| LED 1           | 10  |
| LED 2           | 9   |
| LED 3           | 8   |
| LED 4           | 7   |

## How It Works

Initial State: The RGB LED is green, indicating the system is ready.

Start Charging: When the Start button is pressed:

The RGB LED turns red.

The four LEDs light up sequentially, simulating the charging process.

Stop Charging: If the Stop button is pressed at any time:

The system stops immediately.

The finish animation (blinking LEDs) is played.

The RGB LED turns green.

Charging Complete: When all four LEDs finish blinking, the system resets.

## Code Explanation

The program follows these key steps:

It monitors button states using digitalRead.

A simple debounce mechanism prevents accidental multiple detections.

The startCharging() function lights up LEDs sequentially.

The stopCharging() function stops the process and resets indicators.

The finishCharging() function blinks all LEDs three times, signaling the end.

## Installation & Upload

Connect the components as per the pin configuration.

Open the Arduino IDE and select the correct board and port.

Upload the provided code.

Press the Start button to begin the simulation!

## Possible Improvements

Implement hardware debounce using capacitors or pull-down resistors.

Use interrupts instead of delay() for a more responsive system.

Add a display to show charging percentage in real time.
