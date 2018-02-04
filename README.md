To get a pdf version from this repository you need:

- [Stack](https://www.haskellstack.org)
- XeLaTeX (comes with your usual LaTeX installation)

With everything in place:

~~~bash
$ stack setup
$ stack build
$ stack exec -- pandoc --standalone --pdf-engine xelatex -H 00-header.tex -f markdown --filter tlcppler.sh --filter runcppcode.sh --filter loadcodeinoutput.sh 00-metadata.yaml ??-*.md -t latex -o test.pdf
~~~
