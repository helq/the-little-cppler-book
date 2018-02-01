# Block 1: Basics #

<!--
   -1. basic operations, output, if, for, while, and functions
   -->

## Getting to know C++(11) ##

\inlinetodo{Add interludes asking whoever is reading to pause for a while to recover from
so much info}

\inlinetodo{Add a space before footnotes}

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

Well, it doesn't compile! We get an error similar to:

~~~
:7:13: error: expected expression
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

What is the purpose of `<< " " <<`{.cpp} in the code?

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

It fails to compile because there is a semicolon missing in the code!

The error shown by the compiler is actually[^whyactually] useful here, it is telling us
that we forgot a `;`!

~~~
:8:30: error: expected ';' after expression
  std::cout << 5 << std::endl
                             ^
                             ;
1 error generated.
~~~

[^whyactually]: Why "actually"? Well, you will find that most of the time errors
  thrown by the compiler are hard to understand. It is often something that we
  programmers need to learn to do. We learn to understand the confusing error messages
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
it's value for any number between $-2147483648$ and $2147483647$[^platformdependent]

[^platformdependent]: This numbers are based on a program compiled for a 32bit computer,
  the values may vary between different computers.

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
:9:20: error: use of undeclared identifier 'var3'
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

What is the output of:

~~~{.cpp layout="01-simple.cc"}
int var1 = 6;
std::cout << var1 << " ";
var1 = 20;
std::cout << var1 << " ";
var1 = -5;
std::cout << var1 << std::endl;
~~~

= = =

The output is:

```output
```

---

What is the output of:

~~~cpp
int var1 = 6;
std::cout << var1 << " ";
int var1 = 20;
std::cout << var1 << " ";
var1 = -5;
std::cout << var1 << std::endl;
~~~

= = =

It doesn't compile because you cannot ask for more space in memory (declare) with the same
name variable, you gotta use a different name.[^shadowscope]

[^shadowscope]: this will be truth until we learn how to "shadow" a variable name with
  help of scopes \inlinetodo{mm..., doesn't sound that good, rewrite}

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

Till now we've seen just two operations (`*` and `+`), but there are plenty more:

~~~{.cpp layout="01-simple.cc"}
int var1 = (2 + 18 - 6 * 2) * 5;
int var2 = var1 / 3;
int var3 = var1 % 3;

std::cout << "var1 => " << var1 << std::endl;
std::cout << "var2 => " << var2 << std::endl;
std::cout << "var3 => " << var3 << std::endl;
~~~

= = =

The output is:

~~~output
~~~

You probably know all operations here, but maybe not `%`. It is the _modulus_ operation, or
residue operation, and it symbolises the result of the residue of dividing integer
numbers.

For example, the result of dividing $50$ by $3$ can be written as:

$$ 50 = 3 \times 16 + 2 $$

Where $50$ is the dividend, $3$ is the divisor, $16$ the (integer) result, and $2$ the
modulus/remainder.

If an integer is divisible by another then the modulus of operating them must be $0$,
e.g., $21 = 7 \times 3 + 0$.

---

What is the output of:

~~~{.cpp layout="01-simple.cc"}
std::cout << 8 % 3 << " "
          << 8 % 2 << " "
          << 7 % 2 << " "
          << 17 % 1 << " "
          << 17 % 7 << " "
          << std::endl;
~~~

= = =

The output is:

~~~output
~~~

---

~~~{.cpp layout="01-simple.cc"}
std::cout << 20 - 6 * 2 << " "
          << (20 - 6) * 2 << " "
          << 20 - (6 * 2) << " "
          << std::endl;
~~~

= = =

~~~output
~~~

Notice how `20 - 6 * 2` does reduce^[or compute] to $8$ and not to $28$! (i.e.,
$20-6 \times 2 = 20-(6 \times 2) \neq (20-6) \times 2$). Each operator has a specific
precedence that indicates if it must be applied before another operator, `*` for example
has a higher precedence than `+`.

---

\inlinetodo{add exercises about all of this}

\inlinetodo{add one exercise that ask students to write a program with a single
compilation error and ask another to find it and correct it}

---

What is the output of:[^double]

~~~{.cpp layout="01-simple.cc"}
double acction   = 9.8; // m/s^2 acceleration
double mass      = 3;   // kg    mass
double initial_v = 10;  // m/s   ini. velocity
double time      = 2.3; // s     time passed

double final_v = initial_v + acction * time;

std::cout << "Velocity after " << time
          << "s is: " << final_v << "m/s"
          << std::endl;

double momentum = mass * final_v;

std::cout << "Momentum after " << time
          << "s is: " << momentum << "kg*m/s"
          << std::endl;
~~~

[^double]: `double`{.cpp} allows us to declare "real" numbers (they are actually
  rational). And we can operate with them as we did with `int`{.cpp}'s

= = =

The output is:

~~~output
~~~

We are using here the equation $v = u + a*t$ to determine the final velocity of an object
(in a line) after $2.3 s$. The object starts with a velocity $2.3 m/s$, has a constant
acceleration of $9.8 m/s^2$^[free fall ;)], and we know the weight of the object, so we
can calculate too its momentum.

