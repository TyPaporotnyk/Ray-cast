# Ray-cast

[![MIT License](https://img.shields.io/badge/license-MIT-blue.svg?style=flat)](http://choosealicense.com/licenses/mit/)
![Commits](https://img.shields.io/github/last-commit/TyPaporotnyk/Ray-cast)
![Version](https://img.shields.io/badge/C++-Solutions-blue.svg?style=flat&logo=c%2B%2B)

## Simple ray cast visualization 

<p>
    <img src="docs/visualization.gif" width="50%"/>
</p>

<b> Thanks <a href="https://github.com/Kofybrek">Kofybrek</a> for the textures </b>

# Requirements
* C++ 17
* CMake 3.20
* SFML 2.5

# Building & Running
```
cmake -B cmake-build-debug -DCMAKE_BUILD_TYPE=Debug
cmake --build cmake-build-debug
cmake --build cmake-build-debug --target debug
```

# Control
| Action               | Control         |
| ---------------------|-----------------|
| Move                 | wasd keys       |
| Rotation             | mouse movement  |
| Exit                 | esc             |



