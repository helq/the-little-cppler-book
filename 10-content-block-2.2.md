## Grouping data together ##

---

Write the following function in C++:

$$\begin{aligned}
  sum\_squared : \, \mathbb{N} \times \mathbb{N} &\rightarrow \mathbb{N} \\
                (i,n) &\mapsto \sum_{j=i}^{n}{j^2}
\end{aligned}$$

= = =

~~~cpp
int sum_squared(int i, int n) {
  int result = 0;
  for(int j=i; j<=n; j++) {
    result += j*j;
  }
  return result;
}
~~~

---

And what if we wanted to write a C++ function with the following type:

$$\begin{aligned}
  twothings : \, \mathbb{N} \times \mathbb{N} &\rightarrow \mathbb{N} \\
                (i,n) &\mapsto \left(\sum_{j=i}^{n}{j^2}, \prod_{j=i}^{n}{j^2} \right)
\end{aligned}$$

= = =

Well, that's not possible right now. The only thing we may do is to write two functions
which each one computes a fraction of the output. Something like this:

$$\begin{aligned}
  twothings_1 : \, \mathbb{N} \times \mathbb{N} &\rightarrow \mathbb{N} \\
                (i,n) &\mapsto \sum_{j=i}^{n}{j^2} \\
  twothings_2 : \, \mathbb{N} \times \mathbb{N} &\rightarrow \mathbb{N} \\
                (i,n) &\mapsto \prod_{j=i}^{n}{j^2}
\end{aligned}$$

---

Diving a function like this into its two components is feasible sometimes, but not always,
take a look at the following function[^letin]:

[^letin]: **let in** lets us declare a variable (or many variables) to later use them in
  more computations, for example: **let** $x = 3+4$ **in** $y=x*20$ is the same as
  writing $y=(3+4)*20$.

$$\begin{aligned}
  fib : \, \mathbb{N} &\rightarrow \mathbb{N} \times \mathbb{N} \\
  i &\mapsto
  \begin{cases}
    (0, 1) & \quad \text{if } i \leq 0 \\
    \begin{matrix*}[l]
     \textbf{let } & (a,b) = fib(i-1) \\
     \textbf{in }  & (b, a+b)
    \end{matrix*}
    & \quad \text{otherwise}
  \end{cases}
\end{aligned}$$

What is the result of $fib(5)$?

= = =

Let's start with the smallest value ($0$), and go up till $5$:

$$fib(0) = (0, 1)$$

$$\begin{aligned}
  fib(1) &= \textbf{let } (a,b) = fib(0) \textbf{ in } (b,a+b) \\
         &= \textbf{let } (a,b) = (0, 1) \textbf{ in } (b,a+b) \\
         &= (1,0+1) \\
         &= (1,1) \\
  fib(2) &= \textbf{let } (a,b) = fib(1) \textbf{ in } (b,a+b) \\
         &= \textbf{let } (a,b) = (1, 1) \textbf{ in } (b,a+b) \\
         &= (1,1+1) \\
         &= (1,2) \\
  fib(3) &= \textbf{let } (a,b) = fib(2) \textbf{ in } (b,a+b) \\
         &= (2,3) \\
  fib(4) &= \textbf{let } (a,b) = fib(3) \textbf{ in } (b,a+b) \\
         &= (3,5) \\
  fib(5) &= \textbf{let } (a,b) = fib(4) \textbf{ in } (b,a+b) \\
         &= (5,8) \\
\end{aligned}$$

---

What do you think will the following code output?

~~~{.cpp layout="00-empty.cc"}
#include <iostream>

struct pair {
  int x;
  int y;
};

int main() {
  pair p;
  p.x = 12;
  p.y = 6;
  std::cout << p.x << " " << p.y << std::endl;
  return 0;
}
~~~

= = =

Well, nothing very surprising:

~~~output
~~~

A **_struct_** allows us to declare and manipulate several blocks of memory as in one.

---

We can access to each one of the individual parts of a variable declared as as _struct_
with help of the dot (**`.`**) operator.

Let's suppose that we define `pair` as:

