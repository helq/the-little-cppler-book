## Breaking the code into pieces ##

\inlinetodo{add what happens when we call return and we write code after}

---

What does the following code does?

~~~{.cpp layout="01-simple.cc"}
double acction   = 9.8; // m/s^2 acceleration
double mass      = 3;   // kg    mass

double initial_v = 10;  // m/s   ini. velocity
double time      = 2.3; // s     time passed

double final_v = initial_v + acction * time;
double momentum = mass * final_v;
std::cout << "Momentum after " << time
          << "s is: " << momentum << "kg*m/s"
          << std::endl;

time = 4.2;
final_v = initial_v + acction * time;
momentum = mass * final_v;
std::cout << "Momentum after " << time
          << "s is: " << momentum << "kg*m/s"
          << std::endl;

time = 9;
final_v = initial_v + acction * time;
momentum = mass * final_v;
std::cout << "Momentum after " << time
          << "s is: " << momentum << "kg*m/s"
          << std::endl;
~~~

= = =

It prints the result of applying the same formula to different values. Its output is:

~~~output
~~~

You see all that repeated code! Wouldn't it be cool if we could just write that once and
use it many times?

---

Introducing **functions**. What do you think the following code will do?

~~~{.cpp layout="00-empty.cc"}
#include <iostream>

void momentum(double initial_v, double time) {

  double acction   = 9.8; // m/s^2 acc
  double mass      = 3;   // kg    mass

  double final_v = initial_v + acction * time;
  double momentum = mass * final_v;
  std::cout << "Momentum after " << time
            << "s is: " << momentum << "kg*m/s"
            << std::endl;
}

int main() {
  momentum(10, 2.3);
  momentum(10, 4.2);
  momentum(10, 9);

  return 0;
}
~~~

= = =

Its output is the same as the code above, but we have eliminated all the repeated code.

~~~output
~~~

`momentum` is called a _function_ (or procedure in old people talk terms), and it consists
in a piece of code that can be run by calling it with the syntax `momentum(num1, num2)`
(where `num1` and `num2` are either numbers or expressions that evaluate to numbers
(`double`)).

Functions need to be defined outside `main` because `main` itself is a function! And
functions cannot be defined[^yeahlambda] inside a function.

[^yeahlambda]: actually, it is possible to define as many functions as one may like inside
  another function, but requires object oriented stuff to understand. For more info see
  "lambda functions".

---

What should we be modify in the function `show_addition` for it to output the right answer?

~~~{.cpp layout="00-empty.cc"}
#include <iostream>

void show_addition(int a, int b) {
  std::cout << a << " + " << b
            << " == " << a*b;
}

int main() {
  for (int i=4; i<=7; i++) {
    show_addition(i,3);
  }

  return 0;
}
~~~

= = =

Yeah, we are using the wrong operation, it shouldn't be `*`, it should be `+`. Also, we
didn't add a newline after each new statement. The new function should be written as:

~~~cpp
void show_addition(int a, int b) {
  std::cout << a << " + " << b
            << " == " << a+b
            << std::endl;
}
~~~

Notice how we do NOT use in `show_addition` the variable names we declared in `main`.
Remember the scope thing? Well, each function has its own variables and they are invisible
to all the other. When you call/run/invoque a function, you are copying the values of the
variables in your scope to a newly created scope for the function.

---

Now, what will this code output?

~~~{.cpp layout="00-empty.cc"}
#include <iostream>

void add_two_nums(int a, int b, int c) {
  c = b + a;

  std::cout << "a == " << a << std::endl;
  std::cout << "b == " << b << std::endl;
  std::cout << "c == " << c << std::endl;
}

int main() {
  int first  = 4;
  int second = 3;
  int total  = -2;

  add_two_nums(first, second, total);

  std::cout
    << "total == " << total << std::endl;

  return 0;
}
~~~

= = =

The output is

~~~output
~~~

weird, isn't it? No, it is not weird. When we call/run the function `add_two_nums` we copy
the variables values to newly created variables `a`, `b` and `c`, which are only visible
to the function `add_two_nums` and not to `main`.

---

Have you noticed the `void`{.cpp} word[^actuallykeyword] at the definition of the
function?

[^actuallykeyword]: `void`{.cpp} is actually a keyword, i.e., a word that is special for
  C++, nobody can use void as a name for a variable or function.

`void`{.cpp} tells us that the function doesn't return any value as a result of its
computation. There are other keywords that tell us when a function returns something, for
example, the keyword `int`{.cpp}.

