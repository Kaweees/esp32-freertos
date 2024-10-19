<!--
*** This readme was adapted from Best-README-Template.
  https://github.com/othneildrew/Best-README-Template
-->

<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->
<div align="left">

[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]

</div>

<a href="https://github.com/Kaweees/espressif">
  <img alt="C++ Logo" src="assets/img/espressif.svg" align="right" width="150">
</a>

<div align="left">
  <h1><em><a href="https://github.com/Kaweees/espressif">~espressif</a></em></h1>
</div>

<!-- ABOUT THE PROJECT -->

Template for developing Espressif FreeRTOS-based applications on the Espressif IDF (Espressif IoT Development Framework)  in C/C++

> [!NOTE]  
> This project is specifically tailored for ESP32-S3 microcontrollers, some commands might need to be adjusted to work with other ESP32 microcontrollers.

### Built With

[![Neovim][C++-shield]][C++-url]
[![Espressif][Espressif-shield]][Espressif-url]
[![GitHub Actions][github-actions-shield]][github-actions-url]


<!-- PROJECT PREVIEW -->
## Preview

<p align="center">
  <img src="assets/img/preview.png" alt="Project Preview" width="80%">
</p>

<!-- GETTING STARTED -->
## Getting Started

### Prerequisites

Before attempting to build this project, make sure you have [GNU Make](https://www.gnu.org/software/make/), [CMake](https://cmake.org), [ESP-IDF](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/get-started/index.html), and [Esptool.py](https://docs.espressif.com/projects/esptool/en/latest/esp32/installation.html#installation/),  installed on your machine.


### Installation

To get a local copy of the project up and running on your machine, follow these simple steps:

1. Clone the project repository

   ```sh
   git clone https://github.com/Kaweees/espressif.git
   cd espressif
   ```

2. Set up or refresh the esp-idf environment your current terminal session

   ```sh
   alias get_idf="source $HOME/esp/esp-idf/export.sh"
   get_idf
   ```

3. Find the serial port of your ESP32-S3 microcontroller

   ```sh
   ls /dev/cu.* # List all serial ports
   ```

4. Build and flash the project to your ESP32-S3 microcontroller

   ```sh
   clear && idf.py -p /dev/cu.usbmodem1101 -b 115200 flash monitor
   ```

## Usage

<!-- PROJECT FILE STRUCTURE -->
## Project Structure

```sh
espressif/
├── .github/                       - GitHub Actions CI/CD workflows
├── include/                       - project header files
├── src/                           - project source files
│   └── main.c                     - Entry point, main function
├── CMakeLists.txt                 - CMake build script
├── LICENSE                        - project license
└── README.md                      - you are here
```

## License

The source code for [Kaweees/espressif](https://github.com/Kaweees/espressif) is distributed under the terms of the GNU General Public License v3.0, as I firmly believe that collaborating on free and open-source software fosters innovations that mutually and equitably beneficial to both collaborators and users alike. See [`LICENSE`](./LICENSE) for details and more information.

<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->

[contributors-shield]: https://img.shields.io/github/contributors/Kaweees/espressif.svg?style=for-the-badge
[contributors-url]: https://github.com/Kaweees/espressif/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/Kaweees/espressif.svg?style=for-the-badge
[forks-url]: https://github.com/Kaweees/espressif/network/members
[stars-shield]: https://img.shields.io/github/stars/Kaweees/espressif.svg?style=for-the-badge
[stars-url]: https://github.com/Kaweees/espressif/stargazers

<!-- MARKDOWN SHIELD BAGDES & LINKS -->
<!-- https://github.com/Ileriayo/markdown-badges -->
[C++-shield]: https://img.shields.io/badge/C++-%23008080.svg?style=for-the-badge&logo=c%2B%2B&logoColor=004482&labelColor=222222&color=004482
[C++-url]: https://isocpp.org/
[Espressif-shield]: https://img.shields.io/badge/espressif-%23008080.svg?style=for-the-badge&logo=espressif&logoColor=E7352C&labelColor=222222&color=E7352C
[Espressif-url]: https://docs.espressif.com/projects/esp-idf/en/stable/esp32/index.html
[github-actions-shield]: https://img.shields.io/badge/github%20actions-%232671E5.svg?style=for-the-badge&logo=githubactions&logoColor=2671E5&labelColor=222222&color=2671E5
[github-actions-url]: https://github.com/features/actions
