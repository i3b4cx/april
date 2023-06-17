# april
**quickstart guide**
```*->start here*```

-[intro]()
-[setup]()
-[rendering]()
-[ecs]()
-[network]()
-[audio]()
-[parsing]()
-[testing]()

-[building from source]()
-[toolchains]()
-[installing april libraries]()
-[linking against april in other projects]()

## grabing the codebase and its submodules
```bash
git clone git@github.com:i3b4cx/april.git ~/
cd april
git submodules update --init --recursive
```

## release build; no test suite
```bash
mkdir build && cd build
../scripts/configure-local-release
make -j8
```

## debug build; w/ tests and samples
```bash
mkdir build && cd build
../scripts/configure-local-debug
make -j8
```

## installing april libraries
```bash
*tbd*
```

## building with april
```bash
*tbd*
```
