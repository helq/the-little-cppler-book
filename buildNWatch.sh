#!/usr/bin/env bash

# TODO: Replace this file with custom made code, a more flexible approach

touch devel
git config core.hooksPath git-hooks

build-pdf-exe --verbose --live

filestowatch="($(grep -v _build/ live.txt | grep -v code/ | tr '\n' '|' ))"
# doesn't work :(, the glob pattern that hobbes uses is just too simple
#filestowatch="(*-*.md|00-header.tex)"

hobbes "$filestowatch" | xargs -n1 sh -c 'sleep 1 && build-pdf-exe --verbose'
