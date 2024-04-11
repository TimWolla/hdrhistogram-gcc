#!/bin/bash

pushd HdrHistogram_c/

env CFLAGS="-O2 -ggdb" cmake .
make
sudo make install

popd

gcc -shared -g -O0 lib.c -lhdr_histogram_static -lm -o lib.so

gcc app.c -o app
