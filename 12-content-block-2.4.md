## More space to play with! Yay! ##

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
