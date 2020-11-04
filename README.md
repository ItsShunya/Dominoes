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
    <a  href="https://github.com/Shunya-sama/Shuwy"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a  href="https://github.com/Shunya-sama/Shuwy">View Demo</a>
        ·
    <a  href="https://github.com/Shunya-sama/Shuwy/issues">Report Bug</a>
        ·
    <a  href="https://github.com/Shunya-sama/Shuwy/issues">Request Feature</a>
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

[![Product Name Screen Shot][product-screenshot]](https://example.com)

Trying to choose a suitable bot for some general project discords was always a tiresome activity, seeing bots with too many useless features, or more likely focused in really concise targets. Shuwy is a bot which provides some general **moderation** features, together with **automation** capabilities such as setting a role for new members or welcoming them. It also features a powerful graphical **music** player to allow the users have a full experience bot.

### Built With

- [Python 3.7](https://www.python.org/)

- [discord.py](https://github.com/Rapptz/discord.py)

- [Lavalink](https://github.com/Frederikam/Lavalink)

- [Wavelink](https://github.com/PythonistaGuild/Wavelink)

- [aiosqlite](https://github.com/omnilib/aiosqlite)

<!-- GETTING STARTED -->

## Getting Started

I developed Shuwy for my personal use, but in case you want to set up your own local copy of Shuwy, follow these simple steps.

### Prerequisites

1. Make sure you have Python 3.7 installed, otherwise get it **[here](https://www.python.org/downloads/).**

2. Download a **[Database Browser for SQLite](https://sqlitebrowser.org/dl/)**, you will need it to maintain your databases.

3. Generate your Discord Bot Token

4. Set up a Lavalink server

### Installation

1. Clone the repo

```sh

git clone https://github.com/Shunya-sama/Shuwy.git

```

2. Set up a virtual environment

```sh

python3.7 -m venv ShuwyPythonenv

```

3. Install dependencies

```sh

pip install -U -r requirements.txt

```

### Configuration

1. Add your Discord Bot Token to `\config\.env.example` file

```sh

DISCORD_TOKEN=YOUR TOKEN HERE

```

2. Rename `\config\.env.example` to `\config\.env`

3. Open `\config\lavalink.bat` and correct the path to `Lavalink.jar`

```sh

java -jar "PATH-TO-YOUR-Lavalink.jar"

```

5. Open `\config\run.bat` and correct the following paths.

```sh

"PATH-TO-YOUR-BOT\ShuwyPythonenv\Scripts\python.exe"  "PATH-TO-YOUR-BOT\Shuwy.py" %*

```

<!-- USAGE EXAMPLES -->

## Usage

The tools that I supply together with Shuwy are made of my own accord to ease the workflow. The functionalities of the bot are pretty standard and everyone is welcome to add or suggest more of them.

### Launch

To start the bot, simply navigate to the \config folder and launch the executable run.bat. This is a _BATCH_ file that I developed to make it easier to start the bot and monitor its activity, the syntax of this _BATCH_ file makes it restricted uniquely to _Windows 10_, if you are using some other _OS_, just run the `Shuwy.py` file or use this command line:

```sh

"PATH-TO-YOUR-BOT\ShuwyPythonenv\Scripts\python.exe"  "PATH-TO-YOUR-BOT\Shuwy.py" %*

```

### Functionalities

_For more examples, please refer to the [Documentation](https://example.com)_

<!-- ROADMAP -->

## Roadmap

See the [open issues](https://github.com/Shunya-sama/Shuwy/issues) for a list of proposed features (and known issues).

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

Distributed under the GNU General Public License. See `COPYING` for more information.

<!-- CONTACT -->

## Contact

Victor Luque - [@ItsShunya](https://twitter.com/ItsShunya) - Shunya#1624 - luque.viictor@gmail.com

Project Link: [https://github.com/Shunya-sama/Shuwy](https://github.com/Shunya-sama/Shuwy)

<!-- ACKNOWLEDGEMENTS -->

## Acknowledgements

- [Rapptz](https://github.com/Rapptz) for developing discord.py

- [Pythonista Guild](https://github.com/PythonistaGuild) for their work with Wavelink

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
