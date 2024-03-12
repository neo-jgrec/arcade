/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** DLLoader
*/

#include "DLLoader.hpp"

#include <stdexcept>
#include <dlfcn.h>

template <typename T>
DLLoader<T>::~DLLoader()
{
    if (handle)
        dlclose(handle);
}

template <typename T>
T *DLLoader<T>::getInstance(const std::string &path, const std::string &entryPoint)
{
    this->handle = dlopen(path.c_str(), RTLD_LAZY);
    if (!this->handle) {
        throw std::runtime_error("Cannot open library: " + std::string(dlerror()));
    }
    T *(*create)() = (T *(*)())dlsym(this->handle, entryPoint.c_str());
    if (!create) {
        throw std::runtime_error("Cannot load symbol create: " + std::string(dlerror()));
    }
    T *instance = create();
    return instance;
}

template <typename T>
void DLLoader<T>::destroyInstance(T *instance)
{
    delete instance;
}
