#/usr/bin/bash

MONTH=$(date +%b)
TODAY=$(date +%m.%d)
FOLDER="src/$MONTH/$TODAY"

bash -c "cmake -B build -GNinja -DBUILD_DES_SRC=$FOLDER"
bash -c 'cmake --build build'