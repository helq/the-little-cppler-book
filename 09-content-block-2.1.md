# Block 2: Going further with functions and more space to play with #

<!--
   -2. recursive functions, input, pass by reference, arrays, and string operations
   -  * introduce the magic of recursive functions
   -  * show how variables passed as value don't change while passed by reference do
   -  * introduce arrays
   -  * show how arrays behave differently from any other value, and how they appear to be
   -    always pass by reference and not by value
   -  * arrays have many gotchas, like asking for a value outside the range of the array
   -  * possible exercises: copy content of an array from one to the other
   -  * (optional) tell them that many people, professionaly, don't like arrays and use
   -    better the standard libraries, which have a lot of functions for common things we
   -    have done already. Like, copying an array, printing it on the screen, ...
   -
   -  maybe:
   -  * show examples of input from the user (nahh..)
   -  * show things to get wrong with input from the user (from wrong type to unexpected
   -    stuff from spaces, tabs and newlines)
   -->

## Answering with a question ##

---

The successor function is the function that returns the natural number that follows any
natural number we give it, i.e., the successor function is $succ(x) = x+1$ where $x$ is a
natural number.

Can you write this function in C++?

= = =

Of course, and it's:

~~~cpp
int succ(int x) {
  return x+1;
}
~~~

---

What is the output of:

~~~{.cpp layout="00-empty.cc"}
#include <iostream>

int succ(int x) {
  return x + 1;
}

int main() {
  std::cout << succ(0)
     << " " << succ(succ(0))
     << " " << succ(0)
     << " " << succ(succ(succ(0)))
     << " " << succ(succ(succ(succ(0))))
     << std::endl;
  return 0;
}
~~~

= = =

Not very surprisingly:

~~~output
~~~

---

In maths we define addition (`+`) on natural numbers in the following way:[^peano]

1. We define there is a $0 \in \mathbb{N}$
2. We define that every natural number has a successor:
  $n \in \mathbb{N} \rightarrow (n+1) \in \mathbb{N}$
3. We define how to add two numbers
  $$add(a, b) =
  \begin{cases}
    a               & \quad \text{if } b = 0\\
    succ(add(a, c)) & \quad b = succ(c)
  \end{cases}$$

[^peano]: This method to define natural numbers is called "Peano Numbers", you can take a
  deeper look at them if you search in the wikipedia for "Peano axioms", highly
  recommended! It's a basic structure in maths and every mathematician knows it.

How would you write `add(a, b)` in C++?

= = =

One possibility is:

~~~cpp
int add(int x, int y) {
  if (y==0) {
    return x;
  } else {
    return succ( add(x, y-1) );
  }
}
~~~

Digression, this is NOT how the computer adds, but this is how in maths addition is
defined.

---

So, what is the output of:

~~~{.cpp layout="00-empty.cc"}
#include <iostream>

int succ(int x) {
  return x + 1;
}

int add(int x, int y) {
  if (y==0) {
    return x;
  } else {
    return succ( add(x, y-1) );
  }
}

int main() {
  std::cout << succ(0)
     << " " << succ(succ(0))
     << " " << add( succ(succ(0)), 0 )
     << " " << add( succ(0), succ(0) )
     << " " << add( 0, succ(succ(0)) )
     << " " << add( 0, succ(succ(0)) )
     << " " << succ( add( 0, 2 ) )
     << " " << add( 10, 2 )
     << " " << add( 3, 21 )
     << std::endl;
  return 0;
}
~~~

= = =

Yeah, well, it seems just wasteful, so many additions and succesions to print just a
couple of `2`s:

~~~output
~~~

---

What is happenning with `add(succ(0), succ(succ(0)))`{.cpp}? (step by step)

~~~{.cpp .hidden layout="00-empty.cc"}
#include <iostream>

int succ(int x) { return x + 1; }

int add(int x, int y) {
  if (y==0) { return x; }
  else      { return succ( add(x, y-1) ); }
}

int main() {
  std::cout
     << add( succ(0), succ(succ(0)) )
     << std::endl;
  return 0;
}
~~~

= = =

A step by step of the execution of `add(succ(0), succ(succ(0)))`{.cpp}:

1. Before any function is executed, all its arguments are computed, so to run `add` we
   need to run first `succ(0)` and `succ(succ(0))` which return us the values `1` and `2`,
   respectively.
