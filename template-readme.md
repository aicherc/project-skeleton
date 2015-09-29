## Instructions for using the python project template
By Christopher Aicher

## References 

* http://www.jeffknupp.com/blog/2013/08/16/open-sourcing-a-python-project-the-right-way/
* http://learnpythonthehardway.org/book/ex46.html

## Setup

* (_Optional, but recommended_) create a virtual environment for the project 
using ```virtualenv``` 
See http://docs.python-guide.org/en/latest/dev/virtualenvs/
Or using  ```conda```
```
conda create -n my_envname python
```
To activate/deactivate the virtual enivorment:
```
source activate my_envname
source deactivate
```
After activating the enivroment use ```conda install``` to install modules such as ```setuptools```.

* Run tests via ```nosetests```

* To add our package to path:
```
python setup.py develop
```
This lets us interactively change and update our package. 

* To remove module from path:
```
python setup.py develop --uninstall
```
Remove when we're done with it.



