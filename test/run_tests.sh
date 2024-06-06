#!/bin/bash

# Compile the code and tests
g++ -I ../source/ -o tst_checkmates checkmates.cpp ../source/chess.cpp

# Check if compilation was successful
if [ $? -eq 0 ]; then
    # Run the tests
    ./tst_checkmates
    
    # Check if tests ran successfully
    if [ $? -eq 0 ]; then
        echo "All tests passed!"
    else
        echo "Some tests failed."
    fi
else
    echo "Compilation failed."
fi