2. We call `add` with the values `1` and `2`
3. Inside the call of `add` we ask if `y` is equal to zero. It isn't, therefore we execute
   `succ( add(x, y-1) )`{.cpp}.
4. Before we can call `succ( add(x, y-1) )`{.cpp}, we need to find the value of the
   argument that we want to pass to `succ`. This means, we compute `add(x, y-1)`, and to
   compute it we need first `y-1`.
5. We call now `add` with the values `1` and `1`.
6. Inside the call of `add` we ask if `y` is equal to zero. It isn't (`y==1`), therefore
   we call once more `succ` with argument `add(x, y-1)` (for which we require `y-1`).
7. Inside the call of `add` we ask if `y` is equal to zero. It IS, finally, and we decide
   to return the value of `x`.
8. Now, we come back to the last call of the `add` function, where we compute the `succ`
   of `1`, which is `2`. And return the value to the last call.
9. We get back to the place where `add` was called, we apply the `succ` function and
   return its final value `3`.

---

A simpler way to represent what is happenening step by step when we call a function is to
write each instruction executed line by line, a _trace_. So, the explanation above can be
written as:

~~~
   add(succ(0), succ(succ(0)))

=> add(1, succ(succ(0)))
  (x=0)=> return x+1
  (x=0)=> return 0+1
  (x=0)=> return 1
=> add(1, succ(1))
  (x=1)=> return x+1
  (x=1)=> return 1+1
  (x=1)=> return 2
=> add(1, 2)
  (x=1, y=2)=> if (y==0) { return x; } else { return succ( add(x, y-1) ); }
  (x=1, y=2)=> return succ( add(x, y-1) )
  (x=1, y=2)=> return succ( add(1, 1) )
    (x=1, y=1)=> if (y==0) { return x; } else { return succ( add(x, y-1) ); }
    (x=1, y=1)=> return succ( add(x, y-1) )
    (x=1, y=1)=> return succ( add(1, 0) )
      (x=1, y=0)=> if (y==0) { return x; } else { return succ( add(x, y-1) ); }
      (x=1, y=0)=> return x
      (x=1, y=0)=> return 1
    (x=1, y=1)=> return succ( 1 )
      (x=1)=> return x+1
      (x=1)=> return 1+1
      (x=1)=> return 2
    (x=1, y=1)=> return 2
  (x=1, y=2)=> return succ( 2 )
    (x=2)=> return x+1
    (x=2)=> return 2+1
    (x=2)=> return 3
  (x=1, y=2)=> return 3
=> 3
~~~

Notice, how each time we call the function the values of the variables `x` and `y` are
different, this is because their scope its different. **Everytime we call a function it
creates a new scope!**

---

As you can see, what we are doing is to answer a question with another question. We ask,
"how much is 1 plus 3," and we answer, "the successor of 1 plus 2". We are solving
problems by reframing them, by asking the same problem from a different angle.

But, how does it work? How is it possible to answer a question with another question?

Well, the trick is ...

= = =

that the answer is not any question, it is a special question, a simpler question. The
idea is to simplify our problem by asking something simpler.

A function that calls itself to solve a problem is named **recursive** and it's composed
of two important parts:

- **A base case**: A base rule that determines the answer to the simplest case (above this
  would be $n + 0 = n$, the sum of any number with zero is the same number)
- **A recursive case**: A rule that simplifies the problem but answers it with the same
  function (e.g., $n + (k+1) = (n + k) + 1$, the sum of two natural numbers is the same as
  the successor of the sum of the first number and the predecesor of the second).

---

Do you remember the definition of fibonacci?

= = =

Well, it's this:

$$ fib(x) =
  \begin{cases}
    0                  & \quad \text{if } x = 0 \\
    1                  & \quad \text{if } x = 1 \\
    fib(x-1)+fib(x-2)  & \quad \text{if } x > 1
  \end{cases} $$

---

Now, translate the fibonacci function into C++ code.

= = =

One possible C++ version is:

<!--Yes, there is a mistake in this code but I'll keep it because I've noticed that not
many students notice the mistake and many write down the same code in the quiz, which
would mean they are just copy/pasting the solutions and they are not really thinking.
Also, hello if any of you happen to be reading this XD-->

