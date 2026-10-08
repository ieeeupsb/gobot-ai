_default:
    @just -l

[group: 'dev']
compile:
    @g++ main.cpp -o main.out -Wall

[group: 'dev']
clean:
    @echo "Removing compilation files..."
    @rm -rf *.out
