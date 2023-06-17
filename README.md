# april #

**quickstart guide for my custom work in progress gl2 game engine**

***->[start here]()***
***april documentation*** | ***building, installing, linking***
--------------------------|-------------------------------
***[intro]()***           | ***[building from source]()***
***[setup]()***           | ***[toolchains]()***
***[rendering]()***       | ***[installing april libraries]()***
***[ecs]()***             | ***[linking against april in other projects]()***
***[network]()***         |
***[audio]()***           |
***[parsing]()***         |
***[testing]()***         |


## intro ##

## setup ##

## rendering ##

## ecs ##

## network ##

## audio ##

## parsing ##

## testing ##

## building from source ##
### grabbing the codebase and its submodules ###
```bash
git clone git@github.com:i3b4cx/april.git ~/
cd april
git submodules update --init --recursive
```
### release build; no test suite ###
```bash
mkdir build && cd build
../scripts/configure-local-release
make -j8
```
### debug build; w/ tests and samples ###
```bash
mkdir build && cd build
../scripts/configure-local-debug
make -j8
```

## toolchains ##
simply configure new toolchains with cmake; a mingw-w64 toolchain has already been configured for linux developers interested in building windows applications.

## installing april libraries ##
### installing april libraries ###
```bash
*tbd*
```

## linking against april in other projects ##
### building with april ###
```bash
*tbd*
```
