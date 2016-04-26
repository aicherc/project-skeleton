from setuptools import setup
#from distutils.core import setup
from Cython.Build import cythonize

#setup(ext_modules = cythonize("rect/rect.pyx"))

config = {
    'name': 'CythonRectangles',  # Replace with project name
    'version': '0.0',  # Replace with module_name.__version__
    'url': '',  # Replace with url to github
    'description': 'This is a template',  # Replace with project description
    'author': 'Christopher Aicher',
    'license': 'license',
    'packages': ['rect'],  # Replace with package names
    'ext_modules': cythonize("rect/rect.pyx"), # Cythonized Packages
    'scripts': [], # Scripts with #!/usr/bin/env python
}

setup(**config)
# Develop: python setup.py develop
# Remove: python setup.py develop --uninstall