What, do you think, is the output of the following code:

~~~{.cpp layout="00-empty.cc"}
#include <iostream>

int addtwice(int a, int b) {
  int c = 2 * (a + b);
  return c;
}

int main() {
  std::cout << addtwice(5, 3) << std::endl;
  return 0;
}
~~~

= = =

The output is:

~~~output
~~~

When you call a function, you pass it some data (variables values), the function makes
some calculation and returns, optionally, some result value.

---

**Task for home:** Write a function that takes two integers (`int`{.cpp}) and returns
6 if the sum of the integers is even otherwise -2, i.e., code the function below in C++:

$$ someScore(x, y) =
  \begin{cases}
    6                  & \quad \text{if } x + y \text{ is even} \\
    -2                 & \quad \text{otherwise}
  \end{cases} $$

---

What is the output of:[^twoinone]

[^twoinone]: Note: the statement `total += i;`{.cpp} is equivalent to
  `total = total + i;`{.cpp}. There are several shourtcut versions for other operations
  like `*`, `-`, `/`, `%`: `*=`, `-=`, `/=`, `%=`.

~~~{.cpp layout="00-empty.cc"}
#include <iostream>

int sumToN(int n) {
  int total = 0;
  for (int i=0; i<=n; i++) {
    total += i;
  }
  return total;
}

int main() {
  if (sumToN(20) > 100) {
    std::cout << "1+2+..+20 > 100"
              << std::endl;
  } else {
    std::cout << "1+2+..+20 <= 100"
              << std::endl;
  }

  return 0;
}
~~~


= = =

The output is:

~~~output
~~~

---

What is the output of:

~~~{.cpp layout="00-empty.cc"}
#include <iostream>
#include <cmath>

double aproxTan(double angle) {
  return sin(angle) / cos(angle);
}

int main() {
  double angle = 0.2;
  double pi = 3.14159265358979;
  std::cout
    << "The tangent of " << angle << "pi "
    << "is aprox. " << aproxTan(pi*angle)
    << std::endl;

  return 0;
}
~~~

= = =

Yeah, we have a calculator on steroids:

~~~output
~~~

---

Does this code compile? (notice we changed `double angle`{.cpp} for `int angle`{.cpp}),
if yes, what is the output?

~~~{.cpp layout="00-empty.cc" flags="-Wno-literal-conversion"}
#include <iostream>
#include <cmath> // for `sin` and `cos` functions

double aproxTan(double angle) {
  return sin(angle) / cos(angle);
}

int main() {
  int angle = 0.2;
  double pi = 3.14159265358979;
  std::cout
    << "The tangent of " << angle << "pi "
    << "is aprox. " << aproxTan(pi*angle)
    << std::endl;

  return 0;
}
~~~

= = =

Yeah, it does compile. And the result is:

~~~output
~~~

What is happening is that we are assigning a `double`{.cpp} (`0.2`) to an `int`{.cpp}
(`angle`). In this process, the value gets converted to a value that can be stored in an
`int`{.cpp}, meaning that we loose the fractional part of `0.2` leaving us with `0`.

Then `angle` gets converted (or **cast**) from an `int` to a `double`, because it is being
operated with `pi` which is a variable that holds a `double`[^castrule]

[^castrule]: General rule: the compiler detects if the operators in a binary operation are
  both of the same type, if they aren't, the compiler **casts** the value that contains
  the _less_ information to a type with more information, e.g., `int`{.cpp} -> `double`{.cpp},
  `int`{.cpp} -> `long`{.cpp}, `float`{.cpp} -> `double`{.cpp}

---

What is the output of:

~~~{.cpp layout="00-empty.cc"}
#include <iostream>
#include <cmath>

int aproxTan(int angle) {
  return sin(angle) / cos(angle);
}

int main() {
  double angle = 0.2;
  double pi = 3.14159265358979;
  std::cout
    << "The tangent of " << angle << "pi "
    << "is aprox. " << aproxTan(pi*angle)
    << std::endl;

  return 0;
}
~~~

= = =

The output is:

~~~output
~~~

No surprise here. `pi` and `angle` are variables of type `double`{.cpp}, when we operate
with them we get a value of type `double`{.cpp}. But, once we pass the value to
`aproxTan`, it gets cast to `int`{.cpp} because `aproxTan` receives `int`{.cpp}s, and
returns `int`{.cpp}s. The value of tangent that gets computed is the integer part of
`0.2 * pi`, i.e., `0`.

