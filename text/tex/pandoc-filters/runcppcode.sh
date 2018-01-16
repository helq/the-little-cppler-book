#!/usr/bin/env bash

cd pandoc-filters
stack exec -- runcppcode-exe $@
#stack exec -- runhaskell app/runcppcode.hs $@