~~~cpp
int fib(int x) {
  if (x==0) {
    return 0;
  } else if (x==1) {
    return 1;
  } else {
    return fib(x-1) + (x-2);
  }
}
~~~

Challenge: Can you think on other ways to write fibonacci's formula? using only an `if`
statement?

---

A recursive function is always defined by two equations: the **base case** and the
**recursive case**.

When translating the cases into C++ we always get the structure (if the function takes
and returns integer values):

~~~cpp
int recursive_f(int x, int y) {
  if ( /* Base case */ ) {
    return /* base case result */;

  } else { // Recursive case
    return /* call to 'recursive_f' */;
  }
}
~~~

How is the following function coded into C++ using a recursive function:

$$ fact(x) =
  \begin{cases}
    1            & \quad \text{if } x \leq 1 \\
    x*fact(x-1)  & \quad \text{otherwise}
  \end{cases} $$

= = =

Well, the function is the factorial of a number, often written in math as $n! = 1 \cdot 2
\cdot 3 \cdots n$.

And the code is:

~~~cpp
int fact(int x) {
  if (x<=1) {
    return 1;
  } else {
    return x * fact(x-1);
  }
}
~~~

---

What is the trace of running `fact(4)`?^[same as to say, what is the trace of evaluating
the function (in this case only)]

= = =

~~~
fact(4)

  (x=4)=> if (x<=1) { return 1; }
          else { return x*fact(x-1); }
  (x=4)=> return x*fact(x-1);
  (x=4)=> return 4*fact(3);
    (x=3)=> if (x<=1) { return 1; }
            else { return x*fact(x-1); }
    (x=3)=> return x*fact(x-1);
    (x=3)=> return 3*fact(2);
      (x=2)=> if (x<=1) { return 1; }
              else { return x*fact(x-1); }
      (x=2)=> return x*fact(x-1);
      (x=2)=> return 2*fact(1);
        (x=1)=> if (x<=1) { return 1; }
                else { return x*fact(x-1); }
        (x=1)=> return 1;
      (x=2)=> return 2*1;
      (x=2)=> return 2;
    (x=3)=> return 3*2;
    (x=3)=> return 6;
  (x=4)=> return 4*6;
  (x=4)=> return 24;
=> 24
~~~

---

We can write the evaluation of `fact(5)` more compactly:

\begin{align*}
  fact(5) &= 5 \cdot fact(4) \\
          &= 5 \cdot (4 \cdot fact(3)) \\
          &= 5 \cdot (4 \cdot (3 \cdot fact(2))) \\
          &= 5 \cdot (4 \cdot (3 \cdot (2 \cdot fact(1)))) \\
          &= 5 \cdot (4 \cdot (3 \cdot (2 \cdot 1))) \\
          &= 5 \cdot (4 \cdot (3 \cdot 2)) \\
          &= 5 \cdot (4 \cdot 6) \\
          &= 5 \cdot 24 \\
          &= 120
\end{align*}

How does the evaluation of `fib(4)` looks?

= = =

\begin{align*}
  fib(4) &= fib(3) + fib(2) \\
         &= (fib(2) + fib(1)) + fib(2) \\
         &= ((fib(1) + fib(0)) + fib(1)) + fib(2) \\
         &= ((1 + fib(0)) + fib(1)) + fib(2) \\
         &= ((1 + 0) + fib(1)) + fib(2) \\
         &= (1 + fib(1)) + fib(2) \\
         &= (1 + 1) + fib(2) \\
         &= 2 + fib(2) \\
         &= 2 + (fib(1) + fib(0)) \\
         &= 2 + (1 + fib(0)) \\
         &= 2 + (1 + 0) \\
         &= 2 + 1 \\
         &= 3
\end{align*}

---

Recursive functions are very powerful. They are as powerful as loops (`for` and `while`)
to iterate over a series of numbers.

Take a look at the following function:

~~~{.cpp layout="01-simple.cc"}
void huh(int i, int n) {
  if(i>=n) {
    std::cout << "This is the end: " << n
              << std::endl;
  } else {
    std::cout << i << std::endl;
    huh(i+1, n);
  }
}
...
huh(4, 10);
~~~

What do you think it does when run with `huh(4, 10)`{.cpp}?

= = =

Yeah, it acts precisely as a `for` loop!

