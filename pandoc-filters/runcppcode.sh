#!/usr/bin/env bash

curdir="$PWD"
direxec="$(dirname "$(readlink -f "${BASH_SOURCE[0]}")")"
cd "$direxec"
stack exec -- runcppcode-exe "$curdir" $@
#stack exec -- runhaskell app/runcppcode.hs "$curdir" $@
