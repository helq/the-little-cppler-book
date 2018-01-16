## Basics

### Getting to know C++(11)

\inlinetodo{Add interludes asking whoever is reading to pause for a while to recover from
so much info}

---

What do you think the following code will output after compiling and running it?

~~~{.cpp layout="00-empty.cc"}
#include <iostream>

int main()
{
  std::cout << "Hello World!" << std::endl;
  return 0;
}
~~~

= = =

The output is:

~~~output
~~~

---

Now, what if you compile this other file:

~~~{.cpp layout="00-empty.cc"}
#include <iostream>

int main()
{
  std::cout << "Hello World!" << std::endl;
  std::cout << "I'm a program example and I'm "
            << "in English."
            << std::endl;
  return 0;
}
~~~

= = =

The output is:

~~~output
~~~

Pay close attention to the output, there are three sentences surrounded by quotation marks
(`"`), but there are only two lines in the output. Why?

---

If we change our example slightly (notice the semicolon (`;`)) what do you think it will
happen?

~~~{.cpp}
#include <iostream>

int main()
{
  std::cout << "Hello World!" << std::endl;
  std::cout << "I'm a program example and I'm ";
            << "in English."
            << std::endl;
  return 0;
}
~~~

= = =

Well, it doesn't compiles! We get an error similar to:

~~~
test.cc:7:13: error: expected expression
            << "in English."
            ^
~~~

It is telling us that it was expecting something (a `std::cout` for example) before `<<`.

Try removing or adding random characters (anywhere) to the example and you will find that
the compiler just admits a certain arrangement of characters and not much more. But, why?
Well, the compiler just understands the grammar of C++ as we just understand the grammar
of our human languages. Going a little further with the analogy, we can understand the
grammar of any human language (its parts (verbs, prepositions, ...) and how are they
connected) but we can only understand the meaning (semantics) of those languages we have
studied (or our mother tongues).

---

Does the following program compiles. If yes, what is its output?

~~~{.cpp layout="00-empty.cc"}
#include <iostream>

int main()
{
  std::cout << "Hello World!" << std::endl;
  std::cout << "I'm a program"
            << std::endl
            << "example and I'm"
            << std::endl
            << "in English."
            << std::endl;
  return 0;
}
~~~

= = =

Yep, it in fact compiles, and its output is:

~~~output
~~~

Notice how `std::endl` puts text in a new line, that's its whole job in fact.

---

<!-- vim:set filetype=markdown.pandoc : -->
