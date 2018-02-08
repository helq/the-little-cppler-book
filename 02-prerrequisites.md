# Prerequisites #

## Tools ##

To follow this book you will need two tools:

- A text editor
- A compiler

or, alternatively, you could install a tool that integrates those two tools into one, and
IDE.

Examples of IDE's are: Code::Blocks (Dev-C++) (for windows and linux), Visual Studio (for
windows), NetBeans or Eclipse (for windows, linux and macOS), Xcode (for macOS).

The rest of this guide will suppose you are using Code::Blocks.

### Installing Code::Blocks Dev-C++ ###

Go to <http://www.codeblocks.org/>, clic on Downloads, then clic on "Download the binary
release", and select the download that contains `mingw` and `setup` in the name.

Once you have download it, install it like any other windows program.

## Using the tools ##

I'm gonna assume that you have installed CodeBlocks Dev-C++ in your Windows computer. The
procedure shown here is similar in another Operating Systems like Linux or iOS.

\inlinetodo{Add how to edit using a plain text editor and compile without an interface:
The first thing you need to do is to is open a plain text editor, for example, `notepad`.}

Open Code::Blocks and clic on the menu "File", then "New", and finally "Empty file". A
space to write text should appear in the middle of the window with the name "Untitled1".

Write in the text space the following:

~~~cpp
#include <iostream>

int main()
{
  std::cout << "Hello World!" << std::endl;
  return 0;
}
~~~

Once you have entered the text without any typos save it in a new folder with the name
`helloworld.cc`. Note: you could get stuck if there is some typo on the text, please
revise you don't have any typos.

Now clic on the menu "Build" and then the option "Build". If you go now to the folder
where you saved `helloworld.cc`, you will find a file called `helloworld.exe`[^noexe]

[^noexe]: You may not see a file with that name, you may see a file without the extension
  `.exe`, only `helloworld`. That's ok, windows by default hides extensions. `.exe` is the
  extension that tells windows when a file is an executable, a program. If you want to see
  the extension of files under windows, search on the internet "displaying file extensions
  in windows".

If you double clic the created file, you should see a window appear and dissapear in a
fraction of a second. To actually see what that window was, go back to Code::Blocks and
clic in the menu "Build" and then the option "Run".

Now, you should see a black window open. In it, you will see the line:

```plain
Hello World!
```

followed by some lines telling you how long did the program take to run.

Congratulations! You have compiled and executed your first program!

<!--
   -TODO: ask to compile using the command line
   -
   -Now, you need to find the place where the C++ compiler was installed in your computer. For
   -example if you installed CodeBlocks Dev-C++ in your windows computer, the location of the
   -compiler should be in \todo{add location}.
   -
   -Next, you need to learn to use the console.
   -
   -Given the file `000-hello-world.cc`:
   -
   -
   -compile the file into a executable with either `clang++` or `g++`:
   -
   -\inlinetodo{add std option to make it C++11 compilant}
   -
   -~~~bash
   -clang++ 000-hello-world.cc -o 000-hello-world.exe
   -g++ 000-hello-world.cc -o 000-hello-world.exe
   -~~~
   -
   -and run it with:
   -
   -~~~bash
   -./000-hello-world.exe
   -~~~
   -->

Now that everything is working, why don't you try fiddling with the file, change the
message, or add more, repeat some lines, or something. Have fun.

<!-- vim:set filetype=markdown.pandoc : -->
