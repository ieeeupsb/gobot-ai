# Architecture

We currently have 3 main folders:

- ai
- board
- engine

`ai` for handling the AI Algorithms that will play the game. `board` contains the in-memory representation of the board. `engine` contains the game logic.

We have a [justfile](../justfile) in the repo. A _justfile_ is just a more modern version of Makefile. You are not forced to use it, but if you want to, check [their installation page](https://just.systems/man/en/packages.html).
