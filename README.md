# Builder Pattern: A pragmatic approach with modern C++

A pragmatic approach (i.e. simple and easy to understand) to the [Builder Pattern](https://refactoring.guru/design-patterns/builder)
using modern C++.

Three different ways to implement the Builder Pattern are presented:
* [basic-builder.cpp](basic-builder.cpp): A very basic implementation, so basic that some would argue it's not a Builder Pattern at all.
* [late-access-builder.cpp](late-access-builder.cpp): A more complete Builder that only provides access to the built object after
  the initialization is complete.
* [builder-with-interfaces.cpp](builder-with-interfaces.cpp): A "traditional" approach where the "builder" and the "initialized object"
  implement abstract interfaces.

## Youtube video

This material was created to accompany a YouTube tutorial. You can watch it here:

[![Youtube video](https://i3.ytimg.com/vi/Ag_7sAPv7fQ/maxresdefault.jpg)](https://youtu.be/Ag_7sAPv7fQ)
