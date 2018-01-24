#!/usr/bin/env bash

curdir="$PWD"
direxec="$(dirname "$(readlink -f "${BASH_SOURCE[0]}")")"
cd "$direxec"
stack exec -- loadcodeinoutput-exe "$curdir" $@
#stack exec -- runhaskell app/loadcodeinoutput.hs "$curdir" $@
