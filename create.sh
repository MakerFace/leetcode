#!/usr/bin/env bash
MONTH=$(date +%b)
TODAY=$(date +%m.%d)
FILE=$1

FOLDER="src/$MONTH/$TODAY"

if [ ! -n "$FILE" ];
then
    echo "Usage: bash create.sh FILE"
    exit 1
else
    echo "create and open $FOLDER/$FILE{.cpp,.txt}"
fi

FILE=$FOLDER/$FILE

if [ ! -e $FOLDER ];
then
    echo "create folder $FOLDER"
    mkdir -p $FOLDER
fi

if [ ! -e $FILE ];
then
    echo "touch files"
    touch "$FILE.cpp"
    touch "$FILE.txt"
fi

code $FILE.cpp $FILE.txt