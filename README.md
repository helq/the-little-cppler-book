# [**Link to the book** (pdf)](the_little_cppler.pdf) #

A book on how to learn to code in C++. I've been using this book in an introductory class
on programming at the "Universidad Nacional de Colombia". The course webpage including
some suggested additional material can be found at: <https://helq.github.io/teaching/coding-2018-I/>

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
$ git config --local core.hooksPath "git-hooks"
$ stack build hobbes
$ stack exec -- ./buildNWatch.sh
~~~
