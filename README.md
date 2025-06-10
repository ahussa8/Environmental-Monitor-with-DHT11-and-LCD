# ME 331 Project 3 – Environmental Monitor with DHT11 and LCD

This project reads data from a DHT11 temperature and humidity sensor and displays the results—including temperature in Fahrenheit, relative humidity, and the calculated heat index—on a 16x2 LCD screen. The project is implemented using Arduino and demonstrates sensor integration and real-time data visualization.

## 🔧 Components Used

- Arduino Uno
- DHT11 Sensor (Elegoo Kit version, 3-pin)
- 16x2 LCD Display (with potentiometer for contrast)
- 10kΩ Potentiometer (for LCD contrast control)
- Breadboard and jumper wires

## 📌 Features

- 🌡️ Reads temperature (°F)
- 💧 Displays relative humidity (%)
- 🔥 Calculates and shows heat index (°F)
- 🔁 Continuously updates every few seconds on the LCD
- 🖥️ Uses `DHT` and `LiquidCrystal` libraries

## 🧪 Functionality

- The DHT11 sensor captures ambient temperature and humidity.
- These values are processed by the Arduino.
- The LCD displays:
  - Temperature in °F
  - Humidity in %
  - Heat Index (perceived temperature) in °F
- The sensor reading is updated periodically (e.g., every 2 seconds).

## 💡 Example LCD Output

Temp: 73.4 F
Humidity: 48.0%
HeatIdx: 75.1 F


## 🔄 Arduino Setup

| Pin        | Connection           |
|------------|----------------------|
| DHT11 Data | D4 (or any digital)  |
| LCD RS     | D7                   |
| LCD EN     | D8                   |
| LCD D4     | D9                   |
| LCD D5     | D10                  |
| LCD D6     | D11                  |
| LCD D7     | D12                  |
| Potentiometer | LCD VO (contrast) |

> *Note: DATA pin for DHT11 must avoid conflict with LCD pins.*

## 🛠️ Libraries Required

- **Adafruit DHT Sensor Library**  
  [Install via Arduino Library Manager → “DHT sensor library by Adafruit”]
- **LiquidCrystal Library** (built-in)

## 💬 Code Behavior

- Uses `DHT.readTemperature()` and `DHT.readHumidity()` to gather data.
- Converts Celsius to Fahrenheit using `DHT.convertCtoF()`.
- Calculates the heat index using `DHT.computeHeatIndex()`.
- Displays values on LCD using `lcd.print()` with formatted strings.

## 🎥 Deliverables

- `Project3_AbbasHussain.ino`: Main Arduino sketch
- `Project3_demo_video.mp4`: Video showing the LCD responding to heat/cold

## 📋 Notes

- Sensor is slow to respond—allow a few seconds between changes.
- Make sure to wire the DHT11 correctly (VCC, DATA, GND).
- LCD contrast may need adjustment using the potentiometer.

---

🧪 **Experiment by holding a warm object (e.g., hand or cup) near the sensor to observe live data changes.**
