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

The successor function is the function that returns the natural number that follows any
natural number we give it, i.e., the successor function is $succ(x) = x+1$ where $x$ is a
natural number.

Can you right this function in C++?

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

One possibility is writing:

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
different, this is because their scope its different, **everytime we call a function it
creates a new scope!**

---

As you can see, what we are doing is to answer a question of how much is 1 plus 3, and we
are giving a question as an answer, well that is 2 plus 2. We are solving problems by
reframing them.

How does it work? How is it possible to answer a question with another question?

Well, the trick is ...

= = =

that the answer is not any question, it is a question that tries to simplify our problem,
or it tries to change it in a way that there is a very simple way to solve it. In special
a function that calls itself to solve a problem is named **recursive** and it has two
important parts:

- **Base case**: A base rule that determines the answer to the simplest case (above this
  would be $n + 0 = n$, the sum of any number with zero is the same number)
- **Recursive case**: A rule that simplifies the problem but answers it with the same
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

Can you think on other ways to write it?, for example, using only an `if` statement.

---

**Task for home**: Write a recursive function that adds the numbers from $1$ to $10$
without using any `for` or `while` loop.

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

What is the trace of running `fact(4)`?

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

Again, we can write `fact(5)` more compactly:

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

How does `fib(4)` look in this notation?

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

\inlinetodo{at least 4 tasks for home more on recursive functions!}

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
