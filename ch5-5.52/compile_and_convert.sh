#!/usr/bin/env sh
./loader.scm
ruby out2cpp compiled.out
cp ./*.cpp ./*.h ./mceval/

