/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** DLLoader
*/

#ifndef DLLOADER_HPP_
#define DLLOADER_HPP_

#include <string>
#include <stdexcept>
#include <dlfcn.h>


    template <typename T>
    class DLLoader {
        public:
            /**
             * @brief Construct a new DLLoader object
             *
             */
            DLLoader() = default;

            /**
             * @brief Destroy the DLLoader object
             *
             */
            ~DLLoader() {
                if (_handle)
                    dlclose(_handle);
            }

            /**
             * @brief Get the Instance object
             *
             * Use this function to get an instance of the class
             * Throw a runtime_error if the library cannot be opened or if the symbol cannot be loaded
             *
             * @param path path to the library
             * @param entryPoint name of the function to load
             * @return T*
             */
            T *getInstance(const std::string &path, const std::string &entryPoint = "entryPoint")
            {
                _handle = dlopen(path.c_str(), RTLD_LAZY);
                if (!_handle) {
                    throw std::runtime_error("Cannot open library: " + std::string(dlerror()));
                }
                void *(*create)() = (void *(*)())dlsym(_handle, entryPoint.c_str());
                if (!create) {
                    throw std::runtime_error("Cannot load symbol: " + std::string(dlerror()));
                }
                T *instance = static_cast<T *>(create());

                return instance;
                // return nullptr;
            }

            /**
             * @brief Destroy the Instance object
             *
             * @param instance
             */
            void destroyInstance(T *instance)
            {
                if (instance) {
                    delete instance;
                }
            }

        private:
            void *_handle = nullptr;
    };


#endif /* !DLLOADER_HPP_ */
