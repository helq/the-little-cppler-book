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

It is telling us that it was expecting something (a `std::cout`{.cpp} for example) before
`<<`{.cpp}.

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

Notice how `std::endl`{.cpp} puts text in a new line, that's in fact its whole job.

---

Well that's getting boring. What if we try something different for a change. What is the
otput of this program:

~~~{.cpp layout="00-empty.cc"}
#include <iostream>

int main()
{
  std::cout << "Adding two numbers: "
            << 2 + 3
            << std::endl;
  return 0;
}
~~~

= = =

Nice[^afootnote]

~~~output
~~~

[^afootnote]: this is a footnote, read all of them, they may tell you little things that
  the main text won't.

---

Let's try something a little more complex[^simplecode]

~~~{.cpp layout="01-simple.cc"}
std::cout
  << "A simple operation between " << 3
  << " " << 5 << " " << 20 << ": "
  << (3+5)*20 << std::endl;
~~~

[^simplecode]: Here you can see only a snippet of the whole code. The complete code
    the snippet represents can be found in the source accompaning this book.

    <!--TODO: Find a way to put verbatim inside footnotes-->

    <!--
    -~~~{.cpp .noframe}
    -#include <iostream>
    -
    -int main()
    -{
    -  std::cout
    -    << "A simple operation between " << 3
    -    << " " << 5 << " " << 20 << ": "
    -    << (3+5)*20 << std::endl;
    -  return 0;
    -}
    -~~~
    -->

    From now on, all code will be given on snippets for simplicity but remember that they
    are that, snippets, uncomplete pieces of code that need your help to get complete.

= = =

~~~output
~~~

---

What is the purpose of `<< " " <<`{.cpp} in teh code?

= = =

`<< " " <<`{.cpp} adds an space between the numbers otherwise the output would look weird.

---

What if we remove all spaces from the last example?

~~~{.cpp layout="01-simple.cc"}
std::cout
  << "A simple operation between " << 3
  << 5 << 20 << ": "
  << (3+5)*20 << std::endl;
~~~

= = =

~~~output
~~~

It looks aweful, doesn't it? Spaces are important as formatting!

---

Let's try it now multiline:

~~~{.cpp layout="01-simple.cc"}
std::cout
  << "A simple operation between " << std::endl
  << 3 << std::endl
  << 5 << std::endl
  << 20 << ": " << std::endl
  << (3+5)*20 << std::endl;
~~~

= = =

~~~output
~~~

---

Did you noticed that we only used a `std::cout`{.cpp}?

What is then the output of the code below?

~~~{.cpp layout="01-simple.cc"}
std::cout
  << "A simple operation between " << std::endl;
std::cout << 3 << std::endl;
std::cout << 5 << std::endl;
std::cout << 20 << ": " << std::endl;
std::cout << (3+5)*20 << std::endl;
~~~

= = =

~~~output
~~~

Yeah, it's the same as before!

Notice how the semicolon (`;`) indicates the ending of a statement in code. The code above
could all be written in a single line (and not in 6 lines) and it would output the
same:[^toolong]

[^toolong]: sorry, the single line is too long to show in here all at once.

~~~cpp
std::cout << ... << (3+5)*20 << std::endl;
~~~

Remember every `std::cout`{.cpp} is always paired with a semicolon (`;`) which indicates
the ending of its effects, like a _dot_ indicates the ending of a sentence or paragraph.

---

What happens if you try to compile and run this faulty code?

~~~cpp
std::cout
  << "A simple operation between " << std::endl;
std::cout << 3 << std::endl;
std::cout << 5 << std::endl
std::cout << 20 << ": " << std::endl;
std::cout << (3+5)*20 << std::endl;
~~~

= = =

It fails to compile because there is a semicolo missing in the code!

The error shown by the compiler is actually[^whyactually] useful here, it is telling us
that we forgot a `;`!

~~~
test.cc:8:30: error: expected ';' after expression
  std::cout << 5 << std::endl
                             ^
                             ;
1 error generated.
~~~

[^whyactually]: Why "actually"? Well, you will find that most of the time the errors
  thrown by the compiler are hard to understand, and it is often something that we
  programmers need to learn to do. We learn to understand the confusing error messages the
  compilers give us.

---

But what if we want to not input 5 or 20 twice?

What is the output of the code below?

\inlinetodo{remember to explain how to initialize using \texttt{\{\}}}

~~~{.cpp layout="01-simple.cc"}
int num_1 = 3;
int num_2 = 5;
int num_3 = 20;

std::cout
  << "A simple operation between "
  << num_1 << " "
  << num_2 << " "
  << num_3 << ": "
  << (num_1+num_2)*num_3
  << std::endl;
~~~

= = =

The output is:

~~~output
~~~

---

what is the output if you change the value 5 for 7?

