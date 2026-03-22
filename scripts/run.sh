#!/bin/bash

case $# in
    1)
        TRACE_PATH=$1
        ;;
    *)
        echo "Incorrect number of arguments ($#)"
        exit 1
        ;;
esac

bin/champsim \
    --warmup_instructions 2000000 \
    --simulation_instructions 5000000 \
    ${TRACE_PATH}
