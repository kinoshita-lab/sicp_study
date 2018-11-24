#!/usr/bin/env sh
./loader.scm
ruby out2cpp compiled.out
mv ./*.cpp ./*.h ./mceval/