---

What is the output of:

~~~{.cpp layout="01-simple.cc"}
int var1 = 8;
if (var1 < 10) {
  std::cout << "var1 smaller than 10"
            << std::endl;
} else {
  std::cout
    << "var1 greater than or equal to 10"
    << std::endl;
}
~~~

= = =

The output is:

~~~output
~~~

---

What is the output of the code above if we change `var1`'s assignment from `8` to `19`?

~~~{.cpp layout="01-simple.cc" .hidden}
int var1 = 19;
if (var1 < 10) {
  std::cout << "var1 smaller than 10"
            << std::endl;
} else {
  std::cout
    << "var1 greater than or equal to 10"
    << std::endl;
}
~~~

= = =

The output is:

~~~output
~~~

Precisely, the second line runs but not the first.

The structure:

~~~cpp
if (statement) {
  true branch
} else {
  false branch
}
~~~

runs the `true branch` if the statement `statement` evaluates to `true` otherwise it
runs the `false branch`.

---

What about the output of

~~~{.cpp layout="01-simple.cc"}
int var1 = 10;
if (var1 == 7 + 3) {
  std::cout << "var1 is equal to 7 + 3"
            << std::endl;
} else {
  std::cout << "var1 does not equal 10"
    << std::endl;
}
~~~

= = =

Well, that's easy:

~~~output
~~~

Note, `==` is the equality operation[^noassign], and it compares any two statements as
`var1` or `3+2*12` for equality.

As you expect it, there are many operations to compare between different statements, these
are `==`, `<=`, `>=`, `<`, `>`, and `!=`.

[^noassign]: take care, don't confuse it with the assignment operator `=`!

---

What is the output of:

~~~{.cpp layout="01-simple.cc"}
int var1 = 2*2+2;
if (var1 != 7 + 3) {
  std::cout << "2*2+2 != 7+3" << std::endl;
} else {
  std::cout << "2*2+2 == 7+3" << std::endl;
}
~~~

= = =

The output is:

~~~output
~~~

Yeah, `!=` is the unequality operator.

---

What is the output of:

~~~{.cpp layout="01-simple.cc"}
int var1 = 2*2+20;
if (var1 >= 7 + 3) {
  std::cout << "i never run :(" << std::endl;
} else {
  if (var1 > 23) {
    std::cout << "hey!!" << std::endl;
  } else {
    // nothing in this branch
  }
}
~~~

= = =

The output is:

~~~output
~~~

Usually, if we only care about the true branch of an `if` statement, then we simply ignore
it. The code at left is equivalent then to:

~~~cpp
int var1 = 2*2+20;
if (var1 >= 7 + 3) {
  std::cout << "i never run :(" << std::endl;
} else {
  if (var1 > 23) {
    std::cout << "hey!!" << std::endl;
  }
}
~~~

---

It's possible to put more than one statement inside the `if` statement. For example:

~~~{.cpp layout="01-simple.cc"}
int var1 = 2*2+20;
if (var1 >= 7 + 3) {
  std::cout
    << "you are our visitor number 3889"
    << std::endl;
  int magicnumber = 999999;
  std::cout
    << "and your our winner! please "
    << "deposit " << magicnumber
    << " into our account and you will "
    << " receive 20x what you deposited "
    << std::endl;
}
std::cout
  << "Welcome to e-safe-comerce"
  << std::endl;
~~~

= = =

The output as you expected.

~~~output
~~~

---

~~~{.cpp layout="01-simple.cc"}
int magicnumber = -2;
if (2!=3) {
  magicnumber = 0;
} else {
  magicnumber = 42;
}
std::cout << "Every integer is a divisor of "
          << magicnumber << std::endl;
~~~

= = =

Of course, $0$ can be divided by any number, because it can be written as
$0 = k*n$ where $k=0$ and $n$ is an arbitrary number.

~~~output
~~~

---

What is the output of:

~~~cpp
if (2!=3) {
  int magicnumber = 0;
} else {
  int magicnumber = 42;
}
std::cout << "Every integer is a divisor of "
          << magicnumber << std::endl;
~~~

= = =

It doesn't compile! You wanna know why? Well, keep guessing with the following exercises.

---

Does this compile? If yes, then what is its output?

~~~{.cpp layout="01-simple.cc"}
int magicnumber = -2;
if (2!=3) {
  int magicnumber = 0;
} else {
  int magicnumber = 42;
}
std::cout << "Every integer is a divisor of "
          << magicnumber << std::endl;
~~~

It does compile, and its output is:

= = =

~~~output
~~~

But wait, what? -2 is not always divisible by anyother integer!

---

Maybe, $2$ and $3$ are really the same thing.

~~~{.cpp layout="01-simple.cc"}
int magicnumber = -2;
if (2==3) {
  int magicnumber = 0;
} else {
  int magicnumber = 42;
}
std::cout << "Every integer is a divisor of "
          << magicnumber << std::endl;
