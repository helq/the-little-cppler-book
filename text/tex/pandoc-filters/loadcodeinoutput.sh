#!/usr/bin/env bash

cd pandoc-filters
stack exec -- loadcodeinoutput-exe $@
#stack exec -- runhaskell app/loadcodeinoutput.hs $@
