## Getting Started

### Setup
Create a virtual environment for the project using `conda`
```
conda create --name <env-name> python
```
Then call `conda install <package name>` to install modules.

Alternatively, construct the environment using the `environment.yml` file
```
$ conda create --name <env-name> --file <env-file>
```

To activate/deactivate the virtual environment:
```
$ source activate <env-name>
$ source deactivate
```

See [conda docs](http://conda.pydata.org/docs/using/envs.html) for more details.

### Developing the Python Library
To build the python modules for this project, we use `setup.py` (and it is always recommended to do this in a virtual environment):
```
$ python setup.py develop   # temporarily install the package (and allow quick updating)
```
or
```
$ python setup.py install   # install the package for long-term use (unrecommended)
```

To remove the python modules from the path, we call
```
$ python setup.py develop --uninstall
```
when in develop mode.


### Testing Python Library
Use Python's `unittest` module to write unit tests.
Write tests in the `/test` directory.
See `/test/rect_test.py` for more details.

Run tests via `nosetests` from the terminal.

### Profiling Python Library
From within IPython, define a funcion `to_profile()` with the code of interest.
Then consider running the magic `%prun` after importing the `cProfile` module
```
import cProfile
%prun -D output_dump_location to_profile()
```

For visualization of `cProfile` output, use `kcachegrind` and `pyprof2calltree` from the terminal
```
$ pyprof2calltree -i output_dump_location -k
```

For line-by-line profiling and memory profiling, use the following two extensions to IPython
```
load_ext line_profiler
load_ext memory_profiler
```
Then use the magic functions `%lprun` and `%mprun` on `to_profile()` within IPython.

See http://scikit-learn.org/stable/developers/performance.html for more details.

### Using Cythonize to build python library from cpp files
To build the cython extensions for this project, we use `setup.py` and call
```
terminal$: python setup.py build_ext --inplace            # build cpp extension
```

Then from Python we can call
```
>>>import rect

>>>new_rectangle = rect.PyRectangle()
>>>new_rectangle.x0
0
>>>new_rectangle.getLength()
0
>>>new_rectangle.x1 = 5
>>>new_rectangle.getLength()
5
```

Most of the work is done in `rect.pyx` a cython wrapper file.
To link a C++ library to python using cython, a wrapper `.pyx` file is necessary.
The Cython wrapper is very similar to python, except objects can be statically typed using the `cdef` command (as oppose to python's dynamically duck-typed at runtime).

See [cython userguide](http://docs.cython.org/src/userguide/wrapping_CPlusPlus.html) for more details.


### Building CPP
The C++ code is stored in the `cython` folder.
The header and source files are in `cython/src`.
The unit tests are in `cython/test`.

To build (stand-alone) C++ files/executables, we use `CMake`.
Recall `CMake` is a structured language that helps organize and generate `Makefiles`.
Then by calling `make`, the `Makefiles` compile the code.

Because `CMake` generates a lot of junk, the workflow is to build the project in a `build` directory
```
$ cd [...]/cython
$ mkdir build
$ cd build
$ cmake ..  # Setups up the Makefiles in the `build` directory
$ make      # Compiles the code in the `build` directory
```
To clean up the project, just remove the build folder.

Adding new C++ sources, headers, and tests, requires modifying the appropriate `CMakeLists.txt` files.

### Calling CPP Unit tests
The unit tests are written using the CXX_TEST framework and are added to the `CMakeLists` using `FindCxxTest`.
To run the tests, build the project and call `make test` or use the command `ctest` (both from the build folder).
I prefer to call `ctest --verbose` from the `build` folder.

Don't forget you can run tests individually via the cxx_test executables (compiled in the `build\test` folder).


### Useful References
* http://jeffknupp.com/blog/2013/08/16/open-sourcing-a-python-project-the-right-way/
