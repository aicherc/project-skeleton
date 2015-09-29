try:
    from setuptools import setup
except ImportError:
    from distutils.core import setup

config = {
    'name': 'TEMPLATE',  # Replace with project name
    'version': '0.0',  # Replace with module_name.__version__
    'url': '',  # Replace with url to github
    'description': 'This is a template',  # Replace with project description
    'author': 'Christopher Aicher',
    'license': 'license',
    'packages': ['module_name'],  # Replace with package names
    'scripts': [], # Scripts with #!/usr/bin/env python

}

setup(**config)
# Develop: python setup.py develop
# Remove: python setup.py develop --uninstall
