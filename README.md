# Vat7 Timing

Copyright (c) 2026 BrainInAVat7
Licnese: AGPL-3.0

A thin compile-time abstraction over POSIX and WINDOWS precision
timing functions.


**Current Release Version**

1.0.0-rc




---

## Vat7 Project

Vat7 is a collection of related programs I developed for learning and
personal use and have decided to share publicly and further develop.

I spent the better part of a year writing a toy game engine to get better
at C. As the project developed, I realized that many of the tools and
platform abstractions were really independent projects. I decided to
reorganize the project and share some of the more useful stand-alone
pieces. This largely serves to give me some motivation to document and
organize the code well, and to keep me honest about managing coupling and
organization between pieces. But, if the shared code is useful to someone
else for learning or their own projects, that's great.

This new, public iteration of the project starts with copying the pieces
of the old project I want to share into new repos. This unfortunately means
a lot of the development history is locked in the old private repo (which
still includes a lot I don't intend to share). But, I plan on reworking or
rewriting a lot of the pieces in light of what I learned so far.

The new standalone pieces (which will take some time to separate and edit
so that they stand alone) are:

- Vat7_Timing
- Vat7_Logger
- Vat7_Profiler
- Vat7_AutoTest
- Vat7_WindowIO
- Vat7_Audio
- Vat7_Renderer
- Vat7_LibC


As of now (October 2026) these pieces are in various stages of development,
ranging from perfectly functional (if simple) to nothing more than
placeholder test code.

Please see documentation for individual components to see their current
stage of development.

Other related projects are in the works but will remain private for now.




---

## Dependencies

No dependencies beyond the OS environment itself.

The POSIX version should work on any POSIX environment including but not
limited to:

- LINUX
- MAC
- BSD
- HAIKU


Obviously, the WINDOWS version works on WINDOWS.




---

## Installation

Simply download the zipped source code or clone the repository using

*git clone https://<no link>github.com/BrainInAVat7/Vat7_Timing*

Make sure *vat7_timing.h* is in your include path and that the clearly
name source file for your OS environment is listed in your compile
command or build system source list.




---

## API

### Functions


**vat7_timing_count**

*arguments*: void

*return*: uint64_t

*header*: vat7_timing.h

*description*:

> Returns an precision timing count value from the operating system.
>
> The count should not be interpreted in isolation and differs by platform;
> however, it is guaranteed to be monotonic. In conjunction with the value
> returned by *vat7_timing_frequency* the count difference can be used to
> calculate real elapsed time in seconds to a precision of fractions of a
> microsecond.




**vat7_timing_frequency**

*arguments*: void

*return*: uint64_t

*header*: vat7_timing.h

*description*:

> Returns the count value per second of the operating system counter queried
> by *vat7_timing_count*.




---

## Usage Examples

There are two primary usage patterns, though others are certainly possible.

**Pattern 1: **

```C
#include "vat7_timing.h"
#include <stdint.h>


uint64_t freq = vat7_timing_frequency();
uint64_t start_count = vat7_timing_count();

// do stuff that takes some time

uint64_t end_count = vat7_timing_count();
double seconds = (double)(end_count - start_count) / (double)freq;

// do something with seconds
```


**Pattern 2**

```C
#include "vat7_timing.h"
#include <stdint.h>


uint64_t freq = vat7_timing_frequency();
uint64_t next_tick_count = vat7_timing_count() + freq;
uint64_t seconds = 0;
uint64_t seconds_to_run = 10;

while (seconds <= seconds_to_run)
{
    now = vat7_timing_count();
    if (now >= next_tick_count)
    {
        // tick
        seconds ++;
        next_tick_count += freq;
    }
}
```




---

## Development Status and Plans

**For Next Release**

Vat Timing is in a perfectly functional state. After some testing to ensure
the recent edits (naming changes mostly) did not break anything across
different target systems, version 1.0.0 will be released.


**Future Plans**

-*Test Stubs*: I plan to add a test stub version of the program where the
main timing API functions return values that can be manually set by the user
as a means of testing the usage program's behavior under different timing
scenarios.

-*Support More Environments*: Between WINDOWS and POSIX, all major modern
desktop environments are supported, but these are not the others exist, and
it would be good to add support for more.




---

## Note on AI use

No code in this or any Vat7 project is AI-generated. This is a hobby project
with learning and the satisfaction of creating something myself as the
primary goals. Auto-generating code is antithetical to these goals.

I have used various LLM's as a resource for searching and explaining
documentation, identifying bugs/typos, and general information gathering.
In short, I use it as a faster and more amiable version of *Stack Exchange*.
