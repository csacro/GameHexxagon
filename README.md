# GameHexxagon
Implementation of a Client with GUI for the Game Hexxagon

## Installation
### Dependencies
* Network
  * nlohmann-json
  ```bash
  sudo apt-get install nlohmann-json-dev
  sudo ldconfig
  ```
  * lib-WebSocket
  ```bash
  git clone https://github.com/warmcat/libwebsockets.git
  cd libwebsockets
  mkdir build && cd build
  cmake ..
  make
  sudo make install
  sudo ld config
  ```
  * SopraNetwork
  ```bash
  git clone https://github.com/SoPra-Team-10/Network.git
  cd Network
  mkdir build && cd build
  cmake ..
  make
  sudo make install
  sudo ld config
  ```
* Graphics
  * SFML
  ```bash
  sudo apt-get install libsfml-dev
  ```
  * SFMLComponents
  ```bash
  git clone https://github.com/csacro/SFMLComponents.git
  cd SFMLComponents
  mkdir build && cd build
  cmake ..
  make
  sudo make install
  sudo ld config
  ```

### GameHexxagon
```bash
git clone https://github.com/csacro/GameHexxagon.git
cd GameHexxagon
mkdir build && cd build
cmake ..
make
```
## Usage
### Game
run X server on port 0
```bash
cd src
./GameHexxagon_src
```
(runnable on Windows with WSL and Xming)  
### Tests
```bash
cd test
./GameHexxagon_test
```
