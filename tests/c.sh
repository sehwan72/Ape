#!/bin/bash

if [ -f ../bin/tests/all ]
then
    valgrind -v --leak-check=full ../bin/tests/all
fi
