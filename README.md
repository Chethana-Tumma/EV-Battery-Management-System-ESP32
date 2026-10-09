# EV-Battery-Management-System-ESP32

# 🔋 EV Battery Management System using ESP32

## 📌 Project Overview

This project is an **EV Battery Management System (BMS) using ESP32** developed to monitor multiple battery cell voltages and provide visual and audible indications for different battery conditions.

The system uses an **ESP32 microcontroller** to monitor three cell-voltage inputs. The measured values are displayed on an **I2C LCD**, while LEDs, a relay, and a buzzer provide status and warning indications.

The project is developed and tested using the **Wokwi simulator** and can be extended for real-world EV battery monitoring applications.

## 🎯 Objectives

- Monitor three battery cell voltages.
- Display cell-voltage values on an I2C LCD.
- Detect low-voltage cell conditions.
- Provide visual indication using LEDs.
- Activate a buzzer in battery high and low conditions.
- Control a relay according to the battery condition.
- Send battery-related data to the Blynk IoT platform.
- Understand the basic operation of an EV Battery Management System.

## 🛠️ Components Used

- ESP32 Development Board
- 3 × Potentiometers – used to simulate cell voltages
- I2C LCD Display (16×2)
- Red LED
- Green LED
- Yellow LED
- Buzzer
- Relay Module
- Jumper Wires
- Breadboard
- Power Supply

## 💻 Software Used

- Arduino IDE
- Wokwi Simulator
- Blynk IoT Platform

## ⚙️ Working Principle

The **ESP32** acts as the main controller of the EV Battery Management System.

Three potentiometers are used in the Wokwi simulation to represent the voltage levels of three individual battery cells:

- **Cell 1**
- **Cell 2**
- **Cell 3**

The ESP32 continuously reads the voltage values of all three cells and compares them with the predefined voltage conditions.

Based on the combination of cell voltages, the system identifies the battery condition and provides an appropriate warning through the **LCD, LEDs, and buzzer**.

### 🔴 High-Voltage Warning

When **all three battery cells are at high voltage**, the system identifies the condition as a **HIGH VOLTAGE warning**.

In this condition:

- The LCD displays the high-voltage warning/status.
- The appropriate warning LED is activated.
- The **buzzer turns ON** to provide an audible warning.

### 🟡 Low-Voltage Warning

When **any one of the three battery cells reaches a low-voltage condition**, the system identifies the condition as a **LOW VOLTAGE warning**.

In this condition:

- The LCD displays the low-voltage warning/status.
- The appropriate warning LED is activated.
- The **buzzer turns ON** to provide an audible warning.

### 🟢 Normal Condition

When the cell voltages are within the defined normal operating range and neither the high-voltage nor low-voltage warning condition is detected, the system indicates a **NORMAL** battery condition.

In the normal condition:

- The LCD displays the normal status.
- The normal-status LED is activated.
- The warning buzzer remains OFF.

## 🔔 Buzzer Operation

The buzzer provides an audible warning under two conditions:

- **High-Voltage Warning:** The buzzer turns ON when all three battery cells reach the high-voltage condition.
- **Low-Voltage Warning:** The buzzer turns ON when any one of the three battery cells reaches the low-voltage condition.

The buzzer remains OFF when neither warning condition is detected.

## 💡 Battery Status Indication

| Battery Cell Condition | System Status | Buzzer |
|---|---|---|
| All three cells are at high voltage | HIGH VOLTAGE | ON |
| Any one cell is at low voltage | LOW VOLTAGE | ON |
| Neither warning condition is detected | NORMAL | OFF |

