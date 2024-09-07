#!/bin/bash

EXECUTABLE="./src/build/main"  
OUTFILE="./src/build/main-output"

$EXECUTABLE | tee $OUTFILE

if [ $? -eq 0 ]; then
    echo "Saída salva em $OUTFILE"
else
    echo "Erro ao executar $EXECUTABLE"
fi