~~~

= = =

The output is:

~~~output
~~~

But is the same, why? What have we changed from before? What is the difference with the
code that gives us a zero?

---

Ok, let's stop with the silliness and try with an example that actually give us some clue
of the situation.

~~~{.cpp layout="01-simple.cc"}
int num = 20;
std::cout << num << " ";
{
  int num = 42;
  std::cout << num << " ";
  num = 3;
  std::cout << num << " ";
}
std::cout << num << " ";
num = 0;
std::cout << num << std::endl;
~~~

= = =

Well, the code inside the brackets (`{}`) acts as if it was being run alone without the
intervention of the code of the outside.

~~~output
~~~

It is effectively as if this was the code being run:

~~~cpp
int num = 20;
std::cout << num << " ";
{
  int var = 42;
  std::cout << var << " ";
  var = 3;
  std::cout << var << " ";
}
std::cout << num << " ";
num = 0;
std::cout << num << std::endl;
~~~

---

Any time we enclose code between brackets (`{}`) we are defining a new **scope**. Any
variable we declare inside a scope lives only in that scope, the variable _dies_ once the
scope is closed, is this the reason why this code

~~~cpp
{
  int num = 42;
  std::cout << num << " ";
}
std::cout << num << std::endl;
~~~

doesn't compile. There is no `num`{.cpp} variable in the bigger scope when it wants to
show it.

A rule about scopes is that they can access to variables from the outside, scopes that
enclose them. For example this code, does indeed compiles:

~~~{.cpp layout="01-simple.cc"}
int num = 42;
std::cout << num << " ";
{
  num = 1;
  std::cout << num << " ";
}
std::cout << num << std::endl;
~~~

What is its output?

= = =

You guessed it right! Given that `num`{.cpp} is a variable outside the inner scope, the
inner scope can read and modify the variable content.

~~~output
~~~

---

What is the output of:

~~~{.cpp layout="01-simple.cc"}
int num = 42;
std::cout << num << std::endl;
{
  int num = 1;
  std::cout << num << std::endl;
}
std::cout << num << std::endl;
{
  num = 1;
  std::cout << num << std::endl;
}
std::cout << num << std::endl;
~~~

= = =

~~~output
~~~

Right, in the first inner scope, we declare a new space and shadow the access to the
outside variable `num`{.cpp}, and in the other inner scope, we use the variable accessible
from the outside scope.

---

What is the output of:[^float]

~~~{.cpp layout="01-simple.cc"}
int a = 20;
int b = 21;
if (b-a > 0) {
  float num = -12.2;
  std::cout << num * 3 << std::endl;
} else {
  double num = -12.2;
  std::cout << num * -3 << std::endl;
}
~~~

[^float]: yet again another type of data. `float`{.cpp}s are like `double`{.cpp}s but they
  represent numbers with less precision. Well I haven't talked what precision is, forgive
  me, for the time being just assume that using `double`{.cpp} in your code is better than
  using `float`{.cpp}.
  \inlinetodo{explain at some point what do you mean by precision, maybe another interlude
  could be helpful here}

= = =

The output is:

~~~output
~~~

---

What does this output:

~~~{.cpp layout="01-simple.cc"}
int n = 15;
bool either = n<3;
if (either) {
  std::cout << ":P" << std::endl;
} else {
  std::cout << ":(" << std::endl;
}
~~~

= = =

The output is:

~~~output
~~~

with `bool`{.cpp}[^booltruth] we tell the compiler that it should interprete `either` as a boolean
(either `true`{.cpp} or `false`{.cpp}).

[^booltruth]: True and False are the only two possible values that a statement can take
  in traditional logic, and so it does for us, there are only two options for bool. But
  modern computers are build on blocks of 32 or 64 bits and operations, therefore, with
  values of 32 and 64 bits are cheap to perform. Operations on single bits are not simple
  when you manipulate multiple bits, it is slightly more expensive to use a single bit to
  represent truth or false. Compilers usually use a block of memory (32 or 64 bits) to
  represent a boolean, the convention is for zero (all 32-64 bits in zero) to be false and
  anything else (eg, all bits in zero, or only one bit in zero, etc) to be true.

  This means that you can in fact store integer values inside a bool (i.e.,
  `bool bad = 23;`) but it's consider bad practice and may result in undefined behaivor.

---

Let's take a look at another type of variable, `char`{.cpp}:[^ignorecast]

~~~{.cpp layout="01-simple.cc"}
char apples = 23;
std::cout << "A small integer: " << (int)apples
          << std::endl;
~~~

[^ignorecast]: you can ignore the weird `(int)`{.cpp} thing for now, it is
  called **cast** if you are curious, we will get to them later on.

= = =

The output isn't surprising:

~~~output
~~~

`char`{.cpp} may not seem different to `int`{.cpp}, but it is. `int`, dependending on the
system, has a size of 32 or 64, but `char` has always the same size 8 bits. With 8 bits we
can represent $2^8$ different states, that is 256 different numbers.

---

What is the output of:

