#/usr/bin/bash

bash -c "cmake -B build -GNinja"
bash -c 'cmake --build ./build'