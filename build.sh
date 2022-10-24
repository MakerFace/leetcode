#/usr/bin/bash

MONTH=$(env LANG=en_US.UTF-8 date +%b)
TODAY=$(env LANG=en_US.UTF-8 date +%m.%d)
FOLDER="src/$MONTH/$TODAY"

bash -c "cmake -B build -GNinja -DBUILD_DES_SRC=$FOLDER"
bash -c 'cmake --build build'