~~~cpp
struct pair {
  int x;
  int y;
};
~~~

What is the output of the following code^[we're back inside in `main` for simplicity]:

~~~{.cpp layout="02-pair.cc"}
pair first;
pair second;

first.x = 12;
second.x = 45;
second.y = 3;
first.y = first.x * second.y;
second.y = 12;

std::cout << first.x << " "
          << first.y << std::endl
          << second.x << " "
          << second.x << std::endl;
~~~

= = =

~~~output
~~~

---

What is very neat about **struct**s is that we can use them as any other type we have
encountered to date. We can declare a `pair` which will reserve two spaces of memory `int`
on the fly. Even we can pass and get values of type `pair` to and from a function. For
example:

~~~{.cpp layout="02-pair.cc"}
pair fib(int i) {
  if(i<=0) {
    pair ret;
    ret.x = 0;
    ret.y = 1;
    return ret;
  } else {
    pair ret;
    pair ab = fib(i-1);
    ret.x = ab.y;
    ret.y = ab.x + ab.y;
    return ret;
  }
}
...
pair res;
res = fib(5);
std::cout << res.x << " "
          << res.y << std::endl;
~~~

What will be its output?

= = =

~~~output
~~~

Yeah, this is precisely the $fib$ function from above, we can now write functions with
outputs that are not only `int`, `double`, `char`, `bool`, ... :D

---

The function above doesn't look too nice, it's quite long and cumbersome to read. So, we
are going to apply some tricks to make it look nicer.

The first, is that we can in fact pass values directly to a `pair` when we declare it.
Similar to how we write:

~~~cpp
int a = 5;
~~~

and not:

~~~cpp
int a;
a = 5;
~~~

Even though they are the same.

We can write

~~~cpp
pair p = {1, 2};
~~~

as a shorthand to:

~~~cpp
pair p;
p.x = 1;
p.y = 2;
~~~

Rewrite the function above (`fib`) using this shorthand.

= = =

~~~{.cpp layout="02-pair.cc"}
pair fib(int i) {
  if(i<=0) {
    pair ret = {0, 1};
    return ret;
  } else {
    pair ab = fib(i-1);
    pair ret = { ab.y, ab.x + ab.y };
    return ret;
  }
}
...
pair res;
res = fib(5);
std::cout << res.x << " "
          << res.y << std::endl;
~~~

Wow, that looks much better.

---

Writing something like:

~~~cpp
pair ret = {0, 1};
return ret;
~~~

seems wasteful, why two lines for something like that. Fortunatelly, this is a common
enough case to have a short version.

~~~cpp
return pair{0, 1};
~~~

:D

Rewrite, again, the `fib` function from above to use this new simplification.

= = =

~~~{.cpp layout="02-pair.cc"}
pair fib(int i) {
  if(i<=0) {
    return pair{0, 1};
  } else {
    pair ab = fib(i-1);
    return pair{ ab.y, ab.x + ab.y };
  }
}
...
pair res;
res = fib(5);
std::cout << res.x << " "
          << res.y << std::endl;
~~~

Well, that is nice.

We could even go further, for example there is no need for brackets around a single
sentence, like inside the if branch, or `else` statement when there is a return in the
`if` statement, but that doesn't really matter, that would be too much trimming ;)

Here, this is how it would look like:

~~~cpp
pair fib(int i) {
  if(i<=0)
    return pair{0, 1};
  pair ab = fib(i-1);
  return pair{ ab.y, ab.x + ab.y };
}
~~~

---

**Task for home**: Write the function

$$\begin{aligned}
  twothings : \, \mathbb{N} \times \mathbb{N} &\rightarrow \mathbb{N} \\
                (i,n) &\mapsto \left( \sum_{j=i}^{n}{j^2}, \prod_{j=i}^{n}{j^2} \right)
\end{aligned}$$

using the struct `pair`. Take this as a template:

~~~cpp
pair twothings(int i, int n) {
  // your code in here
  return pair{0, 0};
}
~~~

---

\newpage

<!-- vim:set filetype=markdown.pandoc : -->
