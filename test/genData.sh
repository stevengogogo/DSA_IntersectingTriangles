#!/bin/bash

echo "generate data"

# Path Length Number_files 
/home/ubuntu/.local/bin/julia test/dataGen.jl test/dataGen 4000 1

echo "Complete"