~~~{.cpp .hidden layout="01-simple.cc"}
int num_1 = 3;
int num_2 = 7;
int num_3 = 20;

std::cout
  << "A simple operation between "
  << num_1 << " "
  << num_2 << " "
  << num_3 << ": "
  << (num_1+num_2)*num_3
  << std::endl;
~~~

= = =

The output is:

~~~output
~~~

---

`num_1` is a **variable** and it allows us to save integers on it, you can try changing
it's value for any number between $-2147483649$ and $2147483648$[^platformdependent]

[^platformdependent]: This numbers are based on a program compiled for a 32bit computer,
  the real values dependent between different computers.

What if we put $-12$ in the variable `num_1`?

~~~{.cpp .hidden layout="01-simple.cc"}
int num_1 = -12;
int num_2 = 5;
int num_3 = 20;

std::cout
  << "A simple operation between "
  << num_1 << " "
  << num_2 << " "
  << num_3 << ": "
  << (num_1+num_2)*num_3
  << std::endl;
~~~

= = =

The output is:

~~~output
~~~

---

\newpage

### Interlude: Variables ###

Now, it's  time to explain what are **variables** and what happens when we write
`int name = 0`{.cpp}.

`int name = 0`{.cpp} is equivalent to:[^onlyforsimpletypes]

~~~cpp
int name;
name = 0;
~~~

[^onlyforsimpletypes]: only for the simplest values `int`, `double`, ..., but not for
  objects. Objects are out of the scope of this book, but it is important to know they
  exist.

The first instruction **declares** a space for an `int` in memory (RAM memomry).

So, let's study the architecture of computers, mainly RAM and CPU.

\inlinetodo{ADD explanation on the architecture of computers}

`int name;`{.cpp} then is telling the compiler to reserve (_declare_) some space that nobody
else should use. This space can have any value we want. Because this space in memory could
have been used by anybody else in the past, its value is _nondefined_, meaning that it can
be anything. Therefore we use the next line `name = 0;`{.cpp} to save a zero in the space
declared.

BEWARE! `name = 0;`{.cpp} is NOT an equation!

I repeat, `name = 0;`{.cpp} is NOT an equation!, you are **assigning** a value to a
variable, you could easily assign many different values to a variable, though just the
last one will stay in memory:

```cpp
int name;
name = 0;
name = 12;
```

The procedure of _declaring_ and then _assigning_ a value to a variable is so common that
the designers of the language have made a shortcut:

```cpp
int name = 0;
```

Now, let's go back to the code!

\newpage

---

What is the output of:

~~~{.cpp layout="01-simple.cc"}
int var1 = 6;
int var2 = 3;
int var3 = 10;

std::cout
  << (var1+var2) * var3 - var2
  << std::endl;
~~~

= = =

The output is:

```output
```

---

What is the output of:

~~~.cpp
int var1 = 6;
int var2 = 3;

std::cout
  << (var1+var2) * var3 - var2
  << std::endl;

int var3 = 10;
~~~

= = =

Yeah, it doesn't compile, you are trying to use a variable *before* declaring it (asking
for a space in memory to use it). The compiler gives you the answer:

```
test.cc:9:20: error: use of undeclared identifier 'var3'
  << (var1+var2) * var3 - var2
                   ^
1 error generated.
```

ORDER (of sentences) is key! It is not the same to say "Peter eats spaguetti, then Peter
clean his teeth" than "Peter clean his teeth, then Peter eats spaguetti".

A program runs sequentially from the first line of code to the last

---

What is the output of:

~~~{.cpp layout="01-simple.cc"}
int var1 = 6;
int var2 = 3;
int var3 = 10;

var2 = var1*3;

std::cout
  << (var1+var2) * var3 - var2
  << std::endl;
~~~

= = =

The output is:

```output
```

We can in fact assign to the variable (at the left of `=`) any `int`{.cpp} value result of any
computation. In this case, the computation `var1*3`{.cpp} is assigned to `var2`{.cpp}

---

What is the output of:[^includes]

~~~{.cpp layout="01-simple.cc"}
#include <cmath>
...
int var1 = 6;
int var2 = 3;
int var3 = var1 * pow(var2, 3);

std::cout << "var1 * pow(var2, 3) => "
          << var3 << std::endl;
~~~

[^includes]: Notice the dots (`...`) in the code above. This dots are just for notation,
    they aren't meant to be written in the source code. The dots represent a division
    between two different parts of code.

    \inlinetodo{Add whole file here}

= = =

The output is:

```output
```

Remember that

```{.cpp .noframe}
int var3 = var1 * pow(var2, 3);
```

is equivalent to

```{.cpp .noframe}
int var3;
var3 = var1 * pow(var2, 3);
```

---


<!-- vim:set filetype=markdown.pandoc : -->
