# chess_console

This is a simple chess game, written in C++, that runs in the console.

For more information, please read the [article](https://www.codeproject.com/Articles/1214018/Chess-console-game-in-Cplusplus).

## Building Guide

You may want to clone this repo.

* Linux / macOS
```
$ cd chess_console/source
$ mkdir build
$ cd build
$ cmake ..
$ make
$ ./chess
```

* Windows
  * ensure you have _Visual Studio_ installed on your system
  * open `chess_console/source/Chess_console.sln`
  * you may hit `ctrl+shift+b` or click the _build_ button from the menu bar to compile the solution
  * press the `F5` key to run the game

## Changelog

* May, 2018 - original version
* June, 2024 - fixes for issues [2](https://github.com/jeromevonk/chess_console/issues/2) and [4](https://github.com/jeromevonk/chess_console/issues/4), created unit tests and general improvements
