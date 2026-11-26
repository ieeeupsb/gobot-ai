_default:
    @just -l

[group: 'dev']
_config mode='Release':
    @cmake -B build -DCMAKE_BUILD_TYPE={{mode}}

# Compile the project. Release mode or Debug mode
[group: 'dev']
compile mode='Release': (_config mode)
    @echo "Compiling the project..."
    @cmake --build build --parallel

# Exec the project
[group: 'dev']
exec:
    @./build/gobot

# Compile and Exec the project
[group: 'dev']
run: compile exec

[group: 'dev']
clean:
    @echo "Removing compilation files..."
    @rm -rf build/

[group: 'dev']
test:
    @echo "TODO"
