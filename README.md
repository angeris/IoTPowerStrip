# Stanford IoT Power Strip

## Overview

This is a Smart Power Strip project for the Stanford IoT group, which aims to create a simple, relatively cheap interface for a power strip that can be home-built and is open source.

This repository provides a sample server in Python, an API, and the Arduino
code for the project.

For more information about the Stanford IoT group, please visit the IoT website.

## Arduino

This folder provides all of the Arduino code for the project. In general, this code should not be modified unless its being tailored to specific applications, or unless a patch is being submitted. This project needs to be compiled with the [PlatformIO](http://platformio.org/) platform.

To do so, go to the PowerStripArduino directory and type

    platformio run -t upload

in order to compile and run the code. Note also that this code will only work with the Arduino Micro as it requires a second, dedicated serial RX/TX, which are found on pins 0 and 1 of the Micro.

## API

Note that the API is currently not being hosted on this repository as there are issues with subprojects. This should be fixed soon, but in the meantime the Python sample server, client, and API are found in [Dan's Repository](https://github.com/danXyu/powerstrip_arduino_api).

## Contributors
This project is currently being developed by Guillermo Andres Angeris, Dan Yu, and Christopher Mehdi Elamri.
