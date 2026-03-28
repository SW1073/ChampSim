#!/bin/bash

git submodule update --init
vcpkg/bootstrap-vcpkg.sh -diableMetrics
vcpkg/vcpkg install
