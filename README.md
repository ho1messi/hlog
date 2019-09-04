# hlog

simple, header-only C++ logging library 

## WARNING: hlog only support linux yet.

## Install

add `include/` folder to your project

## Usage

``` c++
#include "hlog.h"

int main(int argc, char ** argv) {
    // init with console output
    // every time call init() hlog will add an console appender
    // which means output one more time
    // if only want to log to files
    // can use hlog::init("output.txt")
    hlog::init(); 

    // add an file appender to also log to file
    // if want to output on console once more
    // can use hlog::addConsole()
    hlog::addFile("output.txt");
    // .csv file will use another format
    hlog::addFile("output.csv");
    
    HLOGI << "Hello world!"; // Info
    HLOGD << "Hello world!"; // Debug
    HLOGE << "Hello world!"; // Error

    return 0;
}
```

console output:
```
2019-09-04 13:24:08.021  INFO [1817566976] [main@8] Hello world!
2019-09-04 13:24:08.021 DEBUG [1817566976] [main@9] Hello world!
2019-09-04 13:24:08.021 ERROR [1817566976] [main@10] Hello world!
```

output.txt:
```
2019-09-04 13:24:08.021  INFO [1817566976] [main@8] Hello world!
2019-09-04 13:24:08.021 DEBUG [1817566976] [main@9] Hello world!
2019-09-04 13:24:08.021 ERROR [1817566976] [main@10] Hello world!
```

output.csv:
```
2019/09/04;13:24:08.021;INFO;1817566976;main@8;Hello world!
2019/09/04;13:24:08.021;DEBUG;1817566976;main@9;Hello world!
2019/09/04;13:24:08.021;ERROR;1817566976;main@10;Hello world!
```

## TODO
- multi-thread safty
- rolling file output
- cross-platform