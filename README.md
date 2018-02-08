# [**Link to the book**](cpp_book.pdf)

A book on how to learn to code in C++.

## "Compiling" Book ##

If you don't want to modify the book, and want to know the end result, keep reading.

Tools you need:

- [Stack](https://www.haskellstack.org)
- XeLaTeX (comes with your usual LaTeX installation)
- Clang compiler (if you want to use GCC, change `clang++` for `g++` in the file `maker-src/build-pdf.hs`)

With everything in place, open the command line, and execute:

~~~bash
$ stack setup
$ stack build
$ stack exec -- build-pdf-exe --verbose
~~~

That's all, happy fiddling :)

If you want to build continuously, i.e., without calling stack everytime you want to see
the results but automatically, run `buildNWatch.sh`:

~~~bash
$ stack build hobbes
$ stack exec -- ./buildNWatch.sh
~~~
