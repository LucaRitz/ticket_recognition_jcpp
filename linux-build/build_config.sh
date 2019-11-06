#!/bin/bash
cd /usr/local/bin
rm -r build/*
cp install.sh build/install.sh
cd build
./install.sh