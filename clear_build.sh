#!/bin/bash

# Navigate to the project root directory
cd "$(dirname "$0")"

# Remove all files in src/build
rm -rf src/build/*

echo "All files in src/build have been deleted."