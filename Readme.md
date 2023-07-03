## Introduction

This is a sample C project uses make build system.

## Prerequisites
- Coverity analysis version 2022.3.0
- Modify Coverity installation path [coverity.conf](https://github.com/inbharajmani/sample_make_c_coverity/blob/8c1ae26e5ad9f5ea2d9481b48a04cd6ac3cba61e/coverity.conf#L36)

## Native Build
```
make all
```

If the build is successful, make prints the output similar to
```
gcc -c -g -Wall ./src/main.c -I./inc/
mv main.o ./obj/
gcc -c -g -Wall ./src/function.c -I./inc/
mv function.o ./obj/
gcc -ofinal ./obj/main.o ./obj/function.o
mv final ./bin/
```
## Clean

```
make clean
```
## Coverity cmd line build steps

- Cov-configure

```
cov-configure --config coverity/coverity_config.xml --gcc 
```

- Cov-build

```
cov-build --emit-complementary-info --config coverity/coverity_config.xml --dir coverity make all
```
- Cov-analyze

```
cov-analyze --dir coverity/ --all --verbose 2
```

- Cov-commit

```
cov-commit-defects --dir coverity/ --stream local_coverity --url **url** --user **username** --password **password**
```

## Violation

- If Coverity succeds it will capture the deadcode present [at this line](https://github.com/inbharajmani/sample_make_c_coverity/blob/8c1ae26e5ad9f5ea2d9481b48a04cd6ac3cba61e/src/main.c#L39)