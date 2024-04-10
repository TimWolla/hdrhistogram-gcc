#!/bin/bash

pushd HdrHistogram_c/

env CFLAGS="-O2 -ggdb" cmake .
make
make install

popd

gcc -shared -g -O0 -fPIC -DPIC -shared -export-dynamic lib.c -lhdr_histogram_static -lm -o lib.so

gcc app.c -o app
