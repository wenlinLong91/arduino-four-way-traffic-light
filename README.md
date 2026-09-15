# Arduino Four-Way Traffic Light Simulation

## Project Overview

This project implements a fixed-time four-way traffic light control system using an Arduino Uno. The circuit and traffic-light sequence were designed and simulated in Wokwi, while PlatformIO was used to manage and compile the Arduino C++ project.

The four traffic-light heads are organized into two phases. Opposing directions share the same signal state, allowing one pair of directions to proceed while the other pair remains stopped.

## Tools and Technologies

* Arduino Uno
* Arduino C++
* Wokwi
* PlatformIO
* Visual Studio Code
* Red, yellow and green LEDs
* 220-ohm resistors

## System Design

The intersection contains four traffic-light heads with 12 LEDs in total. The lights operate as two coordinated phases:

* Phase 1 controls one pair of opposing directions.
* Phase 2 controls the other pair of opposing directions.
* Only one phase displays a green signal at a time.
* A yellow transition is applied before each phase changes to red.
* An all-red interval is included between phases to improve intersection safety.

## Signal Timing

| Setting            |   Duration |
| ------------------ | ---------: |
| Total cycle        | 60 seconds |
| Phase 1 green      | 25 seconds |
| Phase 1 yellow     |  3 seconds |
| All-red transition |  2 seconds |
| Phase 2 green      | 25 seconds |
| Phase 2 yellow     |  3 seconds |
| All-red transition |  2 seconds |

The green time is calculated dynamically from the total cycle time after subtracting the yellow and all-red intervals.

## Pin Configuration

| Signal         | Arduino pin |
| -------------- | ----------: |
| Phase 1 green  |           2 |
| Phase 1 yellow |           3 |
| Phase 1 red    |           4 |
| Phase 2 green  |           5 |
| Phase 2 yellow |           6 |
| Phase 2 red    |           7 |

Opposing traffic-light heads are connected to the same phase pins so that they operate together.

## Control Sequence

1. Both phases start with red signals.
2. Phase 1 changes to green while Phase 2 remains red.
3. Phase 1 changes from green to yellow.
4. Both phases remain red for two seconds.
5. Phase 2 changes to green while Phase 1 remains red.
6. Phase 2 changes from green to yellow.
7. Both phases remain red before the cycle repeats.

## Repository Structure

```text
arduino-four-way-traffic-light/
├── src/
│   └── main.cpp
├── diagram.json
├── platformio.ini
├── wokwi.toml
├── .gitignore
└── README.md
```

## How to Run

### Wokwi

1. Open the project files in Visual Studio Code.
2. Install the PlatformIO IDE and Wokwi Simulator extensions.
3. Build the project using PlatformIO.
4. Start the Wokwi simulation.
5. Observe the two traffic phases changing according to the configured timing.

### PlatformIO

Run the following command from the project directory:

```bash
pio run
```

## Learning Outcomes

Through this project, I developed practical skills in Arduino programming, GPIO control, circuit simulation, timing logic and embedded-system design. I also learned how all-red transition intervals and coordinated signal phases can improve the safety of a traffic-light control sequence.

## Limitations and Future Improvements

The current prototype uses a fixed-time control strategy and does not collect real-time traffic data. Future development could integrate vehicle sensors, pedestrian buttons and adaptive timing algorithms to adjust signal durations according to traffic demand.
