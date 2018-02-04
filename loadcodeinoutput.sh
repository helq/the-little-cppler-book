#!/usr/bin/env bash

curdir="$PWD"
direxec="$(dirname "$(readlink -f "${BASH_SOURCE[0]}")")"
dirsource="maker-src/pandoc-filters"
cd "$direxec"
stack exec -- loadcodeinoutput-exe "$curdir" $@
#stack exec -- runhaskell "$dirsource"/loadcodeinoutput.hs "$curdir" $@
