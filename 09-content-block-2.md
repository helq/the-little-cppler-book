# Block 2: Going further with functions and more space to play with #

<!--
   -2. recursive functions, input, pass by reference, arrays, and string operations
   -  * introduce the magic of recursive functions
   -  * show examples of input from the user
   -  * show how variables passed as value don't change while passed by reference do
   -  * show things to get wrong with input from the user (from wrong type to unexpected
   -    stuff from spaces, tabs and newlines)
   -  * introduce arrays
   -  * show how arrays behave differently from any other value, and how they appear to be
   -    always pass by reference and not by value
   -  * arrays have many gotchas, like asking for a value outside the range of the array
   -  * possible exercises: copy content of an array from one to the other
   -  * (optional) tell them that many people, professionaly, don't like arrays and use
   -    better the standard libraries, which have a lot of functions for common things we
   -    have done already. Like, copying an array, printing it on the screen, ...
   -->

## Answering with a question ##

---

In maths we define addition (`+`) on natural numbers in the following way:

1. We define there is a `0`
2. We define every function has a successor: $n \in Z -> n + 1$
  \inlinetodo{write well}
3. We define how to add two numbers
  $$a + b = (if )$$ \inlinetodo{finish}

\inlinetodo{add function for succ}

How do you think `add(a, b)` can be defined?

= = =

\inlinetodo{write function for adding numbers}

\inlinetodo{digression, this is NOT how the computer adds, but this is how in maths
addition is defined}

---

\inlinetodo{add example how to multiply two numbers}

---

**Task for home**: Sort a given an array with 3 elements. For example:

~~~cpp
int elems[] = {3, 20, -2};

// Your code goes here

std::cout << elems[0] << " " << elems[1] << " " << elems[2] << std::endl;
// -> It should output: `-2 3 20`
~~~

---

**Task for home**: Given an array and its length, your task is to sort the array in
ascending order. For example:

~~~cpp
int elems[] = {3, 20, -2, 3, 4, -30, -2, 0, 12, 5, -100};
int n_elems = 11;

// Your code goes here

std::cout << "{ ";
for (int i=0; i<n_elems; i++) {
  std::cout << elems[i] << " ";
}
std::cout << "}" << std::endl;
// -> It should output: `{ -100, -30, -2, -2, 0, 3, 3, 4, 5, 12, 20 }`
~~~

---

What do you think this will output?

~~~{.cpp layout="01-simple.cc"}
char helloagain[] =
    {'H', 'e', 'l', 'l', 'o', ' ',
    'A', 'g', 'a', 'i', 'n', ' ', ':', ')'};
int hellolen = 14;

for (int i=0; i<hellolen; i++) {
  std::cout << helloagain[i];
}
std::cout << std::endl;
~~~

= = =

Well, it is just like a **string**, just like if we had written
`std::cout << "Hello Again :)" << std::endl;`{.cpp}:

~~~output
~~~

---

Good news everyone! What you see above is (almost) precisely how strings are saved on
memory, they are sequences of bytes!

We could write the above code as:

~~~{.cpp layout="01-simple.cc"}
char helloagain[] =
    {'H', 'e', 'l', 'l', 'o', ' ',
    'A', 'g', 'a', 'i', 'n', ' ', ':', ')', 0};

std::cout << helloagain << std::endl;
~~~

Notice that this time helloagain contains a final `0`. This is used to tell `std::cout`
when to stop.

= = =

The output as we expected:

~~~output
~~~

Or we could've written:

~~~cpp
char helloagain[] = "Hello Again :)";
std::cout << helloagain << std::endl;
~~~

---

What will this print?

~~~{.cpp layout="01-simple.cc"}
char helloagain[] =
    {'H', 'e', 'l', 'l', 'o', ' ', 0, //<- added
    'A', 'g', 'a', 'i', 'n', ' ', ':', ')', 0};

std::cout << helloagain << std::endl;
~~~

Notice the added `0` after "Hello ".

= = =

And the output is, uh, truncated:

~~~output
~~~

The line only prints to the point where it finds the first zero.

Alternatively, we could write:

~~~cpp
char helloagain[] = "Hello\0 Again :)";
std::cout << helloagain << std::endl;
~~~

---

\inlinetodo{show that a string can be manipulated}

\inlinetodo{add task to tell students to convert all capital case letters into small case}

---

<!-- vim:set filetype=markdown.pandoc : -->
