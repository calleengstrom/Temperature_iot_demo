# ESP32 DHT Sensor + Java Spring Backend

Short description
-----------------
This repository contains two coordinated projects: an ESP-IDF firmware for an ESP32 that reads a DHT temperature/humidity sensor and sends data over HTTP, and a Java Spring (Gradle) backend application (TempHibernate) that can receive, process, and persist the sensor data.

Repository layout
-----------------
- `Esp/` — ESP-IDF firmware (CMake-based) for the ESP32 device.
- `TempHibernate/` — Java Spring (Gradle) backend application.

Key features
------------
- Read temperature and humidity from a DHT sensor on an ESP32.
- Wi‑Fi management and HTTP client on the ESP device to POST sensor readings.
- Java Spring backend prepared for persistence with Hibernate (Gradle wrapper included), configured to persist sensor readings into a MySQL database.
- Persist sensor readings to a MySQL database via the backend.

Prerequisites
-------------
- ESP firmware: ESP-IDF toolchain and environment matching the project (CMake, ninja, `idf.py`).
- Java backend: JDK 11+ (or the version in project settings), Gradle wrapper (`gradlew`), optional SQL database (Postgres/MySQL).
- Hardware: ESP32 development board and a DHT sensor (DHT11/DHT22) wired correctly.

Quick start — ESP firmware
-------------------------
1. Install and configure ESP-IDF per the official docs and open a terminal with the ESP-IDF environment.
2. From the `Esp/` folder, build and flash the firmware:

```bash
cd Esp
idf.py set-target esp32
idf.py build
idf.py -p <PORT> flash monitor
```

3. Configure Wi‑Fi credentials and backend endpoint either via project menuconfig or in the firmware config/source before building.

Quick start — Java backend
-------------------------
From the Java project root (the included Gradle wrapper ensures reproducible builds):

```bash
cd TempHibernate
./gradlew build
./gradlew bootRun
```

Or run the built jar from `build/libs` if the project produces an executable jar.

Configuration
-------------
- Firmware: set SSID, password and backend URL in the firmware configuration or as build-time overrides.
- Backend: set the MySQL connection (JDBC URL, username, password) and other properties in `application.properties` / `application.yml` before enabling persistence. Ensure a MySQL instance is running and reachable by the application.

Development notes
-----------------
- Use `idf.py` for ESP tasks (build, flash, monitor).
- Use the provided `gradlew` wrapper to build and run the Java app.
- Keep device credentials out of source control; use environment variables or secure build-time configuration where possible.

Security & deployment
---------------------
- When deploying the backend, secure endpoints (HTTPS, authentication) and protect DB credentials.
- Consider adding input validation on the backend to prevent malformed sensor data from creating errors.

Contributing
------------
Submit issues or pull requests. If you contribute firmware or backend changes, include clear build instructions and any hardware wiring notes.

License
-------
Check the repository root for a license file. If none exists, add a license to clarify reuse terms.

If you want, I can adjust this README with more specific build settings, sample payloads/endpoints, or add step-by-step wiring diagrams.
