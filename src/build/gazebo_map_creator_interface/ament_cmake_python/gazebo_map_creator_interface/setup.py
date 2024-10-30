from setuptools import find_packages
from setuptools import setup

setup(
    name='gazebo_map_creator_interface',
    version='3.5.3',
    packages=find_packages(
        include=('gazebo_map_creator_interface', 'gazebo_map_creator_interface.*')),
)
