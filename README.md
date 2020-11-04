<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->

[![Domino][dominoes-shield]][dominoes-url]
[![made-with-C](https://img.shields.io/badge/Made%20with-C-lightgrey)](https://www.programiz.com/c-programming)
[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]

<!-- PROJECT LOGO -->
<br />
<p align="center">
<a  href="https://github.com/Shunya-sama/Dominoes">
<img  src="https://i.ibb.co/yN2n338/Png-Item-135278.png"  alt="Logo"  width="200"  height="200">
</a>

<h3 align="center">Dominoes</h3>

<p align="center">

This is a dominoes single-player played in the command line interface. It is possible to play with up to three bots and you can even let four bots play to visualize the functionalities of the game.

<br />

<a  href="https://github.com/Shunya-sama/Dominoes"><strong>Explore the docs »</strong></a>

<br />

<br />

<a  href="https://github.com/Shunya-sama/Dominoes">View Demo</a>

·

<a  href="https://github.com/Shunya-sama/Dominoes/issues">Report Bug</a>

·

<a  href="https://github.com/Shunya-sama/Dominoes/issues">Request Feature</a>

</p>

</p>

<!-- TABLE OF CONTENTS -->

## Table of Contents

- [About the Project](#about-the-project)

- [Built With](#built-with)

- [Getting Started](#getting-started)

- [Prerequisites](#prerequisites)

- [Installation](#installation)

- [Usage](#usage)

- [Roadmap](#roadmap)

- [Contributing](#contributing)

- [License](#license)

- [Contact](#contact)

- [Acknowledgements](#acknowledgements)

<!-- ABOUT THE PROJECT -->

## About The Project

This was a project I developed during my first year of unniversity when I was learning C programming, so it includes quite some beginning errors. When you are starting programming in most of the languages, some of the easiest programs to make are just simple games, so in this case I chose dominoes. As a beginner developer, I did not include any kind of GUI, so it only runs in the command line. It is a simple dominoes game for a single player to play against bots.

### Built With

- [C](https://www.programiz.com/c-programming)

<!-- GETTING STARTED -->

## Getting Started

I'm pretty sure there are way better dominoes games out there, but if in any case you need to code a dominoes game in C or want to practice your programming skills, feel free to use this one.

### Prerequisites

1. You will need a C compiler to compile this project, you can get **[GCC](https://gcc.gnu.org/).**

### Installation

1. Clone the repo

```sh

git clone https://github.com/Shunya-sama/Dominoes.git

```

2. Compile the files (make sure you are in the right directory)

```sh

gcc -c main.c game.c move.c player.c questions.c random.c sleep.c stack.c table.c tile.c

```

3. Create the executable file

```sh

gcc -g -o Dominoes main.o game.o move.o player.o questions.o random.o sleep.o stack.o table.o tile.o

```

<!-- USAGE EXAMPLES -->

## Usage

After following the installation procedures you will obtain an executable file. To run it you only need to execute it.

### Settings

You will be asked for the number of players you want to have (from one to four), simply type the number and press enter. You will also have to choose if there will be a human player, in this case you will have to answer _yes_ if you want to play against the bots, or answer _no_ to let the bots play by themselves and analyze the functionalities of the game. You can also activate omniscience to see at all times the tiles owned by every single player.

<!-- ROADMAP -->

## Roadmap

See the [open issues](https://github.com/Shunya-sama/Dominoes/issues) for a list of proposed features (and known issues).

<!-- CONTRIBUTING -->

## Contributing

Contributions are what make the open source community such an amazing place to be learn, inspire, and create. Any contributions you make are **greatly appreciated**.

1. Fork the Project

2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)

3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)

4. Push to the Branch (`git push origin feature/AmazingFeature`)

5. Open a Pull Request

<!-- LICENSE -->

## License

Distributed under the GNU General Public License. See `LICENSE` for more information.

<!-- CONTACT -->

## Contact

Victor Luque - [@ItsShunya](https://twitter.com/ItsShunya) - Shunya#1624 - luque.viictor@gmail.com

Project Link: [https://github.com/Shunya-sama/Dominoes](https://github.com/Shunya-sama/Dominoes)

<!-- ACKNOWLEDGEMENTS -->

## Acknowledgements

- [ETSETB - UPC](https://telecos.upc.edu/es) for their C programming course.

<!-- MARKDOWN LINKS & IMAGES -->

<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->

[dominoes-shield]: https://img.shields.io/badge/dominoes-v0.1.0-blue
[dominoes-url]: https://github.com/Shunya-sama/Dominoes
[contributors-shield]: https://img.shields.io/github/contributors/Shunya-sama/Shuwy.svg
[contributors-url]: https://github.com/Shunya-sama/Shuwy/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/Shunya-sama/Shuwy.svg
[forks-url]: https://github.com/Shunya-sama/Shuwy/network/members
[stars-shield]: https://img.shields.io/github/stars/Shunya-sama/Shuwy.svg
[stars-url]: https://github.com/Shunya-sama/Shuwy/stargazers
[issues-shield]: https://img.shields.io/github/issues/Shunya-sama/Shuwy.svg
[issues-url]: https://github.com/Shunya-sama/Shuwy/issues
[license-shield]: https://img.shields.io/badge/License-GPLv3-blue.svg
[license-url]: https://github.com/Shunya-sama/Shuwy/blob/dev/COPYING
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?logo=linkedin&colorB=555
[linkedin-url]: https://www.linkedin.com/in/victor-luque-martínez-51277b193
[product-screenshot]: images/screenshot.png
