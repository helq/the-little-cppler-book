## What if and if and if and ... ##

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

\newpage

<!-- vim:set filetype=markdown.pandoc : -->