---

What do you think the following outputs?[^forcecast]

~~~{.cpp layout="01-simple.cc"}
std::cout
  << (int)5.3      << " "
  << (int)5.8      << " "
  << ((int)5.3)*2  << " "
  << (int)(5.3*2)  << " "
  << 3/2           << " "
  << (double)3/2   << " "
  << (double)(3/2) << std::endl;
~~~

[^forcecast]: We can force a cast by prepending the value to cast with _`(type)`_, where
  _`type`_ can be any type of the many we have seen, for example, `(int)12.1`{.cpp} casts `12`
  (a `double`{.cpp} or `float`{.cpp}) into an `int`{.cpp}.

= = =

The output is:

~~~output
~~~

**Task for home:** Define a function (in C++) that takes a number $n$ (a `double`{.cpp})
and returns the smallest integer $m$ (an `int`{.cpp}) such that $m \geq n$. For example:

~~~cpp
smallestBig(5.3) == 6
smallestBig(8.9) == 9
smallestBig(2.0) == 2
~~~

---

Files are sequences of bytes[^mostofthetime]. A byte contains 8 bits, which means that we
have $2^8$ different possibilities/states of a byte. We have `00000000`, but also
`00000001`, and `10110001`, all representable as numbers in decimal notation (the first
one in decimal notation is 0, the second is 1, and the third is
$2^7 + 2^5 + 2^4 + 2^0 = 177$)[^moreinfobytes]

[^mostofthetime]: Most of the time
[^moreinfobytes]: If you want to know how precisely convert from binary to decimal, and
  viceversa, please visit Wikipedia's article: _Binary number_.

Do you remember which of the following types has size one byte?

`int`{.cpp}, `float`{.cpp}, `char`{.cpp}, and `double`{.cpp}.

= = =

Yeah, it was `char`{.cpp}, we can save up to 256 numbers in a char (from -128 to 127).

---

We can represent each of these 256 possibilities in many ways, one of them is a decimal
number, but other possibility is assigning arbitrarily a symbol to each. Somebody has
already done the work for us here, and it is called ASCII. For example, the byte
`01000001`, in decimal is 65, and the symbol given to it is: `'A'`. This means we can
print a single character by saving 65 in a `char`{.cpp} variable and printing it:

~~~{.cpp layout="01-simple.cc"}
char symbol = 65;

std::cout << symbol << std::endl;
~~~

= = =

The output as expected:

~~~output
~~~

---

Because when we print a `char`{.cpp} variable we print its ASCII symbol, then there is a
simpler way to input the value to the variable, using single quotes (`'`).

This

~~~cpp
char symbol = 'A';

std::cout << symbol << std::endl;
~~~

prints the same as above. What do you think this will print?

~~~{.cpp layout="01-simple.cc"}
char symbol = 'A';

while (symbol <= 'Z') {
  std::cout << symbol;
  symbol++;
}
std::cout << std::endl;
~~~

= = =

All characters from `A` to `Z`! (as they're defined in the Enghlish alphabet)

~~~output
~~~

---

Now let's try to print more characters (if you look at the ASCII table (online or
somewhere), you will notice that not all characters are visible, therefore we will print
just a subset of the characters):

~~~{.cpp layout="01-simple.cc"}
char symbol = 32; // first "visible" character

while (symbol < 127) {
  std::cout << symbol;
  symbol++;
  if (symbol % 32 == 0) {
    std::cout << std::endl;
  }
}
std::cout << std::endl;
~~~

= = =

Well, a list of all characters available to us.[^allotherchars]

[^allotherchars]: All symbols for the other 128 characters, which values are between 128
  and 255, are machine dependent, they will render in the windows console but not anywhere
  else (If you want to know more I recommend Wikipedia's articles on _Unicode_ and
    _UTF-8_).

~~~output
~~~

---

**Task for home**: Write a function that takes a `char`{.cpp} variable with a value
between `A` and `Z`, and returns it in small case, for example:

~~~cpp
char toSmallCase(char c) {
  // your code goes here
}

int main() {
  char capitalCase = 'M';
  char smallCase = toSmallCase(capitalCase);
  std::cout << capitalCase << std::endl;
}
~~~

And it should print:

~~~
m
~~~

---

\inlinetodo{Add two more exercises to practice with fors and whiles}

\newpage

<!-- vim:set filetype=markdown.pandoc : -->
