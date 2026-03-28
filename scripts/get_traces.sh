#!/bin/bash

case $# in
    1)
        TRACES_DIR=$1
        ;;
    *)
        echo "Incorrect number of arguments ($#)"
        exit 1
        ;;
esac

# curl something something
