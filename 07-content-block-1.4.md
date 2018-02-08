## Syntactic sugar with `for` ##

---

What is the output of:

~~~{.cpp layout="01-simple.cc"}
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

What is the output of:

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

What should we change in the code above to print each number one time only?, i.e.,
what lines are needed to change or be moved (from the code above) to output this:

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

[^manyways]: we may calculate it using the equation $\frac{10*11}{2}$, thus we could write
  `int sum = (10*11)/2`{.cpp}, but we are going to ignore that and try to use what we've
  been discussing to date to solve this problem.

~~~.cpp
int sum = 1+2+3+4+5+6+7+8+9+10;
std::cout << "1+2+3+...+10 == " << sum
          << std::endl;
~~~

But, could we code it using a `while`{.cpp} loop?

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

\newpage

<!-- vim:set filetype=markdown.pandoc : -->