~~~{.cpp layout="01-simple.cc"}
int i = 2;
std::cout << i << " ";
i = i + 1;
std::cout << i << " ";
i = i + 1;
std::cout << i << " ";
i = i * 3;
std::cout << i << std::endl;
~~~

= = =

The output is:

~~~output
~~~

---

Every compiler may define the size of `int`, `char`, `double`, ..., differently depending
on the architecture. If you want to know how many bytes[^abyte] are assigned to any
variable type, you can use `sizeof`{.cpp}. An example of use:

[^abyte]: one byte is 8 bits

~~~{.cpp layout="01-simple.cc"}
std::cout << "A char   is " << sizeof(char)
          << " bytes" << std::endl;
std::cout << "A int    is " << sizeof(int)
          << " bytes" << std::endl;
std::cout << "A double is " << sizeof(double)
          << " bytes" << std::endl;
std::cout << "A float  is " << sizeof(float)
          << " bytes" << std::endl;
std::cout << "A bool   is " << sizeof(bool)
          << " bytes" << std::endl;
~~~

(Hint: if a byte is 8 bits, a `char` is 8 bits, how many bytes are a `char`?)

= = =

This may look different in your computer, but mine runs on 64 bits, therefore `double` has
64 bits and `int` half of that.

~~~output
~~~

---

What is the output of:

~~~{.cpp layout="01-simple.cc"}
char a = 100;
char b = 20;
char c = a + b;
std::cout << "a : " << (int)a << std::endl
          << "b : " << (int)b << std::endl
          << "a+b : " << (int)c << std::endl;
~~~

= = =

Not surprising, that is the output.

~~~output
~~~

---

What is the output of:

~~~{.cpp layout="01-simple.cc"}
char a = 100;
char b = 30;
char c = a + b;
std::cout << "a : " << (int)a << std::endl
          << "b : " << (int)b << std::endl
          << "a+b : " << (int)c << std::endl;
~~~

= = =

The output is:[^charchange]

~~~output
~~~

[^charchange]: This output may change depending on the compiler you are using, it could
  happened that you don't see anything wrong at all. In that case, try changing `100` for
  `220`.

well, that's surprising! What the heck happened?

The answer lies in the 8 bit part that I was talking about. `char`{.cpp} can only hold 256
different numbers, but usually we use one of those bits to indicate the
sign[^notruthsign], therefore we have left only 7 bits for the number. $2^7$ is $128$, so
we can store 128 positive numbers and 128 negative numbers. If we did it naïvely we could
represent the numbers from 0 to 127 with 7 bits plus one bit for the sign, but that's
rarely used, we would be representing 0 in two ways +0 and -0, the answer is to count from
0 to 127 and from -128 to -1, i.e., we can lay down all the representable numbers by 8
bits in the following way: -128, -127, -126, ..., -2, -1, 0, 1, 2, ..., 125, 126, 127.

[^notruthsign]: For more details look at "two's complement binary representation"

When you pass over the limit of what 7 bits[^overflow] can store you need to go somewhere,
and by convention that is going back to the first number, i.e., adding numbers one by one
will lead you to the begining no matter where you start: $1+1=2$, $2+1=3$, ..., $125+1=126$,
$127+1=-128$, $-128+1=-127$, ..., $-1+1=0$, $0+1=1$.

[^overflow]: this is called overflow

---

What is the output of:

~~~{.cpp layout="01-simple.cc"}
char i = 126;
std::cout << (int)i << " ";
i = i + 1;
std::cout << (int)i << " ";
i = i + 1;
std::cout << (int)i << " ";
i = i + 1;
std::cout << (int)i << std::endl;
~~~

= = =

The output, as you may have easily guessed is:

~~~output
~~~

---

\newpage

### Interlude: How are numbers represented? ###


\inlinetodo{fill me!}

\newpage

---

What is the output of:

~~~{.cpp layout="01-simple.cc"}
int i = 0;
if (i<3) {
  std::cout << "There is no else statement";
  i = i * 2;
}
std::cout << std::endl;
~~~

= = =

The output is:

~~~output
~~~

Notice how we ignored the `else`{.cpp} statement, well that's ok, we can just do stuff for
when something is true otherwise we don't do anything.

---

What is the output of:

~~~{.cpp layout="01-simple.cc"}
int i = 0;
if (i<3) {
  std::cout << i << " ";
  i = i + 1;
}
if (i<3) {
  std::cout << i << " ";
  i = i + 1;
}
std::cout << std::endl;
~~~

= = =

The output is:

~~~output
~~~

---

What is the output of:

~~~{.cpp layout="01-simple.cc"}
int i = 0;
if (i<3) {
  std::cout << i << " ";
  i = i + 1;
}
if (i<3) {
  std::cout << i << " ";
  i = i + 1;
}
if (i<3) {
  std::cout << i << " ";
  i = i + 1;
}
if (i<3) {
  std::cout << i << " ";
  i = i + 1;
}
std::cout << std::endl;
~~~

= = =

The output is:

~~~output
~~~

