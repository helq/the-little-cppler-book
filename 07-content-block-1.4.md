## Syntactic sugar with `for` ##

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

**Task for home**: Given a number, print it in reverse. For example, given the kick start
code:

~~~cpp
int mynum = 12367;

// Your code continues here
~~~

It should print in screen:

~~~
76321
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

**Task for home:**

All the multiples of 3 or 5 smaller than 20 are 0, 3, 5, 6, 9, 10, 12, 15 and 18, and
their sum is $78$.^[exercise extracted from project euler (<https://projecteuler.net>
exercise 1)]

What is the sum of all natural numbers smaller than 1000 which are multiples of 3 or 5?
Write some code using a `for` or `while` loop to solve the problem.

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

**Task for home:** Print the numbers from 1 to 9 in a diagonal, something like:

~~~
1
  2
    3
      4
        5
          6
            7
              8
                9
~~~

It is is easy to write:

~~~cpp
std::cout << "1"     << std::endl;
std::cout << "  2"   << std::endl;
std::cout << "    3" << std::endl;
~~~

The challenge is to use a `while`{.cpp} loop. Use a `while`{.cpp} loop to print the diagonal.

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

**Task for home:** Write the multiplication table for any number I give you, for example,
with some code like:

~~~cpp
int num = 3;

for (int i=0; i<=10; i++) {
  // your code goes here
}
~~~

I want you to output:

~~~
3 * 0 == 0
3 * 1 == 3
3 * 2 == 6
3 * 3 == 9
3 * 4 == 12
3 * 5 == 15
3 * 6 == 18
3 * 7 == 21
3 * 8 == 24
3 * 9 == 27
3 * 10 == 30
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

**Task for home:**

The fibonacci sequence is a sequence defined by:

$$ fib(x) =
  \begin{cases}
    0                  & \quad \text{if } n = 0 \\
    1                  & \quad \text{if } n = 1 \\
    fib(x-1)+fib(x-2)  & \quad \text{if } n > 1
  \end{cases} $$

Which gives us the sequence $0,1,1,2,3,5,8,13,21,34,55,...$. Notice how every number in
the sequence (except the first two) is equal to the sum of both its predecesors.

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

\newpage

<!-- vim:set filetype=markdown.pandoc : -->