~~~output
~~~

In fact, we can rewrite the function to work with a `for` loop and not recursion:

~~~cpp
void huh(int i, int n) {
  for(int j=i; j<=n; j++) {
    std::cout << i << std::endl;
  }
  std::cout << "This is the end: " << n
            << std::endl;
}
...
huh(4, 10);
~~~

---

**Task for home**: Write a recursive function that adds the numbers from $1$ to $10$
without using any `for` or `while` loop.

---

<!--
   -Why would we want to use recursion if it is equally powerful to loops? Well, there are
   -situations in which recursion is more desirable. They are particularly useful when
   -operating in data structures different from simple lists, for examples, trees. Let's print
   -a tree!
   -
   -~~~{.cpp layout="01-simple.cc"}
   -#include <cmath>
   -
   -void branches(int i, int spaces, int depth) {
   -  if(i<pow(2, depth)) {
   -    std::cout << depth;
   -    for (int j = 0; j < spaces; j++) {
   -      std::cout << " ";
   -    }
   -    branches(i+1, spaces, depth);
   -  }
   -}
   -
   -void tree(int spacesbefore, int depth) {
   -  if(depth>=0) {
   -    for(int j=0; j<spacesbefore; j++) {
   -      std::cout << " ";
   -    }
   -    branches(0, 2*spacesbefore+1, depth);
   -    std::cout << std::endl;
   -    tree(2*spacesbefore+1, depth-1);
   -  }
   -}
   -...
   -tree(0, 4);
   -~~~
   -
   -\inlinetodo{better to do this using ncurses, there will the power of recursion really show}
   -
   -Can you guess the output?
   -
   -= = =
   -
   -The output of the program:
   -
   -~~~output
   -~~~
   -
   ----
   -
   -**Task for home:** Modify the function `tree` (see above) to print the tree like this:
   -
   -~~~
   -4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4
   -\ / \ / \ / \ / \ / \ / \ / \ /
   - 3   3   3   3   3   3   3   3
   - \   /   \   /   \   /   \   /
   -  \ /     \ /     \ /     \ /
   -   2       2       2       2
   -   \       /       \       /
   -    \     /         \     /
   -     \   /           \   /
   -      \ /             \ /
   -       1               1
   -       \               /
   -        \             /
   -         \           /
   -          \         /
   -           \       /
   -            \     /
   -             \   /
   -              \ /
   -               0
   -~~~
-->

---

What does the following function outputs:

~~~{.cpp layout="00-empty.cc"}
#include <iostream>

void print_i2n_squared(int i, int n) {
  if(i<=n) {
    std::cout << i*i << " ";
    print_i2n_squared(i+1, n);
  } else {
    std::cout << std::endl;
  }
}

int main() {
  print_i2n_squared(3, 5);
  print_i2n_squared(12, 21);
  return 0;
}
~~~

= = =

The output is:

~~~output
~~~

---

Write the function from the last example (`print_i2n_squared`) using a `for` loop and not
recursion

= = =

~~~{.cpp layout="00-empty.cc"}
#include <iostream>

void print_i2n_squared(int start, int n) {
  for(int i=start; i<=n; i++) {
    std::cout << i*i << " ";
  }
  std::cout << std::endl;
}

int main() {
  print_i2n_squared(3, 5);
  print_i2n_squared(12, 21);
  return 0;
}
~~~

---

So, there seems to be a pattern. Look at the two pieces of code in the last two examples.
Are they gonna do the same for every input `i` and `n`?

Can you write down the rules on how to convert a function like `print_i2n_squared` from a
`for` loop to a recursive function?

= = =

Yes, they behave almost in the same way. Thought, depending on the compiler you're using
and the options you've set it on, the recursive function may not work properly always.

And what are the rules, or the scheme, to translate from one to the other, well:

As a recursive function:

~~~cpp
void f_rec(VARS) {
  if(ASSERTION) {
    MAIN ROUTINE
    f_rec(VARS on next step);
  } else {
    END ROUTINE
  }
}
~~~

And as a for or while loop:

~~~cpp
void f_loop(VARS) {
  for( init vars; ASSERTION; VARS on next step)
    MAIN ROUTINE
  }
  END ROUTINE
}
~~~

Where `init vars` initialises the variables we are going to use inside the loop.

---

