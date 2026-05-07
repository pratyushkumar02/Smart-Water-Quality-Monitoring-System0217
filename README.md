# Smart-Water-Quality-Monitoring-System0217

## Project Overview

The Smart Water Quality Monitoring System is an IoT-based project developed using ESP32 and multiple water quality sensors. The main purpose of this project is to monitor water quality in real time and identify whether the water is safe or unsafe based on threshold values.

The system continuously reads data from different sensors such as turbidity, TDS, and temperature sensors. The collected data is processed by the ESP32 microcontroller and displayed on the serial monitor. The project can also upload live data to the ThingSpeak cloud dashboard for remote monitoring.

---

# Features

* Real-time water quality monitoring
* Threshold-based decision system
* Measures turbidity, TDS, and temperature
* Displays water status as CLEAN, MODERATE, or UNSAFE
* IoT dashboard using ThingSpeak
* Buzzer alert for unsafe water condition
* Low-cost and portable system

---

# Components Used

| Component                  | Quantity    |
| -------------------------- | ----------- |
| ESP32 Dev Module           | 1           |
| Turbidity Sensor           | 1           |
| TDS Sensor                 | 1           |
| DS18B20 Temperature Sensor | 1           |
| Buzzer                     | 1           |
| Jumper Wires               | Multiple    |
| Breadboard                 | 1           |
| Transparent Container      | 1           |
| Resistors                  | As required |

---

# Sensor Connections

## Turbidity Sensor

| Sensor Pin | ESP32 Pin |
| ---------- | --------- |
| VCC        | 5V        |
| GND        | GND       |
| OUT        | GPIO34    |

## TDS Sensor

| Sensor Pin | ESP32 Pin |
| ---------- | --------- |
| +          | 5V        |
| -          | GND       |
| A          | GPIO35    |

## DS18B20 Temperature Sensor

| Sensor Wire | ESP32 Pin |
| ----------- | --------- |
| Red         | 3.3V      |
| Black       | GND       |
| Yellow      | GPIO4     |

## Buzzer

| Buzzer Pin | ESP32 Pin |
| ---------- | --------- |
| Positive   | GPIO25    |
| Negative   | GND       |

---

# Working Principle

1. The sensors collect water quality data.
2. ESP32 reads the sensor values.
3. Threshold conditions are applied.
4. The system checks whether the water is safe or unsafe.
5. The data is displayed on the serial monitor.
6. Data is uploaded to ThingSpeak cloud dashboard.
7. Buzzer activates if water quality becomes unsafe.

---

# Water Quality Logic

| Condition                  | Status           |
| -------------------------- | ---------------- |
| Low Turbidity + Low TDS    | CLEAN AND SAFE   |
| Medium Turbidity           | MODERATE         |
| High Turbidity or High TDS | DIRTY AND UNSAFE |

---

# Software Used

* Arduino IDE
* ThingSpeak
* ESP32 Board Package

---

# Libraries Used

* WiFi.h
* ThingSpeak.h
* OneWire.h
* DallasTemperature.h

---

# Applications

* River water monitoring
* Drinking water analysis
* Smart city projects
* Environmental monitoring
* Industrial water monitoring

---

# Future Improvements

* Mobile app integration
* LCD display
* pH sensor integration
* AI-based prediction system
* Solar-powered operation

---

# Conclusion

This project demonstrates a simple and efficient IoT-based water quality monitoring system using ESP32. The system can monitor water quality in real time and help identify unsafe water conditions. It is a low-cost and practical solution that can be used for environmental monitoring and smart water management applications.

---

# Author

Pratyush Kumar
