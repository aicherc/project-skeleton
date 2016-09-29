from setuptools import setup, Extension
#from distutils.core import setup
from Cython.Build import cythonize
import eigency

extensions = [
        Extension(name = "rect.rect", # Need the . to put *.so in right location
            sources = ["rect/rect.pyx"],
            include_dirs = [".", "cython/src"]
            ),
        Extension(name = "eigen_example.eigen_example",
            sources = ["eigen_example/eigen_example.pyx"],
            include_dirs = [".", "cython/src"] + eigency.get_includes()
            ),
        ]

config = {
    'name': 'ProjectSkeleton',  # Replace with project name
    'version': '0.0',  # Replace with module_name.__version__
    'url': '',  # Replace with url to github
    'description': 'This is a template',  # Replace with project description
    'author': 'Christopher Aicher',
    'license': 'license',
    'packages': ['rect', 'eigen_example'],  # Replace with package names
    'ext_modules': cythonize(extensions), # Cythonized Packages
    'scripts': [], # Scripts with #!/usr/bin/env python
}

setup(**config)
# Develop: python setup.py develop
# Remove: python setup.py develop --uninstall
