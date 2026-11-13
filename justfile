_default:
    @just -l

[group: 'dev']
compile:
    @g++ main.cpp -o main.out -O2 -std=c++20 -Wall -Wextra

[group: 'dev']
clean:
    @echo "Removing compilation files..."
    @rm -rf *.out
