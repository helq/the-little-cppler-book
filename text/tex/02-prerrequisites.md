# Prerequisites #

## Tools ##

\inlinetodo{Tools neccesary to follow the book (for everything to work), note: the source
code can be found in a repo, though}

## Using the tools ##

\inlinetodo{Ask to open a file with a text editor}

\inlinetodo{Extend explanation on how to compile}

\inlinetodo{ask to modify the file and see what happens}

Given the file `000-hello-world.cc`:

~~~cpp
#include <iostream>

int main()
{
  std::cout << "Hello World!" << std::endl;
  return 0;
}
~~~

compile the file into a executable with either `clang++` or `g++`:

\inlinetodo{add std option to make it C++11 compilant}

~~~bash
clang++ 000-hello-world.cc -o 000-hello-world.exe
g++ 000-hello-world.cc -o 000-hello-world.exe
~~~

and run it with:

~~~bash
./000-hello-world.exe
~~~

the output of the program in terminal will be:

~~~
Hello World!
~~~

<!-- vim:set filetype=markdown.pandoc : -->
