#!/usr/bin/env bash
cd ..
tar --exclude bin --exclude src --exclude build --exclude-vcs --exclude-vcs-ignores -zcvf leetcode.tar.gz leetcode
