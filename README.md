To get a pdf version from this repository you need:

- [Stack](https://www.haskellstack.org)
- XeLaTeX (comes with your usual LaTeX installation)

With everything in place:

~~~bash
$ stack setup
$ stack build
$ stack exec -- build-pdf-exe --verbose
~~~
