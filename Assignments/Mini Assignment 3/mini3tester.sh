#!/bin/bash

# These should generate errors
./triangles -1
./triangles 0

# These should be valid
./triangles 1
./triangles 3
./triangles 10

# This one should prompt the user for a value, enter a wrong value
./triangles

# This should prompt the user for a value, enter a good value
./triangles

