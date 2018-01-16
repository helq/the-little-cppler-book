To get a pdf version from this file run:

~~~bash
$ pandoc --standalone --pdf-engine xelatex -H 00-header.tex -f markdown --filter pandoc-filters/tlcppler.sh --filter pandoc-filters/runcppcode.sh --filter pandoc-filters/loadcodeinoutput.sh 00-metadata.yaml ??-*.md -t latex -o test.pdf
~~~
