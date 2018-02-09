## What if's ##

\inlinetodo{explain what is a keyword, and why some exercises may fail}

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

**Task for home:** Write a program that outputs the steps to follow to make a healthy
breakfast if there are multiple options for breakfast. You should be able to select your
option for breakfast by setting a variable to one of many values (as many as you like).

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

<!-- vim:set filetype=markdown.pandoc : -->