---

What is the output the above if we change all appearances of `i<3`{.cpp} for `i<2`{.cpp}
or `i<4`{.cpp}.

= = =

The outputs are:

~~~cpp
0 1
~~~

for `i<2`{.cpp} and

~~~cpp
0 1 2 3
~~~

for `i<4`{.cpp}.

---

What is the output if we change `i<3`{.cpp} for `i<5`{.cpp}?

= = =

Well there are only 4 `if`{.cpp}s, the limit is 4 numbers printed on the screen:

~~~cpp
0 1 2 3
~~~

---

What should we do to print five numbers?

= = =

Well, there are many options. We could add a `std::cout << i << std::endl;`{.cpp} line
after the last `if`{.cpp} statement, or we could copy an `if`{.cpp} (and this is what I
wanted you to answer)

---

What do you think this outputs?

~~~{.cpp layout="01-simple.cc"}
int i = 0;
while (i<4) {
  std::cout << i << " ";
  i = i + 1;
}
std::cout << std::endl;
~~~

= = =

The output is:

~~~output
~~~

Nice, no repeated code!

---

What happens if we change `i<4`{.cpp} above for `i<5`{.cpp}?

~~~{.cpp .hidden layout="01-simple.cc"}
int i = 0;
while (i<4) {
  std::cout << i << " ";
  i = i + 1;
}
std::cout << std::endl;
~~~

= = =

Well, now we can see five numbers:

~~~output
~~~

---

What is the output of:

~~~{.cpp layout="01-simple.cc"}
int i = 1;
while (i<4) {
  std::cout << i << " ";
  i = i + 1;
}
std::cout << std::endl;
~~~

= = =

The output is:

~~~output
~~~

---

What is the output of:

~~~{.cpp layout="01-simple.cc"}
int i = -2;
while (i<4) {
  std::cout << i*2 << std::endl;
  i = i + 1;
}
~~~

= = =

The output is:

~~~output
~~~

---

Something a little more elaborated:

~~~{.cpp layout="01-simple.cc"}
int i = -2;
while (i<3) {
  std::cout << i << " squared is: " << i*i
            << std::endl;
  i = i + 1;
}
~~~

= = =

The output is:

~~~output
~~~

But I'm getting bored with all those `i = i + 1`{.cpp}, fortunatelly that operation is so
common in day to day work that it can be written shorter: `i++`{.cpp}.

---

What is the output of:

~~~{.cpp layout="01-simple.cc"}
int i = -6;
while (i<=-2) {
  std::cout << i << " squared is: " << i*i
            << std::endl;
  i++;
}
~~~

= = =

~~~output
~~~

---

\inlinetodo{add exercises using \texttt{while}}

---

What is happenning here?

~~~{.cpp layout="01-simple.cc"}
int a = 13;
int b = 6;
int c = 8;
while (b<a && b<c) {
  std::cout << "Both conditions met"
            << std::endl;
  b++;
}
~~~

= = =

~~~output
~~~

---

And here?

~~~{.cpp layout="01-simple.cc"}
int a = 13;
int b = 6;
int c = 8;
while (b<a || b<c) {
  std::cout << "At least one condition met"
            << std::endl;
  b++;
}
~~~

= = =

~~~output
~~~

Well, `&&`{.cpp} is called the **and** operator, and `||`{.cpp} is called the **or**
operator, they operate on `bool`{.cpp}s only.[^notreallbool]

[^notreallbool]: Well, they can actually operate in any number, any number not zero is
  treated as `true`{.cpp} otherwise `false`{.cpp}. This means that `a && b` is a
  valid statement above, but it is a weird one, its result is `true`{.cpp}. Such
  expressions, even though totally legal, are discouraged.

---

What is the output of:

~~~{.cpp layout="01-simple.cc"}
bool a = 5 > 2;
bool b = true;
if (a==b) {
  std::cout << "5 > 2 is equal to true"
            << std::endl;
} else {
  std::cout << "bananas!" << std::endl;
}
~~~

= = =

~~~output
~~~

As usual.

---

What is the output of:

~~~{.cpp layout="01-simple.cc"}
if ((5>2)==true) {
  std::cout << "5 > 2 is equal to true"
            << std::endl;
} else {
  std::cout << "bananas!" << std::endl;
}
~~~

= = =

It's basically the same thing from above, isn't it.

~~~output
~~~

---

We have printed only `int`{.cpp}s and `double`{.cpp}s to date, what would be the result of
printing `bool`{.cpp}s?

~~~{.cpp layout="01-simple.cc"}
std::cout << "true gets printed as " << true
          << std::endl;
std::cout << "But false gets printed as "
          << false << std::endl;
~~~

= = =

~~~output
~~~

Yep, `true`{.cpp} is represented as `1` always![^moreontrue]

[^moreontrue]:this is standard behaivor, because comparing `true` with `1` will result in
  `true` again, but it won't if you compare it to `3` even though `3` is treated as true
  if you use it in an `if` expression.

  Moral of the fable: don't use boolean operations on variables that are not boolean! and
  don't use non-boolean operations on boolean variables!

