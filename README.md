# tuto_tests
tuto and ex for unit test

## Prerequisites

### Having CMOCKA installed
see install procédure on https://github.com/clibs/cmocka/blob/master/INSTALL.md  
But also, you can adapt the folowing command, please, replace `<INSTALL_DIR>`  with the dir where you have installed cmocka.  
Depending the system, you may use `install/lib64` instead of `install/lib`
```shell
wget https://cmocka.org/files/1.1/cmocka-1.1.5.tar.xz
tar xf cmocka-1.1.5.tar.xz
cd cmocka-1.1.5
mkdir build
mkdir install
cd ./build
cmake -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>/install -DCMAKE_BUILD_TYPE=Debug ..
make
make install
```
## Set up env 
just need to update LD_LIBRARY_PATH:
```shell
export LD_LIBRARY_PATH=<INSTALL_DIR>/install/lib
```

## Other links
- CMOCKA main page : https://cmocka.org/
- Tuto : https://lwn.net/Articles/558106/



## Run the example
```shell
> make
gcc -c -Iinc -I../../cmocka-1.1.5/install/include -L../../cmocka-1.1.5/install/lib64 -lcmocka src/test_file1.c -o src/test_file1.o
gcc -c -Iinc -I../../cmocka-1.1.5/install/include -L../../cmocka-1.1.5/install/lib64 -lcmocka src/file1.c -o src/file1.o
gcc src/test_file1.o src/file1.o -o test1 -L../../cmocka-1.1.5/install/lib64 -lcmocka
./test1
[==========] Running 3 test(s).
[ RUN      ] test_f1__1
[       OK ] test_f1__1
[ RUN      ] test_f2__1
[       OK ] test_f2__1
[ RUN      ] test_f2__1
[       OK ] test_f2__1
[==========] 3 test(s) run.
[  PASSED  ] 3 test(s).
```

## what is happening ?

### testing f1
`f1` function is tested by `test_f1__1()` test function very simply with `assert_int_equal` cmocka primitive.

### testing f2
`f2` function is tested by `test_f2__1()` and `test_f2__1()` tests functions and with a mock of `fa`.

## to continue
Are the test complete enought ?  
Complete the tests with
- testing arguments of the called functions
  - for that, good ex in https://blog.microjoe.org/2017/unit-tests-c-cmocka-coverage-cmake.html#id14 using `expect_string` and `check_expected`.  
    See API documentation : https://api.cmocka.org/group__cmocka__param.html. Use to check values passes to parameters during call of `fa()` with primitives `check_expected`, `expect_value` and `expect_in_range_count`.
- a more complete criteria
  - functional coverage
  - statement coverage
  - decision coverage
  - MCDC coverage (just know that can exist, check https://fr.wikipedia.org/wiki/MC/DC)



