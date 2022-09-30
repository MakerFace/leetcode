#!/usr/bin/env bash
cd ..
tar --exclude src --exclude build --exclude-vcs --exclude-vcs-ignores -zcvf leetcode.tar.gz leetcode
