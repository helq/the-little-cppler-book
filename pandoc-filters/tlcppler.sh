#!/usr/bin/env bash

direxec="$(dirname "$(readlink -f "${BASH_SOURCE[0]}")")"
cd "$direxec"
stack exec -- tlcppler-exe $@
#stack exec -- runhaskell app/tlcppler.hs $@
