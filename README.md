# hlog

simple, headers only logging library 

## Install

add `include/` folder to your project

## Usage

``` c++
#include "hlog.h"

int main(int argc, char ** argv) {
    hlog::init();
    hlog::addFile("output.txt");
    hlog::addFile("output.csv");
    
    HLOGI << "Hello world!";
    HLOGD << "Hello world!";
    HLOGE << "Hello world!";

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