---

Let's take a look at the _truth table_ for `&&`{.cpp}:[^parenthesismandatory]

~~~{.cpp layout="01-simple.cc"}
std::cout
  << "1 && 1 == " << (true  && true)
  << std::endl
  << "1 && 0 == " << (true  && false)
  << std::endl
  << "0 && 1 == " << (false && true)
  << std::endl
  << "0 && 0 == " << (false && false)
  << std::endl;
~~~

[^parenthesismandatory]: the parenthesis around the boolean expressions are necessary,
  otherwise they would get confused with `<<`.

= = =

~~~output
~~~

---

And the _truth table_ for `!`{.cpp} (not, negation):

~~~{.cpp layout="01-simple.cc"}
std::cout
  << "!1 == " << !true  << std::endl
  << "!0 == " << !false << std::endl;
~~~

= = =

~~~output
~~~

All tables as you know them from logic, old stuff (actually, not that old, this tables
were first used as tables in the 20th century, but they are so intuitive that one may
think they're an older invention [^morehistory]).

[^morehistory]: for some more history see wikipedia article _Truth table_.

---

Now, what should be changed in the code above (for `&&`{.cpp}) to make the _truth table_
for `||`{.cpp}. The output of the table should be:

~~~output
~~~

= = =

And here is the code:

~~~{.cpp layout="01-simple.cc"}
std::cout
  << "1 || 1 == " << (true  || true)
  << std::endl
  << "1 || 0 == " << (true  || false)
  << std::endl
  << "0 || 1 == " << (false || true)
  << std::endl
  << "0 || 0 == " << (false || false)
  << std::endl;
~~~

---

What should be the value of `c` in the code below for the code to output `0 1 2 3 4`?

~~~cpp
int b = 10;
int c = ???;
int i = 0;

while ((i<b) && (i<c)) {
  std::cout << i << " ";
  i++;
}
std::cout << std::endl;
~~~

= = =

~~~{.cpp .hidden layout="01-simple.cc"}
int b = 10;
int c = 5;
int i = 0;

while ((i<b) && (i<c)) {
  std::cout << i << " ";
  i++;
}
std::cout << std::endl;
~~~

Precisely, it should be `5`{.cpp}. Let's take a look at the code running line by line:

1. We declare and initialize the variables `b`, `c` and `i` with the values `10`, `5` and `0` respectively.
2. We ask, is `i` content smaller than `b`?, and is `i` content smaller than `c`?, and both are truth ($0<10$ and $0<5$).
2. We print in the screen the value of `i` ($0$)
2. We increment the value of the variable `i`
2. We ask, is `i` content smaller than `b`?, and is `i` content smaller than `c`?, and both are truth ($1<10$ and $1<5$).
2. We print in the screen the value of `i` ($1$)
2. We increment the value of the variable `i`
2. We ask, is `i` content smaller than `b`?, and is `i` content smaller than `c`?, and both are truth ($2<10$ and $2<5$).
2. We print in the screen the value of `i` ($2$)
2. We increment the value of the variable `i`
2. We ask, is `i` content smaller than `b`?, and is `i` content smaller than `c`?, and both are truth ($4<10$ and $3<5$).
2. We print in the screen the value of `i` ($3$)
2. We increment the value of the variable `i`
2. We ask, is `i` content smaller than `b`?, and is `i` content smaller than `c`?, and both are truth ($4<10$ and $4<5$).
2. We print in the screen the value of `i` ($4$)
2. We increment the value of the variable `i`
2. We ask, is `i` content smaller than `b`?, and is `i` content smaller than `c`?, one is false ($5<10$ and $5<5$).
2. We get out of the while loop and go to the next line, thus we print at last a newline.

---

Describe line by line what the following code does (and its output):

~~~{.cpp layout="01-simple.cc"}
int b = 10;
int c = 5;
int i = 0;

while ((i<b) && (2*i<c)) {
  std::cout << i << " ";
  i++;
}
std::cout << std::endl;
~~~

= = =

The steps are:

1. We declare and initialize three `int`{.cpp} variables (`b`, `c` and `i` with `10`, `7` and `0` respectively).
2. We ask, is `i` content smaller than `b`?, and is `2*i` content smaller than `c`?, and both are truth ($0<10$ and $0<5$).
2. We print in the screen the value of `i` ($0$)
2. We increment the value of the variable `i`
2. We ask, is `i` content smaller than `b`?, and is `2*i` content smaller than `c`?, and both are truth ($1<10$ and $2<5$).
2. We print in the screen the value of `i` ($1$)
2. We increment the value of the variable `i`
2. We ask, is `i` content smaller than `b`?, and is `2*i` content smaller than `c`?, and both are truth ($2<10$ and $4<5$).
2. We print in the screen the value of `i` ($2$)
2. We increment the value of the variable `i`
2. We ask, is `i` content smaller than `b`?, and is `2*i` content smaller than `c`?, and one is false ($3<10$ and $6<5$).
2. We get out of the while loop and go to the next line, thus we print at last a newline.

The complete output is:

~~~output
~~~

---

What is the output of:

~~~{.cpp .norun layout="01-simple.cc"}
int imzero = 0;

while (imzero < 4) {
  std::cout << imzero << " ";
}
std::cout << std::endl;
~~~

= = =

The output is...:

~~~
0 0 0 0 0 0 0 0 0 0 0 0 0 ...
~~~

an unending sequence of zeros, so, what is wrong?

We forgot to add the statement `imzero++`{.cpp}! Without it, well, the variable `imzero`
never changes its state/value, and we ask _ad infinitum_ if zero is smaller than
four. ^[I actually wrote faulty code like that several times in the writing of this book
XD]

---

What should be the value of `c` in the code below for the code to output `0 2 4 6 8`?

~~~cpp
int b = 7;
int c = ???;
int i = 0;

while ((i<b) || (i+1<c)) {
  std::cout << i << " ";
  i++;
  i++;
}
std::cout << std::endl;
~~~

= = =

Yep, either `c` should be either `10` or `11`.

~~~{.cpp .hidden layout="01-simple.cc"}
int b = 7;
int c = 10; // it works with 11 too
int i = 0;

while ((i<b) || (i+1<c)) {
  std::cout << i << " ";
  i++;
  i++;
}
std::cout << std::endl;
~~~

---

What is the output of:

~~~{.cpp .hidden layout="01-simple.cc"}
std::cout << "3%2 == " << (3%2) << std::endl;
std::cout << "4%2 == " << (4%2) << std::endl;
std::cout << "0%2 == " << (0%2) << std::endl;
std::cout << "7%2 == " << (7%2) << std::endl;
std::cout << "2%2 == " << (2%2) << std::endl;
~~~

= = =

The output is:

~~~output
~~~

Notice how the odd numbers all return `1`, and all even numbers return `0`. Why?

---

What is the output:

~~~{.cpp layout="01-simple.cc"}
int a = 0;
while (a<=10) {
  if (a%2 == 0) {
    std::cout << a << " ";
  }
  a++;
}
std::cout << std::endl;
~~~

= = =

The output is:

~~~output
~~~

Cool, we can skip things while we count up (or down), like --in this case-- odd numbers.

---

What is the output of:

~~~{.cpp layout="01-simple.cc"}
int a = 0;
int b = 0;
while (a<=10) {
  if (a%2 == 0) {
    b = b + a;
  }
  std::cout << b << " ";
  a++;
}
std::cout << std::endl;
~~~

= = =

The output is:

~~~output
~~~

---

What should we change in the code above to print only one time each number, i.e.,
what lines are needed to change or be moved (from the code above) to output:

~~~output
~~~

?

= = =

Yep, we move the printing statement (line) to inside the true branch of the `if`
statement:

~~~{.cpp layout="01-simple.cc"}
int a = 0;
int b = 0;
while (a<=10) {
  if (a%2 == 0) {
    b = b + a;
    std::cout << b << " ";
  }
  a++;
}
std::cout << std::endl;
~~~

---

Say now, we want something simple, like knowing what is $1+2+3+ \cdots +10$ equal to.
There are many ways to do this, for example:[^manyways]

[^manyways]: we may calculate it using the equation $\frac{10+11}{2}$, thus we could write
  `int sum = (10+11)/2`{.cpp}, but we are going to ignore that and try to use what we've
  been discussing to date to solve this problem.

~~~.cpp
int sum = 1+2+3+4+5+6+7+8+9+10;
std::cout << "1+2+3+...+10 == " << sum
          << std::endl;
~~~

But, could there be a way to do the same using a `while`{.cpp} loop?

= = =

Yep, there is, for example:

~~~{.cpp layout="01-simple.cc"}
int sum = 0;
int i = 1;
while (i<=10) {
  sum = sum + i;
  i++;
}
std::cout << "1+2+3+...+10 == " << sum
          << std::endl;
~~~

Notice how this way of writing $1+2+ \cdots +10$ allows us to sum up to any number not only 10!
This little piece of code is very similar at what we do in maths when we write
$\sum_{i=1}^{i=10}{i}$ instead of $1+2+ \cdots +10$.

---

And what if we wanted to calculate

$$\sum_{i=1}^{i=10}{i^2} = 1^2+2^2+ \cdots +10^2$$

What should we change from the code above?

= = =

Well, that's right, `sum = sum + i` changes for `sum = sum + i*i`.

The full code and its output:

~~~{.cpp layout="01-simple.cc"}
int sum = 0;
int i = 1;
while (i<=10) {
  sum = sum + i*i;
  i++;
}
std::cout << "1^2 + 2^2 + 3^2 + ... + 10^2 == "
          << sum << std::endl;
~~~

~~~output
~~~

---

**Exercise for home:**

All the multiples of 3 or 5 smaller than 20 are 0, 3, 5, 6, 9, 10, 12, 15 and 18, and
their sum is $78$.
^[exercise extracted from project euler (<https://projecteuler.net> exercise 1)]

What is the sum of all natural numbers smaller than 1000 which are multiples of 3 or 5.

---

Writing code is often annoying because you can get errors that you didn't expect. The
following code supposedly should print on the screen the numbers from 10 to 1, top-bottom.
What is wrong with the code?

~~~cpp
int i = 10;
while (i<=1) {
  std::cout << i << " ";
  i--;
}
std::cout << std::endl;
~~~

= = =

Precisely, the condition `i<=1`{.cpp} is never met, all we need to do is to change
"smaller than" for "larger than", i.e., change the condition for `i>=1`{.cpp}.

~~~{.cpp .hidden layout="01-simple.cc"}
int i = 10;
while (i>=1) {
  std::cout << i << " ";
  i--;
}
std::cout << std::endl;
~~~

---

Robert has written a weird piece of code, it has two loops! What is it doing? What is the
output of the code below?

~~~{.cpp layout="01-simple.cc"}
int i = 0;
while (i<=10) {
  int j = 0;
  while (j<=20) {
    std::cout << "*";
    j++;
  }
  std::cout << std::endl;
  i++;
}
~~~

= = =

Nice, it runs 10 times the same code, a code that prints twenty asterisks.

~~~output
~~~

---

But I'm getting bored of writing so much code with the `while`{.cpp} loop. In fact, the
pattern whe have been using with while is so common that there is a shorter version of it,
the `for`{.cpp}. Let's see if you can guess what the following code does:

~~~{.cpp layout="01-simple.cc"}
for (int i=0; i<=10; i++) {
  for (int j=0; j<=20; j++) {
    std::cout << "*";
  }
  std::cout << std::endl;
}
~~~

= = =

~~~output
~~~

It does the same as the previous code![^itdoesbutisnot]

[^itdoesbutisnot]: It does the same, but the two pieces of code are semantically different
  if we put them in a different context, like inside a block of code which has already a
    variable named `i` in it.

A `for`{.cpp} loop is syntactic sugar[^syntacticsugar] for a `while`{.cpp} loop, it makes
convenienent and more explicit that we want to iterate over a value.

[^syntacticsugar]: This word will appear many times here onward, and it means, roughly: a
  way to write something in a simpler way. Similar to how we write LOL or WTF, and not
  "that made me laught so hard, man" or "seriously, that's weird as heck!".

A `for`{.cpp} loop has four different parts:

~~~cpp
for (A; B; C) {
  D;
}
~~~

and it's equivalent to the following `while`{.cpp} loop.

~~~cpp
{
  A;
  while (B) {
    D;
    C;
  }
}
~~~

---

Write the following `while`{.cpp} loop as `for`{.cpp} loop.

~~~{.cpp layout="01-simple.cc"}
int top = 10;
int i = 0;
while (i<top) {
  std::cout << i * top + 1 << " ";
  i++;
}
std::cout << std::endl;
~~~

= = =

Feels good, isn't it? Simple exercises for a while.

~~~cpp
int top = 10;
for (int i=0; i<top; i++) {
  std::cout << i * top + 1 << " ";
}
std::cout << std::endl;
~~~

---

What is the output of the following code:

~~~{.cpp layout="01-simple.cc"}
for (int i=0; i<18; i++) {
  if ((i%3!=0) && (i%7!=0)) {
    std::cout << i << " ";
  } else {
    std::cout << ". ";
  }
}
std::cout << std::endl;
~~~

= = =

The output is:

~~~output
~~~

Numbers multiple of 3 or 7 are printed as dots (`.`), while all others are printed as
themselves.

---

**Exercise for home:**

The fibonacci sequence is a sequence defined by:

$$ fib(x) =
  \begin{cases}
    0                  & \quad \text{if } n = 0 \\
    1                  & \quad \text{if } n = 1 \\
    fib(x-1)+fib(x-2)  & \quad \text{if } n > 1
  \end{cases} $$

Which gives us the sequence $0,1,1,2,3,5,8,13,21,34,55,...$. Notice how every number in
the sequence (except the first two) is equal to the sum to both its predecesors.

Write a program that prints on the screen the first 20 fibonacci numbers using loops
(either `while`{.cpp} or `for`{.cpp} loops).

<!--
   -Note: this exercise is one of the things that I remember the most from 7 years ago. The
   -professor left us this as an exercise for home (or we couldn't do it in class, I don't
   -remember) and I went out of class wondering how to solve it, I stopped in the middle of
   -my walk back to the bus way home and sat down to write the idea I had in mind, it took me
   -a long time to write, but I was so damn proud of myself when I solved the puzzle, so much
   -that to this date I still remember that day (I hope that it is true anyway, the memory
   -could have changed so much over the course of all these years, but anyway it's an
   -encouraging tale I have from that time that I think I should try to make others brains
   -explode in the same way mine did)
   -->

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

\inlinetodo{add 6 more exercises with returns of many classes, mainly used to make
computation simpler, like making complex computations and returning values.}

---

<!-- vim:set filetype=markdown.pandoc : -->