But some functions do return something (i.e., their type is not `void` but `int`,
`double`, ...). For example:

~~~cpp
int sum_i2n(int i, int n) {
  if(i<=n) {
    return i + sum_i2n(i+1, n);
  } else {
    return 0;
  }
}
~~~

What is this function doing? What is the output of:

~~~cpp
int main() {
  std::cout << sum_i2n(1,10) << std::endl;
  std::cout << sum_i2n(1,10)*3 << std::endl;
  return 0;
}
~~~

~~~{.cpp .hidden layout="00-empty.cc"}
#include <iostream>

int sum_i2n(int i, int n) {
  if(i<=n) {
    return i + sum_i2n(i+1, n);
  } else {
    return 0;
  }
}

int main() {
  std::cout << sum_i2n(1,10) << std::endl;
  std::cout << sum_i2n(1,10)*3 << std::endl;
  return 0;
}
~~~

= = =

Well, the function is adding all numbers from `i` to `n` (inclusively). The output is:

~~~output
~~~

---

Now, write the function above using a `for` loop and not recursion.

= = =

~~~cpp
int sum_i2n(int i, int n) {
  int sum = 0;
  for(int j=i; j<=n; j++) {
    sum += i;
  }
  return sum;
}
~~~

---

These kind of recursive functions (which return something rather than `void`) have a
similar pattern to convert them from and to `for` (or `while`) loops.

What are the rules, or scheme, to translate from a `for` loop to a recursive function.

= = =

Given a "`for` loop" function:

~~~cpp
TYPE f_loop(VARS) {
  TYPE result = BASE_VALUE;
  for(init vars; ASSERTION; VARS on next step) {
    result = OPERATE( result, VARS );
  }
  return result;
}
~~~

Where operate may be one simple operation like `+` (or `*`), or it may be a more complex
operation.

We can write the "equivalent"^[dependend on the compiler and optimizations] recursive
function:

~~~cpp
TYPE f_rec(VARS) {
  if( ASSERTION ) {
    return OPERATE( result, VARS on next step );
  } else {
    return BASE_VALUE;
  }
}
~~~

---

**Task for home:** Write a recursive function that returns the number its given inverted.
For example, if we call `reversed(23464)` it should return `46432`.

Take the following code as template:

~~~cpp
#include <iostream>

int reversed(int n) {
  // Your code should go here
  return 0;
}

int main() {
  std::cout << 1234 << " reversed is " << reversed(1234) << std::endl;
  std::cout << 643 << " reversed times two is " << 2*reversed(643) << std::endl;
  return 0;
}
~~~

with output:

~~~
1234 reversed is 4321
643 reversed times two is 692
~~~

---

Sometimes, it's easier to write a recursive function with an additional parameter
(variable) which it's gonna hold the result of the recursive operation. For example, what
does the following function do if it is called with the parameters `arecfun(1, 10, 0)`?

~~~cpp
int arecfun(int i, int n, int acc) {
  if(i<=n) {
    return sum_i2n(i+1, n, acc+i);
  } else {
    return acc;
  }
}
~~~

= = =

Yep, this is precisely the same function we were playing with before. And it would return
when called with the parameters `(1, 10, 0)` the value `55`.

---

**Task for home:** Write a recursive function that prints on the screen the first `20`
numbers of the fibonacci sequence.

---

**Task for home:** Read, analyse (and execute) the following two equivalent functions:

Its `for` version.

~~~cpp
int sum_i2n(int i, int n) {
  int sum = 0;
  for(int j=i; j<=n; j++) {
    sum += i;
  }
  return sum;
}
~~~

and, its recursive version.

~~~cpp
int helper_f(int i, int n, int acc) {
  if(i<=n) {
    return sum_i2n(i+1, n, acc+i);
  } else {
    return acc;
  }
}

int sum_i2n(int i, int n) {
  return helper_f(i, n, 0);
}
~~~

Derive a set of rules, or a scheme, to convert a `for` loop-function into a recursive
function[^tailrecursive].

[^tailrecursive]: This kind of recursive functions is called "tail recursive functions",
  and can be usually be easily converted into `for` loops by the compiler, therefore, they
  are recommended over non-tail recursive function if they can be converted.

---

\newpage

<!-- vim:set filetype=markdown.pandoc : -->
