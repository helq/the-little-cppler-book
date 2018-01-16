#!/usr/bin/env bash

cd pandoc-filters
stack exec -- tlcppler-exe $@
#stack exec -- runhaskell app/thelittlecppler.hs $@
