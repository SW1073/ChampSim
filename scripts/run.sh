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

WARM_INSTR=200000
SIM_INSTR=500000

bin/champsim \
    --warmup_instructions ${WARM_INSTR} \
    --simulation_instructions ${SIM_INSTR} \
    ${TRACE_PATH}
