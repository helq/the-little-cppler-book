#!/usr/bin/env bash

direxec="$(dirname "$(readlink -f "${BASH_SOURCE[0]}")")"
dirsource="maker-src/pandoc-filters"
cd "$direxec"
stack exec -- tlcppler-exe $@
#stack exec -- runhaskell "$dirsource"/tlcppler.hs $@
